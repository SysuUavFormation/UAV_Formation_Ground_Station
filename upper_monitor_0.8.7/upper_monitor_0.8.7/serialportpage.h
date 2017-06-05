#ifndef SERIALPORTPAGE_H
#define SERIALPORTPAGE_H

#include <QWidget>
#include <QtWidgets>
#include "win_qextserialport.h"
#include "uav_link.h"

class SerialportPage : public QWidget
{
    Q_OBJECT
public:
    SerialportPage(QWidget *parent = 0);

private:
    UAV_link *uav_link;
    Win_QextSerialPort *myCom;
    QGroupBox *configGroup;
    QLabel *comNumLabel;
    QComboBox *comNumCombo;
    QLabel *baudRateLabel;
    QComboBox *baudRateCombo;
    QLabel *checkBitLabel;
    QComboBox *checkBitCombo;
    QLabel *dataBitLabel;
    QComboBox *dataBitCombo;
    QLabel *stopBitLabel;
    QComboBox *stopBitCombo;
    QPushButton *openButton;
    QPushButton *refreshComButton;
    QGroupBox *recDataGroup;
    QTextEdit *recDataText;
    QPushButton *clearRecDataButton;
    QPushButton *stopRecButton;
    QLabel *hexDispLabel;
    QCheckBox *hexDispCheck;
    QGroupBox *sendDataGroup;
    QTextEdit *sendDataText;
    QPushButton *clearSendDataButton;
    QPushButton *startSendButton;
    QLabel *hexSendLabel;
    QCheckBox *hexSendCheck;
    bool comStatus;
    QTimer *timerForTask;

private slots:
    void on_openButton_clicked();
    void on_sendData_clicked();
    void on_clearRecData_clicked();
    void on_clearSendData_clicked();
    void on_refreshCom_clicked();
    void recData();
    void my_task();
};

#endif // SERIALPORTPAGE_H
