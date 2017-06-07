#include <QtWidgets>
#include "statuspage.h"

static uint agent_communication_status_counter[AGENT_ACCOUNT] = {0};

StatusPage::StatusPage()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyyMMddhhmm");
    QString filename = "./log/log_" + str + ".txt";
    log = new QFile(filename);
    log->open(QIODevice::WriteOnly | QIODevice::Text);
    outfile = new QTextStream(log);
    *outfile << "AGENT LOG-" << str << "\n";
    *outfile << "AGENT ACCOUNT:" << QString::number(AGENT_ACCOUNT - 1, 10) << "\n";
    statusTable = new QTableWidget(40, 14);
    QStringList header;
    header<<"ID" << "连接状态" << "当前经度" << "当前纬度" << "当前高度" << "当前速度E" << "当前速度N" << "当前速度D" << "目标经度" << "目标纬度"  << "目标高度" << "待设置目标经度" << "待设置目标纬度" << "待设置目标高度";
    statusTable->setHorizontalHeaderLabels(header);
    statusTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    statusTable->verticalHeader()->setVisible(false); //隐藏列表头
    statusTable->setColumnWidth(0, 30);
    statusTable->horizontalHeaderItem(0)->setTextColor(QColor(0, 0, 0));
    for(int i=1; i<14; i++)
    {
        statusTable->setColumnWidth(i, 95);
    }
    for(int i=1; i<4; i++)
    {
        statusTable->horizontalHeaderItem(i)->setTextColor(QColor(128, 64, 0)); //设置文字颜色
    }
    for(int i=4; i<7; i++)
    {
        statusTable->horizontalHeaderItem(i)->setTextColor(QColor(0, 64, 0)); //设置文字颜色
    }
    for(int i=7; i<10; i++)
    {
        statusTable->horizontalHeaderItem(i)->setTextColor(QColor(0, 0, 128)); //设置文字颜色
    }
    for(int i=10; i<13; i++)
    {
        statusTable->horizontalHeaderItem(i)->setTextColor(QColor(0, 64, 64)); //设置文字颜色
    }
    statusTable->horizontalHeaderItem(13)->setTextColor(QColor(64, 0, 128)); //设置文字颜色

    for(int id=1; id<AGENT_ACCOUNT; id++)//状态初始化为未连接
    {
        statusTable->setItem(id-1, LINKSTATUS, new QTableWidgetItem("N"));
        statusTable->item(id-1, LINKSTATUS)->setTextColor(Qt::red);
        statusTable->item(id-1, LINKSTATUS)->setTextAlignment(Qt::AlignCenter);
    }

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(statusTable);
    setLayout(mainLayout);
    refreshStatusTimer = new QTimer(this);
    connect(refreshStatusTimer, SIGNAL(timeout()), this, SLOT(refreshStatus()));
    refreshStatusTimer->start(1000);
}

void StatusPage::refreshCurrentPosition()
{
    for(int id=1; id<AGENT_ACCOUNT; id++)
    {
        statusTable->setItem(id-1, AGENTID, new QTableWidgetItem(QString::number(id)));
        statusTable->setItem(id-1, CURRENTPOSITION_LNG, new QTableWidgetItem(QString::number(current_position[id][0], 10, 6)));
        statusTable->setItem(id-1, CURRENTPOSITION_LAT, new QTableWidgetItem(QString::number(current_position[id][1], 10, 6)));
        statusTable->setItem(id-1, CURRENTPOSITION_ALT, new QTableWidgetItem(QString::number(current_position[id][2], 10, 6)));
    }
}

void StatusPage::refreshTempGoalPosition()
{
    for(int id=1; id<AGENT_ACCOUNT; id++)
    {
        statusTable->setItem(id-1, TEMPGOALPOSITION_LNG, new QTableWidgetItem(QString::number(temp_goalPosition[id][0], 10, 6)));
        statusTable->setItem(id-1, TEMPGOALPOSITION_LAT, new QTableWidgetItem(QString::number(temp_goalPosition[id][1], 10, 6)));
        statusTable->setItem(id-1, TEMPGOALPOSITION_ALT, new QTableWidgetItem(QString::number(temp_goalPosition[id][2], 10, 6)));
    }
}

void StatusPage::refreshGoalPosition()
{
    for(int id=1; id<AGENT_ACCOUNT; id++)
    {
        statusTable->setItem(id-1, GOALPOSITION_LNG, new QTableWidgetItem(QString::number(goal_position[id][0], 10, 6)));
        statusTable->setItem(id-1, GOALPOSITION_LAT, new QTableWidgetItem(QString::number(goal_position[id][1], 10, 6)));
        statusTable->setItem(id-1, GOALPOSITION_ALT, new QTableWidgetItem(QString::number(goal_position[id][2], 10, 6)));
    }
}

void StatusPage::refreshCurrentVelocity()
{
    for(int id=1; id<AGENT_ACCOUNT; id++)
    {
        statusTable->setItem(id-1, CURRENTVELOCITY_E, new QTableWidgetItem(QString::number(current_velocity[id][0], 10, 6)));
        statusTable->setItem(id-1, CURRENTVELOCITY_N, new QTableWidgetItem(QString::number(current_velocity[id][1], 10, 6)));
        statusTable->setItem(id-1, CURRENTVELOCITY_D, new QTableWidgetItem(QString::number(current_velocity[id][2], 10, 6)));
    }
}

void StatusPage::refreshLinkStatus()
{
    for(unsigned char id=1; id<AGENT_ACCOUNT; id++)
    {
        if((uav_status_flag > 0x80 && agent_communication_status[id] == (id+0x80)) || (uav_status_flag == 1 && agent_communication_status[id] == 1) || (uav_status_flag == 6 && agent_communication_status[id] == 6))
        {
            goal_position[id][0] = temp_goalPosition[id][0];
            goal_position[id][1] = temp_goalPosition[id][1];
            goal_position[id][2] = temp_goalPosition[id][2];
           // qDebug() << "uav_statis_flag:" <<uav_status_flag << " " << id << ":" <<agent_communication_status[id];
        }

        if(agent_communication_status[id] > 0)
        {
            if(uav_status_flag > 0x80 && agent_communication_status[id] == (id+0x80))
            {
                statusTable->setItem(id-1, LINKSTATUS, new QTableWidgetItem("设置目标点"));
            }
            else if((uav_status_flag == 1 && agent_communication_status[id] == 1))
            {
                statusTable->setItem(id-1, LINKSTATUS, new QTableWidgetItem("起飞"));
            }
            else if(uav_status_flag == 2 && agent_communication_status[id] == 2)
            {
                statusTable->setItem(id-1, LINKSTATUS, new QTableWidgetItem("降落"));
            }
            else if(uav_status_flag == 3 && agent_communication_status[id] == 3)
            {
                statusTable->setItem(id-1, LINKSTATUS, new QTableWidgetItem("悬停"));
            }
            else if(uav_status_flag == 4 && agent_communication_status[id] == 4)
            {
                statusTable->setItem(id-1, LINKSTATUS, new QTableWidgetItem("开始执行"));
            }
            else if(isArrived(id))
            {
                statusTable->setItem(id-1, LINKSTATUS, new QTableWidgetItem("到达目标"));
            }
            else if(uav_status_flag == 5 && agent_communication_status[id] == 5)
            {
                statusTable->setItem(id-1, LINKSTATUS, new QTableWidgetItem("检查通信"));
            }
            else if(uav_status_flag == 6 && agent_communication_status[id] == 6)
            {
                statusTable->setItem(id-1, LINKSTATUS, new QTableWidgetItem("编队保持"));
            }
            for(int id=1; id<AGENT_ACCOUNT; id++)
            {
                *outfile << QString::number(current_position[id][0], 10, 6) << " " << QString::number(current_position[id][1], 10, 6)
                        << " " << QString::number(current_position[id][2], 10, 6) << " ";
            }
            *outfile << "\n";
 //           statusTable->setItem(id-1, LINKSTATUS, new QTableWidgetItem("Y"));
            statusTable->item(id-1, LINKSTATUS)->setTextColor(Qt::blue);
            statusTable->item(id-1, LINKSTATUS)->setTextAlignment(Qt::AlignCenter);
           // qDebug() << "uav_statis_flag:" <<uav_status_flag << " " << id << ":" <<agent_communication_status[id];
            agent_communication_status[id] = 0;
            agent_communication_status_counter[id] = 0;
        }
        else
        {
            agent_communication_status_counter[id]++;
            if(agent_communication_status_counter[id] > 5)
            {
                statusTable->setItem(id-1, LINKSTATUS, new QTableWidgetItem("N"));
                statusTable->item(id-1, LINKSTATUS)->setTextColor(Qt::red);
                statusTable->item(id-1, LINKSTATUS)->setTextAlignment(Qt::AlignCenter);
            }
        }
    }
}

void StatusPage::refreshStatus()
{
    refreshCurrentPosition();
    refreshGoalPosition();
    refreshTempGoalPosition();
    refreshCurrentVelocity();
    refreshLinkStatus();
}

StatusPage::~StatusPage()
{
    log->close();
}

bool StatusPage::isArrived(int id)
{
    double sum = (current_position[id][0] - goal_position[id][0])*(current_position[id][0] - goal_position[id][0]) + (current_position[id][1] - goal_position[id][1])*(current_position[id][1] - goal_position[id][1]) + (current_position[id][2] - goal_position[id][2])*(current_position[id][2] - goal_position[id][2]);
    if(sum <= 1.5f*1.5f)
        return true;
    else
        return false;
}
