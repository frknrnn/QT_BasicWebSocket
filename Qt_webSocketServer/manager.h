#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include "websockethandler.h"

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);
    ~Manager();

signals:

private:
    WebSocketHandler * m_socketHandler;

};

#endif // MANAGER_H
