#include "websockethandler.h"
#include <QDebug>


WebSocketHandler::WebSocketHandler(QObject *parent) : QObject(parent)
{
    m_socketServer = new QWebSocketServer("SocketServer",QWebSocketServer::NonSecureMode,this);
    connect(m_socketServer,&QWebSocketServer::newConnection,this,&WebSocketHandler::onNewSocketConnection);
    if(m_socketServer->listen(QHostAddress::Any,8585)){
        qDebug() << "Server is running";

    }else{
        qDebug() << "Server unable to start listening!";
    }

}

WebSocketHandler::~WebSocketHandler()
{
    m_socketServer->deleteLater();
}

void WebSocketHandler::onNewSocketConnection()
{
    qDebug() << "New Client Connected!" ;
    auto newClient = m_socketServer->nextPendingConnection();
    newClient->setParent(this);
    connect(newClient,&QWebSocket::textMessageReceived,this,&WebSocketHandler::onTextMessageReceived);
    connect(newClient,&QWebSocket::disconnected,this,&WebSocketHandler::onSocketDisconnected);
    m_clientList.append(newClient);


}

void WebSocketHandler::onTextMessageReceived(QString message)
{
    qDebug()<< "Received message: " << message;
}

void WebSocketHandler::onSocketDisconnected()
{
    auto client = qobject_cast<QWebSocket *> (sender());
    if(client){
        m_clientList.removeAll(client);
    }

}
