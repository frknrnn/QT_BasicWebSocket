#include <QCoreApplication>
#include "controller/websockethandler.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    WebSocketHandler socketHandler;

    socketHandler.connectToServer("ws://127.0.0.1:8585");

    return a.exec();
}
