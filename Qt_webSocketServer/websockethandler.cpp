#include "websockethandler.h"
#include <QDebug>
#include <random>


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

    std::random_device rd;
    std::default_random_engine generator;
    generator.seed(rd);

    std::uniform_int_distribution<int> idGenerator(1000,9999);
    QString newClientId = QString(idGenerator(generator));

    while(m_clientList.keys().contains(newClientId)){
        QString newClientId = QString(idGenerator(generator));
    }




    auto newClient = m_socketServer->nextPendingConnection();
    newClient->setParent(this);
    connect(newClient,&QWebSocket::textMessageReceived,this,&WebSocketHandler::onTextMessageReceived);
    connect(newClient,&QWebSocket::disconnected,this,&WebSocketHandler::onSocketDisconnected);
    m_clientList[newClientId] = newClient;


}

void WebSocketHandler::onTextMessageReceived(QString message)
{
    qDebug()<< "Received message: " << message;
}

void WebSocketHandler::onSocketDisconnected()
{
    auto client = qobject_cast<QWebSocket *> (sender());
    if(client){
       for(QMap<QString,QWebSocket *>::iterator mapIterator = m_clientList.begin();
           mapIterator != m_clientList.end();mapIterator++)
       {
           if(mapIterator.value()==client){
               QString uid = mapIterator.key();
               m_clientList.remove(uid);
               client->deleteLater();
           }
       }

    }

}
