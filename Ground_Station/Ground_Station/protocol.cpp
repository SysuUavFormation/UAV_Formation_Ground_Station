#include "uav_link.h"
#include "protocol.h"
#include <QDebug>
Protocol::Protocol(Win_QextSerialPort *c){
    myCom = c;
    usart1_rec_index = 0;
}
void Protocol::updateDataBuff(int num, char* buff){           //接收串口数据
    for(int i = 0; i < num; i++)
        usart1_rec_data[usart1_rec_index++] = buff[i];
}
void Protocol::sendData(char *data_to_send,uint8 _cnt){
     myCom->write(data_to_send, _cnt);
}

/*void Protocol::copy(unsigned char *usart1_rec_data,unsigned char *usart1_rec_index, Win_QextSerialPort *myCom){
    usart1_rec_data=Protocol_usart1_rec_data;
    usart1_rec_index=&Protocol_usart1_rec_index;
    myCom=Protocol_myCom;
}*/

