#include "serialportpage.h"
#include <QDebug>
#include <QtSerialPort/QSerialPortInfo>

SerialportPage::SerialportPage(QWidget *parent)
    : QWidget(parent)
{
    configGroup = new QGroupBox(tr("串口配置"));

    comNumLabel = new QLabel(tr("串口号"));
    comNumCombo = new QComboBox;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
        comNumCombo->addItem(info.portName());

    QHBoxLayout *comNumLayout = new QHBoxLayout;
    comNumLayout->addWidget(comNumLabel);
    comNumLayout->addWidget(comNumCombo);

    baudRateLabel = new QLabel(tr("波特率"));
    baudRateCombo = new QComboBox;
    baudRateCombo->addItem(tr("115200"));
    baudRateCombo->addItem(tr("9600"));
    QHBoxLayout *baudRateLayout = new QHBoxLayout;
    baudRateLayout->addWidget(baudRateLabel);
    baudRateLayout->addWidget(baudRateCombo);

    checkBitLabel = new QLabel(tr("检验位"));
    checkBitCombo = new QComboBox;
    checkBitCombo->addItem(tr("无"));
    checkBitCombo->addItem(tr("奇"));
    checkBitCombo->addItem(tr("偶"));
    QHBoxLayout *checkBitLayout = new QHBoxLayout;
    checkBitLayout->addWidget(checkBitLabel);
    checkBitLayout->addWidget(checkBitCombo);

    dataBitLabel = new QLabel(tr("数据位"));
    dataBitCombo = new QComboBox;
    dataBitCombo->addItem(tr("7"));
    dataBitCombo->addItem(tr("8"));
    dataBitCombo->setCurrentIndex(1);
    QHBoxLayout *dataBitLayout = new QHBoxLayout;
    dataBitLayout->addWidget(dataBitLabel);
    dataBitLayout->addWidget(dataBitCombo);

    stopBitLabel = new QLabel(tr("停止位"));
    stopBitCombo = new QComboBox;
    stopBitCombo->addItem(tr("1"));
    stopBitCombo->addItem(tr("2"));
    QHBoxLayout *stopBitLayout = new QHBoxLayout;
    stopBitLayout->addWidget(stopBitLabel);
    stopBitLayout->addWidget(stopBitCombo);

    openButton = new QPushButton(tr("打开"));
    refreshComButton = new QPushButton(tr("刷新串口"));

    QVBoxLayout *configLayout = new QVBoxLayout;
    configLayout->addLayout(comNumLayout);
    configLayout->addLayout(baudRateLayout);
    configLayout->addLayout(checkBitLayout);
    configLayout->addLayout(dataBitLayout);
    configLayout->addLayout(stopBitLayout);
    configLayout->addWidget(openButton, 0, Qt::AlignHCenter);
    configLayout->addWidget(refreshComButton, 0, Qt::AlignHCenter);
    configLayout->addStretch();
    configGroup->setLayout(configLayout);

/********************************************************************/
    recDataGroup = new QGroupBox(tr("串口数据接收"));

    recDataText = new QTextEdit;
    recDataText->setFontPointSize(12);
    recDataText->setFontWeight(20);
    recDataText->setReadOnly(true);
    recDataText->setFrameStyle(QFrame::Box);
    recDataText->setFrameShadow(QFrame::Sunken);
    recDataText->setMidLineWidth(1);
    stopRecButton = new QPushButton(tr("停止接收"));
    clearRecDataButton = new QPushButton(tr("清除缓存区"));

    hexDispLabel = new QLabel(tr("十六进制显示"));
    hexDispCheck = new QCheckBox;
    hexDispCheck->setChecked(true);
    hexDispCheck->setEnabled(true);
    QHBoxLayout *hexDispLayout = new QHBoxLayout;
    hexDispLayout->addWidget(hexDispLabel, 0, Qt::AlignLeft);
    hexDispLayout->addWidget(hexDispCheck, 1, Qt::AlignLeft);

    QHBoxLayout *temp1Layout = new QHBoxLayout;
    temp1Layout->addLayout(hexDispLayout, Qt::AlignRight);
    temp1Layout->addWidget(clearRecDataButton, 0, Qt::AlignRight);
    temp1Layout->addWidget(stopRecButton, 0, Qt::AlignRight);

    QVBoxLayout *recDataLayout = new QVBoxLayout;
    recDataLayout->addWidget(recDataText);
    recDataLayout->addLayout(temp1Layout);
    recDataGroup->setLayout(recDataLayout);

/**********************************************************************/
    sendDataGroup = new QGroupBox(tr("串口数据发送"));

    sendDataText = new QTextEdit;
    sendDataText->setFontPointSize(12);
    sendDataText->setFontWeight(25);
    sendDataText->setFrameStyle(QFrame::Box);
    sendDataText->setFrameShadow(QFrame::Sunken);
    sendDataText->setMidLineWidth(1);
    startSendButton = new QPushButton(tr("开始发送"));
    clearSendDataButton = new QPushButton(tr("清除缓存区"));

    hexSendLabel = new QLabel(tr("十六进制发送"));
    hexSendCheck = new QCheckBox;
    hexSendCheck->setChecked(true);
    hexSendCheck->setEnabled(true);
    QHBoxLayout *hexSendLayout = new QHBoxLayout;
    hexSendLayout->addWidget(hexSendLabel, 0, Qt::AlignLeft);
    hexSendLayout->addWidget(hexSendCheck, 1, Qt::AlignLeft);

    QHBoxLayout *temp2Layout = new QHBoxLayout;
    temp2Layout->addLayout(hexSendLayout, Qt::AlignRight);
    temp2Layout->addWidget(clearSendDataButton, 0, Qt::AlignRight);
    temp2Layout->addWidget(startSendButton, 0, Qt::AlignRight);

    QVBoxLayout *sendDataLayout = new QVBoxLayout;
    sendDataLayout->addWidget(sendDataText);
    sendDataLayout->addLayout(temp2Layout);
    sendDataGroup->setLayout(sendDataLayout);

    QVBoxLayout *temp3Layout = new QVBoxLayout;
    temp3Layout->addWidget(recDataGroup);
    temp3Layout->addWidget(sendDataGroup);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(configGroup);
    mainLayout->addLayout(temp3Layout);

    setLayout(mainLayout);

    comStatus = false;
    connect(openButton, SIGNAL(clicked()), this, SLOT(on_openButton_clicked()));
    connect(startSendButton, SIGNAL(clicked()), this, SLOT(on_sendData_clicked()));
    connect(clearRecDataButton, SIGNAL(clicked()), this, SLOT(on_clearRecData_clicked()));
    connect(clearSendDataButton, SIGNAL(clicked()), this, SLOT(on_clearSendData_clicked()));
    connect(refreshComButton, SIGNAL(clicked()), this, SLOT(on_refreshCom_clicked()));
}

void SerialportPage::on_openButton_clicked()
{
    if(openButton->text() == tr("打开"))
    {
        QString portName = comNumCombo->currentText();//获取串口名称
        myCom = new Win_QextSerialPort(portName,QextSerialBase::EventDriven);
        comStatus = myCom->open(QIODevice::ReadWrite);

        //设置波特率
        if(baudRateCombo->currentText()==tr("9600"))
        {
            myCom->setBaudRate(BAUD9600);
        }
        else if(baudRateCombo->currentText()==tr("115200"))
        {
            myCom->setBaudRate(BAUD115200);
        }

        //设置数据位
        if(dataBitCombo->currentText()==tr("8"))
            myCom->setDataBits(DATA_8);
        else if(dataBitCombo->currentText()==tr("7"))
            myCom->setDataBits(DATA_7);

        //设置奇偶校验
        if(checkBitCombo->currentText()==tr("无"))
            myCom->setParity(PAR_NONE);
        else if(checkBitCombo->currentText()==tr("奇"))
            myCom->setParity(PAR_ODD);
        else if(checkBitCombo->currentText()==tr("偶"))
            myCom->setParity(PAR_EVEN);

        //设置停止位
        if(stopBitCombo->currentText()==tr("1"))
            myCom->setStopBits(STOP_1);
        else if(stopBitCombo->currentText()==tr("2"))
            myCom->setStopBits(STOP_2);

        myCom->setFlowControl(FLOW_OFF);
        myCom->setTimeout(500);

        if(comStatus == true)
        {
            //信号和槽函数关联，当串口缓冲区有数据时，进行读串口操作
            connect(myCom,SIGNAL(readyRead()),this,SLOT(recData()));

            openButton->setText(tr("关闭"));
            baudRateCombo->setEnabled(false);
            dataBitCombo->setEnabled(false);
            checkBitCombo->setEnabled(false);
            stopBitCombo->setEnabled(false);
            comNumCombo->setEnabled(false);
        }
        else
        {
            QString message = "串口打开失败";
            QMessageBox::information(this, tr("QMessageBox::information()"), message);
            return;
        }
        uav_link = new UAV_link(myCom);

        timerForTask = new QTimer;
        connect(timerForTask, SIGNAL(timeout()), this, SLOT(my_task()));
                timerForTask->start(80);//100ms


    }
    else
    {
        myCom->close();
        openButton->setText(tr("打开"));
        baudRateCombo->setEnabled(true);
        dataBitCombo->setEnabled(true);
        checkBitCombo->setEnabled(true);
        stopBitCombo->setEnabled(true);
        comNumCombo->setEnabled(true);
    }
}


void SerialportPage::my_task()
{
    uav_link->Data_Receive_Anl();
    if(((uav_status_flag == 5) && (check_communication == 1)))
    {
        uav_link->Uav_Send_Data(UAV_GROUND_ALL_ID, UAV_GROUND_GPS_VELOCITY);
        check_communication = 0;
    }
}

void SerialportPage::recData()
{
    int num = myCom->bytesAvailable();
    //读取串口缓冲区的所有数据给临时变量temp
    QByteArray temp = myCom->readAll();
//    QString temp2 = temp;
    //将串口数据显示在窗口的文本浏览器中

    char *Serial_read;
    Serial_read = temp.data();
 //   qDebug() << "receive" << temp;


    if(hexDispCheck->isChecked())
    {
        //16进制输出时，格式化输出
        QByteArray temp_hex = temp.toHex();
        QByteArray formate = temp_hex.toUpper();
        int length = formate.length()/2;
        for(int i=1; i<=length; i++)
        {
            formate.insert(i*3-1, " ");
        }
        //recDataText->insertPlainText(formate);
        QTextCursor cursor = recDataText->textCursor();
        cursor.movePosition(QTextCursor::End);
        recDataText->setTextCursor(cursor);

    }
    else
        recDataText->insertPlainText(temp);

    uav_link->updateDataBuff(num, Serial_read);
  //  QWebFrame *frame = ui->web->page()->mainFrame();
 //   QString cmd = QString("forQtText(\"%1\",\"%2\")").arg(temp2).arg("y");
 //   frame->evaluateJavaScript(cmd);
}

void SerialportPage::on_sendData_clicked()
{
    if(openButton->text() != tr("关闭"))
    {
        QString message = "请先打开串口";
        QMessageBox::information(this, tr("QMessageBox::information()"), message);
        return;
    }
    //要写入串口的数据
    QByteArray data2Send;

    QString s;
    s = sendDataText->toPlainText();
    if(s.length() == 0)
    {
        QString message = "请先输入发送内容";
        QMessageBox::information(this, tr("QMessageBox::information()"), message);
        return;
    }

    if(hexSendCheck->isChecked())
    {
        QString pattern("*[^a-fA-F0-9 \n]*");  //提高代码容错性，利用正则表达式限制输入的字符为十六进制字符
        QRegExp rx;
        rx.setPatternSyntax(QRegExp::Wildcard);
        rx.setPattern(pattern);
        bool match = rx.exactMatch(s);
        if(match == true)
        {
            QString message = "发送内容含有非法字符";
            QMessageBox::information(this, tr("QMessageBox::information()"), message);
            return;
        }

        s.replace(" ",""); //将用户输入的空格和过行过滤掉
        s.replace("\n", "");
        if(s.length()%2 != 0) //将字符串转换成16进制
        {
            s += " ";
        }
//        qDebug() << s.length();
        for (int i = 0; i < (s.length()/2); i++)
        {
            data2Send[i] = (s.mid(i*2, 2)).toInt(0, 16);
        }
//        qDebug() << "Send" << data2Send;
    }
    else
    {
        data2Send = s.toLocal8Bit();
    }
    myCom->write(data2Send);
}

void SerialportPage::on_clearRecData_clicked()
{
    recDataText->clear();
}

void SerialportPage::on_clearSendData_clicked()
{
    sendDataText->clear();
}

void SerialportPage::on_refreshCom_clicked()
{
    comNumCombo->clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
        comNumCombo->addItem(info.portName());
}
