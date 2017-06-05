#include "mappage.h"

MapPage::MapPage(QWidget *parent)
    : QWidget(parent)
{
    menuBar = new QMenuBar(this);
    viewMenu = new QMenu(tr("&View"));
    menuBar->addMenu(viewMenu);
    menuBar->addSeparator();

    controlGroup = new QGroupBox(tr("编队控制"));

    agentAccountLabel = new QLabel(tr("飞行器数量"));
    agentAccountEdit = new QLineEdit;
    agentAccountEdit->setText(QString::number(AGENT_ACCOUNT-1, 10));
    agentAccountEdit->setReadOnly(true);
    agentAccountEdit->setFixedSize(40, 20);
    agentAccountEdit->setAlignment(Qt::AlignRight);
    agentAccountEdit->setToolTip(tr("飞行器编队数量，不可更改"));
    QHBoxLayout *agentAccountLayout = new QHBoxLayout;
    agentAccountLayout->addWidget(agentAccountLabel);
    agentAccountLayout->addWidget(agentAccountEdit);
    agentAccountLayout->addStretch();

    takeoffButton = new QPushButton(tr("起飞"));
    takeoffButton->setToolTip(tr("发送起飞命令"));
    takeoffAltitudeLabel = new QLabel(tr("起飞高度"));
    takeoffAltitudeEdit = new QLineEdit("8.0");
    takeoffAltitudeEdit->setFixedWidth(33);
    takeoffAltitudeEdit->setToolTip(tr("起飞后到达的高度，单位：米"));
    takeoffAltitudeUnitLabel = new QLabel("m");
    QHBoxLayout *takeoffLayout = new QHBoxLayout;
    takeoffLayout->addWidget(takeoffButton);
    takeoffLayout->addWidget(takeoffAltitudeLabel);
    takeoffLayout->addWidget(takeoffAltitudeEdit);
    takeoffLayout->addWidget(takeoffAltitudeUnitLabel);
    landButton = new QPushButton(tr("降落"));
    landButton->setToolTip(tr("发送降落命令"));
    urgencyStopButton = new QPushButton(tr("暂停"));
    urgencyStopButton->setToolTip(tr("发送暂停命令"));
    QGridLayout *commandLayout = new QGridLayout;
    commandLayout->addLayout(takeoffLayout, 0, 0);
    commandLayout->addWidget(landButton, 1, 0, Qt::AlignLeft);
    commandLayout->addWidget(urgencyStopButton, 2, 0, Qt::AlignLeft);

    formLabel = new QLabel(tr("编队算法"));
    formCombo = new QComboBox;
    formCombo->setToolTip(tr("选择设置目标点的方式"));
    formCombo->addItem(tr("手动选取目标点"));
    formCombo->addItem(tr("编队飞行"));
    formCombo->addItem(tr("选取队形"));
    QHBoxLayout *formLayout = new QHBoxLayout;
    formLayout->addWidget(formLabel);
    formLayout->addWidget(formCombo);
    formLayout->addStretch();

    agentIDLabel = new QLabel(tr("飞行器ID"));
    agentIDCombo = new QComboBox;
    for(int i=1; i<AGENT_ACCOUNT; i++)
    {
        agentIDCombo->addItem("飞行器 "+QString::number(i, 10));
    }
    agentIDCombo->addItem("所有飞行器");
    QHBoxLayout *agentIDLayout = new QHBoxLayout;
    agentIDLayout->addWidget(agentIDLabel);
    agentIDLayout->addWidget(agentIDCombo);
    agentIDLayout->addStretch();

    selectGoalButton = new QPushButton(tr("选取目标点"));
    selectGoalButton->setToolTip(tr("为飞行器分别选取目标点"));
    clearGoalButton = new QPushButton(tr("清除目标点"));
    clearGoalButton->setToolTip(tr("清除指定的目标点，如果没有重新设置，则保留上一次的目标点"));
    QHBoxLayout *setGoalLayout = new QHBoxLayout;
    setGoalLayout->addWidget(selectGoalButton);
    setGoalLayout->addWidget(clearGoalButton);
    setGoalLayout->addStretch();

    clearAllMarkersButton = new QPushButton(tr("清除标记"));
    clearAllMarkersButton->setToolTip(tr("清除地图上的所有标记"));
    clearAllMarkersButton->setFixedSize(75, 20);

    missionAltitudeLabel = new QLabel("目标高度");
    missionAltitudeEdit = new QLineEdit("8.0");
    missionAltitudeEdit->setToolTip(tr("设定队形的目标高度，单位：米"));
    missionAltitudeEdit->setFixedWidth(33);
    missionAltitudeUnitLabel = new QLabel("m");
    QHBoxLayout *missionAltitudeLayout = new QHBoxLayout;
    missionAltitudeLayout->addWidget(missionAltitudeLabel);
    missionAltitudeLayout->addWidget(missionAltitudeEdit);
    missionAltitudeLayout->addWidget(missionAltitudeUnitLabel);

    setGoalButton = new QPushButton(tr("设置目标"));
    setGoalButton->setToolTip(tr("设置目标点，将目标点发送到飞行器"));
    setGoalButton->setFixedSize(75,20);

    setCenterPointButton = new QPushButton(tr("设置中心点"));
    setCenterPointButton->setToolTip(tr("设置队形的中心点"));
    setCenterPointButton->setFixedSize(75, 20);
    setCenterPointButton->setDisabled(true);
    spaceLabel = new QLabel(tr("飞行器间隔"));
    spaceEdit = new QLineEdit(tr("4.0"));
    spaceEdit->setToolTip(tr("设置队形中飞行器的间隔，单位：米"));
    spaceEdit->setFixedWidth(33);
    spaceEdit->setDisabled(true);
    spaceUnitLabel = new QLabel(tr("m"));
    QHBoxLayout *spaceLayout = new QHBoxLayout;
    spaceLayout->addWidget(spaceLabel);
    spaceLayout->addWidget(spaceEdit);
    spaceLayout->addWidget(spaceUnitLabel);
    selectFormCombo = new QComboBox;
    selectFormCombo->setFixedSize(75, 20);
    selectFormCombo->setToolTip(tr("选择队形"));
    selectFormCombo->addItem(tr("三角形"));
    selectFormCombo->addItem(tr("正方形"));
    selectFormCombo->addItem(tr("圆形"));
    selectFormCombo->addItem(tr("一字形"));
    selectFormCombo->setDisabled(true);

    startMissionButton = new QPushButton(tr("开始执行"));
    startMissionButton->setToolTip(tr("目标点设置完成后，开始执行任务，飞行器开始飞向目标点"));
    startMissionButton->setFixedSize(75,20);
    checkCommunicationButton = new QPushButton(tr("检查通信"));
    checkCommunicationButton->setToolTip(tr("检查通信状态"));
    checkCommunicationButton->setFixedSize(75, 20);
    status1Label = new QLabel(tr("选中点经度："));
    status2Label = new QLabel(tr("选中点纬度："));
    QVBoxLayout *missionLayout = new QVBoxLayout;
    missionLayout->addLayout(formLayout);
    missionLayout->addLayout(agentIDLayout);
    missionLayout->addLayout(setGoalLayout);
    missionLayout->addWidget(clearAllMarkersButton);
    missionLayout->addLayout(missionAltitudeLayout);
    missionLayout->addWidget(setGoalButton);
    missionLayout->addWidget(setCenterPointButton);
    missionLayout->addLayout(spaceLayout);
    missionLayout->addWidget(selectFormCombo);
    missionLayout->addWidget(startMissionButton);
    missionLayout->addWidget(checkCommunicationButton);
    missionLayout->addStretch();

    QVBoxLayout *controlLayout = new QVBoxLayout;
    controlLayout->addLayout(agentAccountLayout);


    controlLayout->addLayout(commandLayout);
    controlLayout->addLayout(missionLayout);
    controlLayout->addStretch();
    controlLayout->addWidget(status1Label, 0, Qt::AlignBottom);
    controlLayout->addWidget(status2Label, 0, Qt::AlignBottom);
    controlGroup->setLayout(controlLayout);
    controlGroup->setFixedWidth(200);

    dock = new QDockWidget(tr("Map"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    viewMenu->addAction(dock->toggleViewAction());

    mapWeb = new QWebView;
    //QDir tempDir("../../map/test.html");//../map/test.html
    QDir tempDir("D:/QT/upper_monitor_0.8.7_v2/upper_monitor_0.8.7/map/test.html");//../map/test.html
    QString filePath = "file:///" + tempDir.absolutePath();
    mapWeb->load(QUrl(filePath));//load the map in relevant path
    dock->setWidget(mapWeb);

    QHBoxLayout *mainLayout = new  QHBoxLayout;
    mainLayout->addWidget(controlGroup, 0, Qt::AlignLeft);
    mainLayout->addWidget(dock);
    mainLayout->setMenuBar(menuBar);

    setLayout(mainLayout);

    webFrameObj = new Returnvlc(this);

    connect(mapWeb->page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),this, SLOT(addJavaScript()));//将object对象与js中的对象绑定
    connect(setGoalButton,SIGNAL(clicked(bool)), this, SLOT(setGoalPosition()));//将更新按钮与槽绑定

    drawPointTimer = new QTimer(this);
    connect(drawPointTimer, SIGNAL(timeout()), this, SLOT(drawPointTimerUpdate()));//地图定时画点
    drawPointTimer->start(1000);

    connect(takeoffButton, SIGNAL(clicked(bool)), this, SLOT(on_takeoffButton_clicked()));
    connect(landButton, SIGNAL(clicked(bool)), this, SLOT(on_landButton_clicked()));
    connect(urgencyStopButton, SIGNAL(clicked(bool)), this, SLOT(on_urgencyStopButton_clicked()));
    connect(clearAllMarkersButton, SIGNAL(clicked(bool)), this, SLOT(on_clearAllMarkers_clicked()));
    connect(selectGoalButton, SIGNAL(clicked(bool)), this, SLOT(on_selectGoalButton_clicked()));
    connect(clearGoalButton, SIGNAL(clicked(bool)), this, SLOT(on_clearGoalButton_clicked()));
    connect(webFrameObj, SIGNAL(returnValue()), this, SLOT(updateFocusValue()));
    connect(webFrameObj, SIGNAL(returnValue()), this, SLOT(receiveDataFromWeb()));
    connect(setCenterPointButton, SIGNAL(clicked(bool)), this, SLOT(on_setCenterPointButton_clicked()));
    connect(startMissionButton, SIGNAL(clicked(bool)), this, SLOT(on_startMissionButton_clicked()));
    connect(checkCommunicationButton, SIGNAL(clicked(bool)), this, SLOT(on_checkCommunicationButton_clicked()));
    connect(formCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(enableForm()));

}

void MapPage::addJavaScript()
{
    mapWeb->page()->mainFrame()->addToJavaScriptWindowObject("obj",webFrameObj);
}

void MapPage::setGoalPosition()
{
    if(formCombo->currentText() == tr("手动选取目标点"))
    {
        uav_status_flag = 0x81; // 开始设置目标位置
    }
    else if(formCombo->currentText() == tr("编队飞行"))
    {
    }
}

void MapPage::on_startMissionButton_clicked()
{
    if(formCombo->currentText() == tr("手动选取目标点"))
        uav_status_flag = 4;
    else if(formCombo->currentText() == tr("编队飞行"))
    {
        if(leader_goal_position_account >= 0)
        {
            uav_status_flag = 6;
            temp_goalPosition[AGENT_ACCOUNT/2][0] = leader_goal_position[0][0]; // 设置领航者第一个目标点位置
            temp_goalPosition[AGENT_ACCOUNT/2][1] = leader_goal_position[0][1];
            temp_goalPosition[AGENT_ACCOUNT/2][2] = leader_goal_position[0][2];
            current_leader_goal_position = 0; //当前领航者目标位置
        }
        else
        {
            QString message = "请先设置领航者目标位置";
            QMessageBox::information(this, tr("QMessageBox::information()"), message);

            return;
        }
    }
}

void MapPage::sendData2Web(QString x, QString y, QString num)
{//槽函数，调用js中的plane函数
    QWebFrame *frame = mapWeb->page()->mainFrame();
    QString cmd = QString("plane(\"%1\",\"%2\",\"%3\")").arg(x).arg(y).arg(num);
    frame->evaluateJavaScript(cmd);
//    qDebug()<<x<<y << num;
}

void MapPage::on_clearAllMarkers_clicked() //清除所有标志
{
    QWebFrame *frame = mapWeb->page()->mainFrame();
    QString cmd = QString("ClearAllMarkers()");
    frame->evaluateJavaScript(cmd);
    leader_goal_position_account = -1; // 将领航者目标位置清空
}

void MapPage::updateFocusValue()
{
    //qDebug() << webFrameObj->getinfo3() << " " << webFrameObj->getinfo1() << " " << webFrameObj->getinfo2();
    status1Label->setText("选中点经度：" + webFrameObj->getinfo2());
    status2Label->setText("选中点纬度：" + webFrameObj->getinfo1());
}

void MapPage::drawPointTimerUpdate()
{
   // static double step = 0.000001;
    for(int i=1; i<AGENT_ACCOUNT; i++)
    {
      /*  current_position[i][0]=113.383332+i*0.00001; // 测试画线功能
        current_position[i][1]=23.066529;
        current_position[i][2]=8.850000;
        current_position[i][0]+=step;
        current_position[i][1]+=step;
        current_position[i][2]+=step;*/
        sendData2Web(QString::number(current_position[i][0], 10, 6), QString::number(current_position[i][1], 10, 6), QString::number(i, 10));
    }
    // step+=0.000005;
}

void MapPage::receiveDataFromWeb()
{
    int id = webFrameObj->getinfo3().toInt(0, 10);
    QString goalPosition_lat = webFrameObj->getinfo1();
    QString goalPosition_lng = webFrameObj->getinfo2();
    if(formCombo->currentText() == tr("手动选取目标点"))
    {
        temp_goalPosition[id][0] = goalPosition_lng.toDouble(0);
        temp_goalPosition[id][1] = goalPosition_lat.toDouble(0);
        temp_goalPosition[id][2] = missionAltitudeEdit->text().toDouble();
    }
    else if(formCombo->currentText() == tr("编队飞行"))
    {
        leader_goal_position[id][0] = goalPosition_lng.toDouble(0); // 设置经度
        leader_goal_position[id][1] = goalPosition_lat.toDouble(0); // 设置纬度
        leader_goal_position[id][2] = missionAltitudeEdit->text().toDouble(); //设置高度
    }
    else if(formCombo->currentText() == tr("选取队形"))
    {
        double center_longitude = goalPosition_lng.toDouble(0);
        double center_latitude = goalPosition_lat.toDouble(0);
        for(int i=1; i<AGENT_ACCOUNT; i++)
        {
            temp_goalPosition[i][0] = center_longitude + temp_formation[i-1][0]*1e-5;
            temp_goalPosition[i][1] = center_latitude + temp_formation[i-1][1]*1e-5;
            temp_goalPosition[i][2] = missionAltitudeEdit->text().toDouble();
        }
    }
}

void MapPage::on_selectGoalButton_clicked()
{
    if(formCombo->currentText() == tr("手动选取目标点"))
    {
        if(agentIDCombo->currentIndex() < AGENT_ACCOUNT-1)
        {
            int agent_id = agentIDCombo->currentIndex() + 1;

            QWebFrame *frame = mapWeb->page()->mainFrame();
            QString cmd = QString("SelectGoal(\"%1\")").arg(QString::number(agent_id, 10));
            QVariant ret = frame->evaluateJavaScript(cmd);
        }
    }
    else if(formCombo->currentText() == tr("编队飞行"))
    {
        leader_goal_position_account++;
        QWebFrame *frame = mapWeb->page()->mainFrame();
        QString cmd = QString("SelectLeaderGoal(\"%1\")").arg(QString::number(leader_goal_position_account, 10));
        QVariant ret = frame->evaluateJavaScript(cmd);
    }
}

void MapPage::on_clearGoalButton_clicked()
{
    if(agentIDCombo->currentIndex() < AGENT_ACCOUNT-1)
    {
        int agent_id = agentIDCombo->currentIndex() + 1;

        QWebFrame *frame = mapWeb->page()->mainFrame();
        QString cmd = QString("ClearGoalMarker(\"%1\")").arg(QString::number(agent_id, 10));
        frame->evaluateJavaScript(cmd);
    }
    else if(agentIDCombo->currentIndex() == AGENT_ACCOUNT-1) //选中所有无人机
    {
        for(int agent_id=1; agent_id<AGENT_ACCOUNT; agent_id++)
        {
            QWebFrame *frame = mapWeb->page()->mainFrame();
            QString cmd = QString("ClearGoalMarker(\"%1\")").arg(QString::number(agent_id, 10));
            frame->evaluateJavaScript(cmd);
        }
    }
}


void MapPage::on_takeoffButton_clicked()
{
    if(takeoffAltitudeEdit->text().toDouble(0) > 0)
    {
        for(int i=1; i<AGENT_ACCOUNT; i++)
        {
            temp_goalPosition[i][2] = takeoffAltitudeEdit->text().toDouble(0); // 原地起飞，只需要设置目标高度，经纬度不变
        }
        uav_status_flag = 1;
    }
    else
    {
        QString message = "请输入正确高度";
        QMessageBox::information(this, tr("QMessageBox::information()"), message);

        return;
    }
}

void MapPage::on_landButton_clicked()
{
    uav_status_flag = 2;
}

void MapPage::on_urgencyStopButton_clicked()
{
    uav_status_flag = 3;
}

void MapPage::on_setCenterPointButton_clicked()
{
    if(formCombo->currentText() == tr("选取队形"))
    {
        std::vector<double> pos; // 队形的中心点
        pos.resize(3);
        pos[0] = 0;
        pos[1] = 0;
        pos[2] = 0;

        uint iter = 20; // 算法迭代次数
        uint num = AGENT_ACCOUNT -1;  // 飞行器数量
        uint agent_space = spaceEdit->text().toDouble();
        uint formation = 0;

        if(selectFormCombo->currentText() == tr("三角形"))
            formation = TRIANGLE;
        else if(selectFormCombo->currentText() == tr("圆形"))
            formation = CIRCLE;
        else if(selectFormCombo->currentText() == tr("正方形"))
            formation = SQUARE;
        else
            formation = SQUARE;

        for (uint i = 0; i < iter; i++)
        {
            CVT(temp_formation, num, pos, formation, agent_space);
        }

        if(selectFormCombo->currentText() == tr("一字形")) // 当需要生成一字型时，不采用CVT算法。注意，temp_formation的初始化在CVT函数中
        {
            for(int i=0; i<num/2; i++)
            {
                temp_formation[i][0] = 0;
                temp_formation[i][1] = i*agent_space;
                temp_formation[i][2] = 0;
            }
            for(int i=num/2; i<num; i++)
            {
                temp_formation[i][0] = 0;
                temp_formation[i][1] = -temp_formation[i-num/2][1] - agent_space;
                temp_formation[i][2] = 0;
            }
        }
        // 找到队形坐标中经度最小的一个，将其与队形坐标中的中间飞行器坐标对换，方便后续执行编队飞行
        uint index_min = 0;
        int min = temp_formation[0][0];
        for(uint i=0; i<num; i++)
        {
            if(temp_formation[i][0] < min)
            {
                min = temp_formation[i][0];
                index_min = i;
            }
         //   qDebug() << temp_formation[i][0] << ' ' << temp_formation[i][1] << ' ' << temp_formation[i][2] << ' ';
        }
        std::vector<double> temp; // 临时
        temp.resize(3);
        temp = temp_formation[AGENT_ACCOUNT/2-1];
        temp_formation[AGENT_ACCOUNT/2-1] = temp_formation[index_min];
        temp_formation[index_min] = temp;

        for(int i=0; i<num; i++)
        {
            QWebFrame *frame = mapWeb->page()->mainFrame();
            QString cmd = QString("SetFormation(\"%1\",\"%2\",\"%3\")").arg(QString::number(temp_formation[i][0], 10, 6)).arg(QString::number(temp_formation[i][1], 10, 6)).arg(i);
            frame->evaluateJavaScript(cmd);
        }
        QWebFrame *frame = mapWeb->page()->mainFrame();
        QString cmd = QString("SelectCenterPoint(\"%1\")").arg(QString::number(AGENT_ACCOUNT/2, 10));
        frame->evaluateJavaScript(cmd);
    }
}

void MapPage::enableForm()
{
    if(formCombo->currentText() == tr("手动选取目标点"))
    {
        agentIDCombo->setEnabled(true);
        selectGoalButton->setEnabled(true);
        clearGoalButton->setEnabled(true);
        clearAllMarkersButton->setEnabled(true);
        missionAltitudeEdit->setEnabled(true);
        setGoalButton->setEnabled(true);

        setCenterPointButton->setDisabled(true);
        spaceEdit->setDisabled(true);
        selectFormCombo->setDisabled(true);
    }
    else if(formCombo->currentText() == tr("选取队形"))
    {
        selectFormCombo->setDisabled(true);
        agentIDCombo->setDisabled(true);
        selectGoalButton->setDisabled(true);
        clearGoalButton->setDisabled(true);    
        setGoalButton->setDisabled(true);

        setCenterPointButton->setEnabled(true);
        spaceEdit->setEnabled(true);
        selectFormCombo->setEnabled(true);
        missionAltitudeEdit->setEnabled(true);
        clearAllMarkersButton->setEnabled(true);
    }
    else if(formCombo->currentText() == tr("编队飞行"))
    {
        selectFormCombo->setDisabled(true);
        agentIDCombo->setDisabled(true);
        selectGoalButton->setEnabled(true);
        clearGoalButton->setDisabled(true);
        clearAllMarkersButton->setEnabled(true);
        missionAltitudeEdit->setEnabled(true);
        setGoalButton->setDisabled(true);
        setCenterPointButton->setDisabled(true);
        spaceEdit->setDisabled(true);
        selectFormCombo->setDisabled(true);
    }
}

void MapPage::on_checkCommunicationButton_clicked()
{
    uav_status_flag = 5;
    check_communication = 1;
}


void MapPage::closeEvent(QCloseEvent *event)
{
    switch( QMessageBox::information(this, tr("CT Control View"),
    tr("Do you really want to log out CT Control View?"),
    tr("Yes"), tr("No"),0, 1 ) )
    {
      case 0:
        event->accept();
        break;
      case 1:
      default:
        event->ignore();
      break;
    }
}
