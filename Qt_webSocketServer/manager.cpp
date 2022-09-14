#include "manager.h"

Manager::Manager(QObject *parent) : QObject(parent)
{
    m_socketHandler = new WebSocketHandler(this);



}

Manager::~Manager(){
    m_socketHandler->deleteLater();
}
