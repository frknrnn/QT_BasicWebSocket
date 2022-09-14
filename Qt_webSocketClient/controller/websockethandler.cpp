#include "websockethandler.h"
#include <QDebug>



WebSocketHandler::WebSocketHandler(QObject *parent) : QObject(parent)
{
    m_webSocket = new QWebSocket;
    connect(m_webSocket,&QWebSocket::connected,this,&WebSocketHandler::onConnected);
    connect(m_webSocket,&QWebSocket::textMessageReceived,this,&WebSocketHandler::onTextMessageRecived);

}

WebSocketHandler::~WebSocketHandler(){

    m_webSocket->deleteLater();
}

void WebSocketHandler::connectToServer(QString hostAddress)
{
    qDebug() << "Client : connecting to server: " << hostAddress;
    m_webSocket->open(hostAddress);
}


void WebSocketHandler::onConnected()
{
    qDebug() << "Connection established!";
}

void WebSocketHandler::onTextMessageRecived(QString message)
{
    qDebug()<< "Client Recive Message:"<< message;

}
