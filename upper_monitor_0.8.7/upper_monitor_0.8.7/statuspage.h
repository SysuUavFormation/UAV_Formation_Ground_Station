#ifndef STATUSPAGE_H
#define STATUSPAGE_H


#include <QWidget>
#include <QTableWidget>
#include <QtCore>
#include "parameter.h"

#define AGENTID                0
#define LINKSTATUS             1
#define CURRENTPOSITION_LNG    2
#define CURRENTPOSITION_LAT    3
#define CURRENTPOSITION_ALT    4
#define CURRENTVELOCITY_E      5
#define CURRENTVELOCITY_N      6
#define CURRENTVELOCITY_D      7
#define GOALPOSITION_LNG       8
#define GOALPOSITION_LAT       9
#define GOALPOSITION_ALT       10
#define TEMPGOALPOSITION_LNG   11
#define TEMPGOALPOSITION_LAT   12
#define TEMPGOALPOSITION_ALT   13



class StatusPage : public QWidget
{
    Q_OBJECT

private:
    QTableWidget *statusTable;
    QTimer *refreshStatusTimer;
    QFile *log;
    QTextStream *outfile;

public:
    StatusPage();
    ~StatusPage();
    bool isArrived(int id);

private slots:
    void refreshCurrentPosition();
    void refreshCurrentVelocity();
    void refreshGoalPosition();
    void refreshTempGoalPosition();
    void refreshLinkStatus();
    void refreshStatus();
};
#endif // STATUSPAGE_H
