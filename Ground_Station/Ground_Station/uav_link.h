#ifndef UAV_LINK_H
#define UAV_LINK_H

#include "parameter.h"
#include <QTime>
#include "win_qextserialport.h"
#include "protocol.h"




class UAV_link:public Protocol
{
public:
    UAV_link(Win_QextSerialPort *c);
    char data_to_send[50];
    QTime t2;
private:
    //unsigned char usart1_rec_data[256];
    //unsigned char usart1_rec_index;

    //Win_QextSerialPort *myCom;

public:
    void double2uint8(double src, uint8 *dst, long ii);   //
    void Data_Receive_Anl();    //根据接收到的数据分析飞行器状态
    void Uav_Send_Data(uint8 goal_id, uint8 message_id);   //  地面站发数据
    //void updateDataBuff(int num, char* buff);   //  获取数据更新至DataBuff
    bool reachedGoal(double *current_position, double *goal_position);  // 判断是否到达目标点
};

#endif // UAV_LINK_H
