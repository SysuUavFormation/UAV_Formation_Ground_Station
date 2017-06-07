#include "uav_link.h"
#include <QDebug>

bool haveRecFlag = true;

UAV_link::UAV_link(Win_QextSerialPort *c):Protocol(c)
{

}

/*void UAV_link::updateDataBuff(int num, char* buff)
{
    for(int i = 0; i < num; i++)
        usart1_rec_data[usart1_rec_index++] = buff[i];
   // qDebug() << usart1_rec_index;
}*/

void UAV_link::Data_Receive_Anl()
{
    static uint8 data_read_index = 0;
    while(((uint8)(usart1_rec_index - data_read_index)) >= 4)//证明有数据没有读取，可以进行读取数据,至少枕头，数据长度，校验和，数据位，4字节，
    {
        if((*(usart1_rec_data + data_read_index)) == 0xfe)
        {
            uint8 _length = *(usart1_rec_data + (uint8)(data_read_index + 1)) + 4;//_length代表一帧数据最短长度，根据数据长度
            QTime t;
               qDebug()<<"length "<<_length;
            t.restart();
            while(t.elapsed() < 10)
            {
                uint8 _delta_rec_read = (usart1_rec_index - data_read_index );
                if(_delta_rec_read >= _length)//接收到完整的帧，长度匹配
                {
                break;
                }
            }
            for(uint8 i=0;i<(usart1_rec_index - data_read_index);i++)
            {
                qDebug("receive %02x", usart1_rec_data[data_read_index+i]);
            }
            uint8  temp_sum_local = 0;
            uint8  temp_sum_2_local = *(usart1_rec_data + (uint8)(data_read_index + _length - 1));
            for(uint8 temp_i_local = 0; temp_i_local < (_length - 1); temp_i_local ++)        //进行校验
            {
              temp_sum_local += *(usart1_rec_data + (uint8)(data_read_index + temp_i_local));
            }
            if(temp_sum_local != temp_sum_2_local)    //校验失败
            {
              qDebug() << "Check fail";
              for(uint8 i=0;i<(usart1_rec_index - data_read_index);i++)
              {
                  qDebug("%02x", usart1_rec_data[data_read_index+i]);
              }
              data_read_index ++;   //跳过改帧
              uint8 temp_src_id_local = *(usart1_rec_data + (uint8)(data_read_index + 2));
              if((((MY_SOURCE_ID - temp_src_id_local) == 0x01) || ((temp_src_id_local == FINAL_ID) && (MY_SOURCE_ID == FIRST_ID))))
              {
                  data_read_index	= usart1_rec_index;
                  Uav_Send_Data(UAV_GROUND_ALL_ID, UAV_GROUND_GPS_VELOCITY);
                  haveRecFlag = false;//已经发送，等待下一个飞行器的回应
                  t2.restart();
                  return;
              }
              continue;               //数据帧读取失败
            }

            uint8  temp_src_id_local = *(usart1_rec_data + (uint8)(data_read_index + 2));
            uint8 UAV_ID = temp_src_id_local - FIRST_ID;

            for(uint8 i = 0; i <2 ; i++)
               current_position[UAV_ID][i] = ((double)((int32)((usart1_rec_data[(uint8)(4*i+3 +3 + data_read_index)]<<24) | (usart1_rec_data[(uint8)(4*i+2 +3 + data_read_index)]<<16) | (usart1_rec_data[(uint8)(4*i+1 +3 + data_read_index)]<<8) | (usart1_rec_data[(uint8)(4*i +3 + data_read_index)]<<0)))) / 1e7;
            current_position[UAV_ID][2] = ((double)((int32)((usart1_rec_data[(uint8)(14 + data_read_index)]<<24) | (usart1_rec_data[(uint8)(13 + data_read_index)]<<16) | (usart1_rec_data[(uint8)(12 + data_read_index)]<<8) | (usart1_rec_data[(uint8)(11 + data_read_index)]<<0)))) / 100.0;

            current_velocity[UAV_ID][2] = -(((double)((int32)((usart1_rec_data[(uint8)(18 + data_read_index)]<<24) | (usart1_rec_data[(uint8)(17 + data_read_index)]<<16) | (usart1_rec_data[(uint8)(16 + data_read_index)]<<8) | (usart1_rec_data[(uint8)(15 + data_read_index)]<<0)))) / 100);
            current_velocity[UAV_ID][1] = ((double)((int32)((usart1_rec_data[(uint8)(22 + data_read_index)]<<24) | (usart1_rec_data[(uint8)(21 + data_read_index)]<<16) | (usart1_rec_data[(uint8)(20 + data_read_index)]<<8) | (usart1_rec_data[(uint8)(19 + data_read_index)]<<0)))) / 100;
            current_velocity[UAV_ID][0] = ((double)((int32)((usart1_rec_data[(uint8)(26 + data_read_index)]<<24) | (usart1_rec_data[(uint8)(25 + data_read_index)]<<16) | (usart1_rec_data[(uint8)(24 + data_read_index)]<<8) | (usart1_rec_data[(uint8)(23 + data_read_index)]<<0)))) / 100;



            //qDebug() << UAV_ID <<"-success";
            //for(uint8 i=0;i<(usart1_rec_index - data_read_index);i++)
            //{
            //    qDebug("%02x", usart1_rec_data[data_read_index+i]);
            //}

            //返回各飞行器标识
            uint8 temp_flag = usart1_rec_data[(uint8)(27 + data_read_index)];//判断标志位
            agent_communication_status[UAV_ID] = temp_flag;

            if( (((temp_src_id_local - MY_SOURCE_ID) <= 0x02) && temp_src_id_local > MY_SOURCE_ID) || ((temp_src_id_local <= (FIRST_ID+1))  && (MY_SOURCE_ID == FINAL_ID)) || ((MY_SOURCE_ID == (FINAL_ID-1)) && ((temp_src_id_local == FINAL_ID) || (temp_src_id_local == FIRST_ID))) )
          //  if((temp_src_id_local - MY_SOURCE_ID == 0x01) || ((temp_src_id_local == FIRST_ID) && (MY_SOURCE_ID == FINAL_ID)))
            {
                //如果下一个飞行器有回应
                haveRecFlag = true;
            }
            if(((MY_SOURCE_ID - temp_src_id_local) == 0x01) || ((temp_src_id_local == FINAL_ID) && (MY_SOURCE_ID == FIRST_ID)))
            {

                data_read_index	= usart1_rec_index;
                Uav_Send_Data(UAV_GROUND_ALL_ID, UAV_GROUND_GPS_VELOCITY);
                haveRecFlag = false;//已经发送，等待下一个飞行器的回应
                t2.restart();
                return;
            }
            data_read_index += _length;
            continue;
        }
        data_read_index++;
    }
    if(haveRecFlag == false)//如果没有收到下一个飞行器的回应（如果有回应，haveSendFlag会置为false）
    {
        if(t2.elapsed() > 200)
        {
          //如果延时超过200ms还没有收到下一个飞行器的回应，则重发
            Uav_Send_Data(UAV_GROUND_ALL_ID, UAV_GROUND_GPS_VELOCITY);
            t2.restart();
            qDebug()<<"Send again";
        }
    }
}

void UAV_link::double2uint8(double src, uint8 *dst, long ii)
{
    int32 b = src * ii;
    *dst = (uint8)(b & 0x000000ff);
    *(dst+1) = (uint8)((b & 0x0000ff00) >> 8);
    *(dst+2) = (uint8)((b & 0x00ff0000) >> 16);
    *(dst+3) = (uint8)((b & 0xff000000) >> 24);
}

void UAV_link::Uav_Send_Data(uint8 goal_id, uint8 message_id)
{
    uint8 _cnt=0;
    data_to_send[_cnt++] = 0xFE;
    data_to_send[_cnt++] = 0;                     //length
    data_to_send[_cnt++] = MY_SOURCE_ID;             //source id
    switch(message_id)
    {
    case UAV_GROUND_GPS_VELOCITY:
      //调试用的
      if(uav_status_flag >= (FIRST_ID + 1) && uav_status_flag <= (FIRST_ID + AGENT_ACCOUNT -1))// 设置目标点
      {
          current_position[MY_SOURCE_ID-0x80][0] = temp_goalPosition[uav_status_flag - FIRST_ID][0];
          current_position[MY_SOURCE_ID-0x80][1] = temp_goalPosition[uav_status_flag - FIRST_ID][1];
          current_position[MY_SOURCE_ID-0x80][2] = temp_goalPosition[uav_status_flag - FIRST_ID][2];
      }

      else if(uav_status_flag == 1)// 设置起飞目标高度
      {
          current_position[MY_SOURCE_ID-0x80][2] = temp_goalPosition[1][2];//设置起飞高度，所有飞行器的起飞高度相同
      }

      else if(uav_status_flag == 6)// 设置编队飞行领航无人机的目标点
      {
          if(reachedGoal(current_position[AGENT_ACCOUNT/2], temp_goalPosition[AGENT_ACCOUNT/2]) == true)// 如果已经到达上一个目标位置
          {
              if(current_leader_goal_position < leader_goal_position_account)// 检查是否还有下一个目标位置
              {
                  current_leader_goal_position++;
                  temp_goalPosition[AGENT_ACCOUNT/2][0] = leader_goal_position[current_leader_goal_position][0];
                  temp_goalPosition[AGENT_ACCOUNT/2][1] = leader_goal_position[current_leader_goal_position][1];
                  temp_goalPosition[AGENT_ACCOUNT/2][2] = leader_goal_position[current_leader_goal_position][2];
              }
          }
          current_position[MY_SOURCE_ID-0x80][0] = temp_goalPosition[AGENT_ACCOUNT/2][0];
          current_position[MY_SOURCE_ID-0x80][1] = temp_goalPosition[AGENT_ACCOUNT/2][1];
          current_position[MY_SOURCE_ID-0x80][2] = temp_goalPosition[AGENT_ACCOUNT/2][2];
      }

        double2uint8(current_position[MY_SOURCE_ID-0x80][0], laah_state_u8, 1.0e7);
        double2uint8(current_position[MY_SOURCE_ID-0x80][1], laah_state_u8+4, 1.0e7);
        double2uint8(current_position[MY_SOURCE_ID-0x80][2], laah_state_u8+12, 100);
        double2uint8(-current_velocity[MY_SOURCE_ID-0x80][2], dne_velocity_u8, 100);
        double2uint8(current_velocity[MY_SOURCE_ID-0x80][1], dne_velocity_u8+4, 100);
        double2uint8(current_velocity[MY_SOURCE_ID-0x80][0], dne_velocity_u8+8, 100);
         for(uint8 temp_i_local = 0; temp_i_local < 8; temp_i_local++)
        {
          data_to_send[_cnt++] = laah_state_u8[temp_i_local];
        }
         for(uint8 temp_i_local = 12; temp_i_local < 16; temp_i_local++)
        {
          data_to_send[_cnt++] = laah_state_u8[temp_i_local];
        }
        for(uint8 temp_i_local = 0; temp_i_local < 12; temp_i_local++)
        {
          data_to_send[_cnt++] = dne_velocity_u8[temp_i_local];
        }
        data_to_send[_cnt++] = uav_status_flag;

//循环加一发送
       if(uav_status_flag >= FIRST_ID)
         uav_status_flag += 1;

       //初始化
       if((uav_status_flag > FINAL_ID))
       {
         uav_status_flag = FIRST_ID + 1;
       }
            break;

        default:
            break;
    }


    data_to_send[1] = _cnt - 3;

    uint8 sum = 0;
    for(uint8 temp_i_local = 0; temp_i_local < _cnt; temp_i_local++)
    sum += data_to_send[temp_i_local];
    data_to_send[_cnt++] = sum;
    qDebug("data_to_send");
       for(int i=0;i<_cnt;i++)
          qDebug("%02x", data_to_send[i]);
    //send_data(data_to_send, _cnt);
    myCom->write(data_to_send, _cnt);
}


bool UAV_link::reachedGoal(double *current_position, double *goal_position)
{
        /* Check if the agent has reached its goal. */
    double sum1 = 0, sum2 = 0;
    double tmp1 = (goal_position[0] - current_position[0]) * 1.0e5; //GPS坐标转换为以米为单位
    double tmp2 = (goal_position[1] - current_position[1]) * 1.0e5;
    double tmp3 = (goal_position[2] - current_position[2]);
    sum1 = tmp1 * tmp1 + tmp2 * tmp2 + tmp3*tmp3;
    sum2 = 1.0f * 1.5 * 1.5;

//	printf("%f %f\n", sum1, sum2);
    if(sum1 > sum2)
    {
        return false;
    }
     return true;
}
