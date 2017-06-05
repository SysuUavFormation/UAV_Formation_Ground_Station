
#include "parameter.h"
//全局变量
uint8 orca_begin = 0;
bool uav_arrival_flag_b = false;       //是否已经发送到达的标志，置true为已经发送, false为未发送

bool uav_whether_one_waypoint = true;   //飞行器是否进入单个航点模式。true为单个航点，false为单个航线。

//0地面等待；1起飞状态；2降落状态；3悬停状态；4开始执行；5检测通信；6多个航点；7飞行过程中设置
uint8 uav_status_flag = 0;
uint8 check_communication = 0;
uint8 uav_status_flag_last = 5;//前一个状态。
bool uavLowVoltageFlag = false;      //是否低压标志位

uint16 counter_period = 200;
uint16 pit_flag = 0;     //是否进入中断标志位，如果进入了中断则加1，否则置0.
bool uav_stop_flag = false; //飞行器停止标志，如果置true，则飞行器悬停，置false，则飞行器运动
bool pit_send_heartbeat_flag = true;        //飞行器是否发送heartbeat标志位，可以发送则置true,不可以则置false
bool pit_read_data_flag = true;             //读取数据标志位，可以读取则置true，不可以则置false
bool pit_control_flag = true;               //对飞控进行控制标志位
bool pit_orca_flag = true;                  //进行orca标志位

volatile uint16 tmp_pit_flag = 0;
volatile bool tmp_pit_send_heartbeat_flag = true;
volatile bool tmp_pit_read_data_flag = true;
volatile bool tmp_pit_control_flag = true;
volatile bool tmp_pit_orca_flag = true;

uint8 usart0_rec_flag = 0;   //是否有接收到串口0数据标志位，如果收到数据则置1，否则置0.
uint8 usart0_rec_data ;      //串口0接收到的数据
uint8 usart0_timeout_flag = 0 ;          //飞控通信超时标志位

uint8 usart1_rec_index = 0;   //串口1接收到数据的序号，如果收到了数据则加1
uint8 usart1_rec_data[256] ;      //串口1接收到的数据
uint8 usart1_read_index = 0;   //串口1读取数据的序号，如果读取了数据则加1

float rpyh_state[4] = {0, 0, 0, 0};     //roll,pitch,yaw,heading
uint8 rpyh_state_u8[8];     //roll,pitch,yaw,heading(uint8 type)

int8 rpty_control[4] = {0, 0, 0, 0};         //roll,pitch,throttle,yaw control

double laah_state[4];   //longitude,latitude,altitude,height
uint8 laah_state_u8[16];   //longitude,latitude,altitude,height(uint8 type)
double dne_velocity[3];    //throttle_speed,roll_speed,pitch_speed,yaw_speed
uint8 dne_velocity_u8[12];  //throttle_speed,roll_speed,pitch_speed,yaw_speed(uint8 type)
float acceleration_state[3] = {0, 0, 0};   //x,y,z
uint8 acceleration_u8[6] = {0, 0, 0};   //x,y,z(uint8 type)

//double center[2] = {113.3808350, 23.0667510};           //center
//double center[2] = {113.381354, 23.0671136};           //door
double home_position[2] = {113.3808350, 23.0667510};           //home

double waypoint[500][2] = {{113.3808350, 23.0667510},
                          {113.3809399, 23.0667570},
                          {113.3807570, 23.0667130}};           //waypoint

uint16 waypoint_length = 3;              //飞行器当前需要到达多少个航点
uint16 waypointLengthIndex = 0;         //当前飞行器的航点是进行到第几段
uint16 waypointLengthArrary[122];        //飞行器航点长度数组，总长度，段数，各个段的航点长度；
uint16 waypoint_temp_i = 0;              //飞行器现在目标为第几个航点
bool mission_completed_flag_b = true;          //飞行器任务是否完成标志,初始化为true，因为等待任务接收

double uav_goal_pos[3] = {113.3808350, 23.0667510, 500};             //当前的目标点位置
double uavDesiredHeight = 5;          //单位：米，期望高度，初始化为20m
double uavHeightOffset = 0;          //单位：米，高度偏差修正值，初始化为0m

uint8 satelliteNumber = 0;              //卫星数目

uint32 uavVoltageCurrent = 0;                //飞行器当前电压

uint8 agent_communication_status[AGENT_ACCOUNT] = {0};

double current_position[AGENT_ACCOUNT][3] =
{
    {113.380790, 23.066687, 0.0},
    {113.383332, 23.066529, 8.850000},
/*    {113.383231, 23.066487, 7.760000},
    {113.383241, 23.066454, 8.320000},

    {113.383257, 23.066397, 7.680000},
    {113.383323, 23.066362, 8.030000},
    {113.383409, 23.066398, 7.660000},
    {113.383436, 23.066437, 8.420000}

    {113.1234220, 23.9876200, 0.0},
    {113.1234001, 23.9876201, 0.0},
    {113.1234111, 23.9876203, 0.0},
    {113.1234220, 23.9876201, 0.0}*/
                              };
double goal_position[AGENT_ACCOUNT][3] =
{
    {113.380868, 23.066849, 4.0},
    {113.380842, 23.066757, 4.0},
  /*  {113.1234250, 23.9876153, 0.0},
    {113.1234320, 23.9876019, 2.0},

    {113.1234390, 23.9876081, -4.0},
    {113.1234460, 23.9876121, 13.0},
    {113.1234040, 23.9876231, -8.0},
    {113.1234530, 23.9876105, 5.0},

    {113.1234600, 23.9876234, 5.0},
    {113.1234670, 23.9876231, 3.0},
    {113.1234740, 23.9876090, 5.0},
    {113.1234810, 23.9876070, -10.0}*/
};

double temp_goalPosition[AGENT_ACCOUNT][3] =
{
    {1, 2, 3}
};

double current_velocity[AGENT_ACCOUNT][3] =
{
    {0.0}
};

double goal_velocity[AGENT_ACCOUNT][3] =
{
    {0.0}
};

double leader_goal_position[500][3] =  // 编队飞行时，领航者的目标轨迹
{
    {0.0}
};

int leader_goal_position_account = -1;

int current_leader_goal_position = 0; //当前领航者目标位置
