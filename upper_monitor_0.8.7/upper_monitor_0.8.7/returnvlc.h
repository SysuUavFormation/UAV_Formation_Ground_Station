#ifndef RETURNVLC_H
#define RETURNVLC_H

#include <QObject>
#include <QMainWindow>

class Returnvlc:public QObject
{
    Q_OBJECT
public:
    explicit Returnvlc(QObject *parent = 0);
    QString getinfo1();
    QString getinfo2();
    QString getinfo3();

signals:
    void returnValue(void);

public slots:
    void openVLC(QString info1, QString info2, QString info3);

private:
    QString info1;
    QString info2;
    QString info3;
};



#endif // RETURNVLC_H
