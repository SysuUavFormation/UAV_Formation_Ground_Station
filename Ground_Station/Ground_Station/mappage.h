#ifndef MAPPAGE_H
#define MAPPAGE_H

#include <QWidget>
#include <QtWidgets>
#include <QMainWindow>
#include <QtWebKitWidgets/QWebView>
#include <QtWebKitWidgets/QWebFrame>
#include <QtWebKitWidgets/QWebPage>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QtCore>

#include "returnvlc.h"
#include "parameter.h"
#include "CVT/CVT.hpp"
#include <iostream>


#define CUBIC 0
#define TETRAHEDRON 1
#define TRIANGLE 2
#define SQUARE 3
#define CIRCLE 4

/*QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
QT_END_NAMESPACE*/
//extern Returnvlc *webFrameObj;

class MapPage : public QWidget
{
    Q_OBJECT
public:
    MapPage(QWidget *parent = 0);
    void closeEvent(QCloseEvent *event);

private:
    QGroupBox *controlGroup;
    QLabel *agentAccountLabel;
    QLineEdit *agentAccountEdit;
    QPushButton *takeoffButton;
    QLabel *takeoffAltitudeLabel;
    QLineEdit *takeoffAltitudeEdit;
    QLabel *takeoffAltitudeUnitLabel;
    QPushButton *landButton;
    QPushButton *urgencyStopButton;
    QLabel *formLabel;
    QComboBox *formCombo;
    QLabel *agentIDLabel;
    QComboBox *agentIDCombo;
    QPushButton *selectGoalButton;
    QPushButton *clearGoalButton;
    QPushButton *clearAllMarkersButton;
    QLabel *missionAltitudeLabel;
    QLineEdit *missionAltitudeEdit;
    QLabel *missionAltitudeUnitLabel;
    QPushButton *setGoalButton;
    QPushButton *startMissionButton;
    QPushButton *checkCommunicationButton;
    QDockWidget *dock;
    QWebView *mapWeb;
    QMenu *viewMenu;
    QMenuBar *menuBar;
    QLabel *status1Label;
    QLabel *status2Label;

    QPushButton *setCenterPointButton;
    QLabel *spaceLabel;
    QLineEdit *spaceEdit;
    QLabel *spaceUnitLabel;
    QComboBox *selectFormCombo;

    QTimer *drawPointTimer;

    Returnvlc *webFrameObj;

    std::vector<std::vector<double> > temp_formation; // 队形坐标

private slots:
    void addJavaScript();
    void setGoalPosition();
    void sendData2Web(QString x, QString y, QString num);
    void drawPointTimerUpdate();
    void on_takeoffButton_clicked();
    void on_landButton_clicked();
    void on_urgencyStopButton_clicked();
    void on_setCenterPointButton_clicked();
    void on_clearAllMarkers_clicked();
    void on_clearGoalButton_clicked();
    void on_selectGoalButton_clicked();
    void on_startMissionButton_clicked();
    void on_checkCommunicationButton_clicked();
    void receiveDataFromWeb();
    void updateFocusValue();
    void enableForm();
};

#endif // MAPPAGE_H
