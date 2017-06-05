# 无人机群分布式编队飞行上位机系统    
## 项目目的
实现基于GPS的无人机分布式编队避障飞行，工作目标
1. 分布式自主协同编队
2. 非合作式避碰
3. 实时路径规划  
## 为何开源
已经搭建完基础的平台，实现了简单的用上位机控制无人机的编队飞行，队形切换功能，并且考虑到QT的跨平台型，可以给更多的对于无人机群编队飞行感兴趣的开发者们减少前期环境搭建的时间开销，更好的进行无人机群分布式编队避障飞行的开发，希望更多的对于无人机编队飞行感兴趣的开发者们可以一起继承完善该上位机工程，同时对于不同的开发者们，我们允许并且友好的提供通信协议的接口，可以改进我们现有的通信协议，或者采用开发者自己的通信协议（修改或替换UAV_link类的相关函数实现），维护该上位机工程的多态性和可扩展性。
## 流程图
![image](http://ww4.sinaimg.cn/large/006HJ39wgy1ffu7cq4m39j30ia0lf74x.jpg)
## 上位机工程
&nbsp;&nbsp;&nbsp;&nbsp;地面站，也就是地面的基站，它能够通过GPS和串口通信实时监测无人机当前的飞行路线、状况等，能够发送命令，控制调度无人机群，也能够存储无人机群的飞行数据以进行后期的分析等。  
&nbsp;&nbsp;&nbsp;&nbsp;考虑到QT的跨平台型，上位机工程由Qt编写。测试使用系统为Windows7、Windows8.1和Windows10，使用的Qt  Creator版本为Qt Creator 3.4.2 (opensource)。Qt Creator编辑文本格式为UTF-8。  
&nbsp;&nbsp;&nbsp;&nbsp;地面站上位机人机交互界面有三个子界面：串口配置页、地图页和状态页。  



页面| 功能
---|---
串口页| 串口配置；与无线模块通信，获取无人机通信网络中的信息，并将地面站的信息发送到无人机通信网络中
地图页| 监测：将串口页获取到的无人机位置信息实时显示到google地图  
地图页|控制：发送起飞、降落、停止、执行任务等命令；从google地图上获取目标位置，并通过串口页发送出去
状态页| 从串口页获取到所有无人机的状态信息，并定时刷新  

&nbsp;&nbsp;&nbsp;&nbsp;地图页采取在QT中嵌套html网页框架的形式，实现基于谷歌电子地图瓦片的离线地图功能，主要涉及到相关js方面的技术，允许上位机在户外实测时离线的情况下加载当前地图。  

### 串口页
![aa](http://ww1.sinaimg.cn/large/006HJ39wgy1fftd1pvgs6j30r40hqwg1.jpg)
### 地图页
![aa](http://ww1.sinaimg.cn/large/006HJ39wgy1ffu73fz8iqj30w60k3dhp.jpg)
### 状态
![aa](http://ww3.sinaimg.cn/large/006HJ39wgy1fftd24c61dj30r40hq763.jpg)

### 上位机工程类图
![Markdown](http://ww4.sinaimg.cn/large/006HJ39wgy1ffu4drmhh6j30up04bt8n.jpg)  

### 相关文件说明

文件名 | 功能说明
---|---
parameter.h | parameter.h为通信协议基本变量和参数文件
commons.h | commons.h为数据类型定义文件
MainWidget | MainWidget为主界面，生成MapPage、SerialportPage、StatusPage这三个子界面，只完成界面布置功能
MapPage | MapPage为地图界面，用于显示地图，以及可视化显示地图与串口通信处理后的结果
SerialportPage | SerialportPage为串口调试界面，用于实现串口的基本功能，包括串口配置，通信的收发功能。SerialportPage包含串口类（Win_Qextserialport）和通信协议类（UAV_link）
UAV_link |UAV_link类为通信协议类，继承，本上位机充当飞行器编队分布式系统中虚拟飞行器，通信协议类用于解析数据包，向编队中的其他飞行器发送指令等。UAV_link包含parameter.h和commons.h。
protocol | protocol作为UAV_link的父类，用于实现串口的接收数据updateDataBuff和发送数据sendData的函数，UAV_link继承后，可以调用上面俩个函数进行串口通信
### 通信协议
无人机系统通信协议使用了自己的通信协议，分布式无人机编队系统要求每个无人机都知道其他无人机的数据以及地面站发送来的命令。在通信网络中，我们将地面站设置为0号无人机。  

无人机通信数据包如表所示：  
![image](http://ww1.sinaimg.cn/large/006HJ39wgy1ffu63a0bozj30j103n3yg.jpg)  

分布式广播通信  
![image](http://ww1.sinaimg.cn/large/006HJ39wgy1ffu67kv5xrj30gf0e7mxm.jpg)  
当所有无人机都开始运行程序准备就绪后，点击地面站检查通信，地面站会触发通信。为了保证通信网络中的各个节点按照一定顺序发送信息，避免因为同时发送，导致信号干扰出现丢包或者误码。所以，我们制定了通信协议如上图所示：理想情况下，第N架无人机发送信息，通信网络中其他无人机接收信息，但只有第N+1架无人机收到信息后开始发送自己的信息（由于是闭环网络，应注意临界条件），当第N架无人机收到第N+1架无人机发出的信息后，视为第N架无人机成功应答。

### 自定义通信协议
需要一个类继承protocol类，得到父类关于串口的接收数据和发送数据的方法，接收到串口的原始数据后，根据开发者自己的协议设计，添加对串口数据进行具体处理的函数（当前版本采用了Data_Receive_Anl()方法），得到解析后的数据，实现通信协议的多态和可扩展性。

## 问题与展望
进一步完善上位机系统，主要可以分为以下几个目标，根据需要实现：
1. 关联数据库记录飞行状态相关数据
2. opengl多角度三维显示无人机飞行状态
3. 进一步完善通信协议，当前采用的简单轮询方式并且每个数据包固定字节长度，效率较低开销较大
4. 当前采用了ORCA算法和CVT算法，可以新增相关避障算法，仿真通过后，实物上机测试算法
##  实验结果
### 检查通信
![image](http://ww3.sinaimg.cn/large/006HJ39wgy1ffu7q7hzpgj30gi0bf438.jpg)
### 起飞
![image](http://ww3.sinaimg.cn/large/006HJ39wgy1ffu7qr34fcj30f708btam.jpg)
### 选取队形
![image](http://ww4.sinaimg.cn/large/006HJ39wgy1ffu7rfr0lgj30c80aot9u.jpg)
### 队形切换
![image](http://ww2.sinaimg.cn/large/006HJ39wgy1ffu7s02ml9j30kn0b9q4p.jpg)
