#ifndef WEBSOCKETHANDLER_H
#define WEBSOCKETHANDLER_H

#include <QObject>
#include <QtWebSockets/QWebSocket>
class WebSocketHandler : public QObject
{
    Q_OBJECT
public:
    explicit WebSocketHandler(QObject *parent = nullptr);
    ~WebSocketHandler();
    void connectToServer(QString hostAddress);

public slots:

    void onConnected();
    void onTextMessageRecived(QString message);


signals:


private:
    QWebSocket * m_webSocket;

};

#endif // WEBSOCKETHANDLER_H
