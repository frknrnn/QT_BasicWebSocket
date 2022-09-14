#ifndef WEBSOCKETHANDLER_H
#define WEBSOCKETHANDLER_H

#include <QObject>
#include <QtWebSockets/QWebSocketServer>
#include <QtWebSockets/QWebSocket>
class WebSocketHandler : public QObject
{
    Q_OBJECT
public:
    explicit WebSocketHandler(QObject *parent = nullptr);
    ~WebSocketHandler();
signals:


public slots:
    void onNewSocketConnection();
    void onTextMessageReceived(QString);
    void onSocketDisconnected();

private:
    QWebSocketServer * m_socketServer;
    QList<QWebSocket *> m_clientList;
};

#endif // WEBSOCKETHANDLER_H
