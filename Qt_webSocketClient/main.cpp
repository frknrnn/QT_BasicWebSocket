#include <QCoreApplication>
#include "controller/websockethandler.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    WebSocketHandler socketHandler;

    socketHandler.connectToServer("");

    return a.exec();
}
