#include "returnvlc.h"
#include <QDebug>

Returnvlc::Returnvlc(QObject *parent) :
    QObject(parent)
{
}

void Returnvlc::openVLC(QString info1, QString info2, QString info3)
{
    this->info1 = info1;
    this->info2 = info2;
    this->info3 = info3;
    emit returnValue();
}

QString Returnvlc::getinfo1()
{
    return info1;
}

QString Returnvlc::getinfo2()
{
    return info2;
}

QString Returnvlc::getinfo3()
{
    return info3;
}
