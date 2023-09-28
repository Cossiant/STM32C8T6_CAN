#include "include.h"
#include "cppmain.h"

//这里这两个头文件必须要写，不写就报错
CAN_Data_Class CAN_Data;

void CPP_Main() {
    LED_Init_Function();
    CANcommunication_Init_Function(&CAN_Data);
}

void CPP_Main_While() {
//    LED_Light_Function(1000);
//    通过CAN发送数据
		LED_Light_Function(200);
    CANcommunication_Send_Function(&CAN_Data);
		LED_Light_Function(200);
//    读取CAN发送过来的数据
    Read_CAN_Test(&CAN_Data);
		LED_Light_Function(2500);
}
