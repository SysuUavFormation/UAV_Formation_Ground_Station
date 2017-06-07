#ifndef PARAMETER
#define PARAMETER
#include "commons.h"
//#define AGENT_ACCOUNT 11
#define AGENT_ACCOUNT 2
//全局变量
extern uint8 orca_begin;
extern bool uav_arrival_flag_b ;       //是否已经发送到达的标志，置true为已经发送, false为未发送

extern bool uav_whether_one_waypoint;   //飞行器是否进入单个航点模式。true为单个航点，false为单个航线。

//0地面等待；1起飞状态；2降落状态；3悬停状态；4飞往目标点；5检查通信；6多个航点；7飞行过程中设置；0x81设置目标点，与飞行器的ID号相关
extern uint8 uav_status_flag;
extern uint8 check_communication;
extern uint8 uav_status_flag_last;//前一个状态。
extern bool uavLowVoltageFlag;      //是否低压标志位

extern uint16 counter_period;
extern uint16 pit_flag;    //是否进入中断标志位，如果进入了中断则置1，否则置0.
extern bool uav_stop_flag ; //飞行器停止标志，如果置true，则飞行器悬停，置false，则飞行器运动
extern bool pit_send_heartbeat_flag;        //飞行器是否发送heartbeat标志位，可以发送则置true,不可以则置false
extern bool pit_read_data_flag;             //读取数据标志位，可以读取则置true，不可以则置false
extern bool pit_control_flag;  //对飞控进行控制标志位

extern bool pit_orca_flag;     //运行orca标志位

extern volatile uint16 tmp_pit_flag;
extern volatile bool tmp_pit_send_heartbeat_flag;
extern volatile bool tmp_pit_read_data_flag;
extern volatile bool tmp_pit_control_flag;
extern volatile bool tmp_pit_orca_flag;


extern uint8 usart0_rec_flag;   //是否有接收到串口0数据标志位,收到数据则置1，否则置0
extern uint8 usart0_rec_data ;      //串口0接收到的数据
extern uint8 usart0_timeout_flag ;           //飞控通信超时标志位

extern uint8 usart1_rec_index;   //串口1接收到数据的序号，如果收到了数据则加1
extern uint8 usart1_rec_data[256] ;      //串口1接收到的数据
extern uint8 usart1_read_index;   //串口1读取数据的序号，如果读取了数据则加1

static uint16 heart_beat;

//extern double longitude_now;  //经度,degree.
//extern double latitude_now;    //纬度,degree.
//extern float altitude_now;    //海拔,m.
//extern float height_now;      //高度,m.
extern float rpyh_state[4];     //roll,pitch,yaw,heading
extern uint8 rpyh_state_u8[8];     //roll,pitch,yaw,heading(uint8 type)

extern int8 rpty_control[4];         //roll,pitch,throttle,yaw control

extern double laah_state[4];   //longitude,latitude,altitude,height
extern uint8 laah_state_u8[16];   //longitude,latitude,altitude,height(uint8 type)

extern double dne_velocity[3];      //throttle,roll,pitch,yaw speed
extern uint8 dne_velocity_u8[12];    //throttle,roll,pitch,yaw speed(uint8 type)

extern float acceleration_state[3];   //x,y,z
extern uint8 acceleration_u8[6];   //x,y,z(uint8 type)

//extern double center[2];           //center
//extern double center[2];           //door
extern double home_position[2];           //home
extern double waypoint[500][2];           //waypoint

extern uint16 waypoint_length;              //飞行器需要到达多少个航点
extern uint16 waypointLengthIndex;         //当前飞行器的航点是进行到第几段
extern uint16 waypointLengthArrary[122];        //飞行器航点长度数组，总长度，段数，各个段的航点长度；
extern uint16 waypoint_temp_i;              //飞行器现在目标为第几个航点
extern bool mission_completed_flag_b;             //飞行器任务是否完成标志

extern double uav_goal_pos[3];             //当前的目标点位置

extern double uavDesiredHeight;          //单位：米，期望高度，初始化为2m,单位厘米
extern double uavHeightOffset;          //单位：米，高度偏差修正值，初始化为0m

extern uint8 satelliteNumber;              //卫星数目

extern uint32 uavVoltageCurrent;                //飞行器当前电压

extern uint8 agent_communication_status[AGENT_ACCOUNT];  //飞行器连接状态
extern double current_position[AGENT_ACCOUNT][3];

extern double goal_position[AGENT_ACCOUNT][3];

extern double temp_goalPosition[AGENT_ACCOUNT][3];

extern double current_velocity[AGENT_ACCOUNT][3];

extern double goal_velocity[AGENT_ACCOUNT][3];

extern double leader_goal_position[500][3]; // 编队飞行时，领航者的目标轨迹

extern int leader_goal_position_account; //领航者目标数量

extern int current_leader_goal_position; //当前领航者目标位置

#endif // PARAMETER

