#ifndef PROTOCOL_H
#define PROTOCOL_H


#include "parameter.h"
#include <QTime>
#include "win_qextserialport.h"
#define FIRST_ID                 0x80  //第一架飞行器id
#define FINAL_ID                 (FIRST_ID + AGENT_ACCOUNT - 1)  //最后一架飞行器id
#define MY_SOURCE_ID             0x80  //飞行器自身id
#define UAV_GROUND_ALL_ID        0xff    //发送到所有设备

#define UAV_GROUND_ARRIVAL              0x80
#define UAV_GROUND_GPS                  0x81
#define UAV_GROUND_ACC_RPYH             0x82
#define UAV_GROUND_RPTY_CONTROL         0x83
#define UAV_GROUND_CURRENT_STATUS       0x84
#define UAV_GROUND_LOW_VOLTAGE          0x85
#define UAV_GROUND_GPS_VELOCITY         0x86
#define UAV_GROUND_SEND_CHECK           0xf0
class Protocol
{
public:
    Protocol(Win_QextSerialPort *c);
    unsigned char usart1_rec_data[256];
    unsigned char usart1_rec_index;
    Win_QextSerialPort *myCom;

public:
    void updateDataBuff(int num, char* buff);     //接收数据
    void sendData(char *data_to_send,uint8 _cnt);  //发送数据
    //virtual void Uav_Send_Data(uint8 goal_id, uint8 message_id){}        //发送数据

    //void copy(unsigned char *usart1_rec_data,unsigned char *Protocol_usart1_rec_index, Win_QextSerialPort * myCom);
};

#endif // PROTOCOL_H

