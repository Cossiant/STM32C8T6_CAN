//
// Created by Admin on 2023/9/28 0028.
//
#include "include.h"

CAN_HandleTypeDef hcantype;
CAN_TxHeaderTypeDef TxHeadertype;
CAN_RxHeaderTypeDef RxHeadertype;
CAN_Data_Class *pCAN_Data_Class;

void CANcommunication_Init_Function(CAN_Data_Class *CAN_Data) {
    //开启CAN模块
    HAL_CAN_Start(&hcantype);
    //开启CAN中断
    HAL_CAN_ActivateNotification(&hcantype, CAN_IT_RX_FIFO0_MSG_PENDING);

    //配置邮箱信息
    TxHeadertype.RTR = CAN_RTR_DATA;
    TxHeadertype.IDE = CAN_ID_STD;
    TxHeadertype.StdId = CAN_Data->CAN_STD_ID;
    TxHeadertype.TransmitGlobalTime = DISABLE;
    TxHeadertype.DLC = 8;

    //把数据地址赋给变量
    pCAN_Data_Class = CAN_Data;
}

void CANcommunication_Send_Function(CAN_Data_Class *CAN_Data) {
    HAL_CAN_AddTxMessage(&hcantype, &TxHeadertype, CAN_Data->TxData, &(CAN_Data->CAN_EXTI_ID));
    HAL_Delay(10);
}

//CAN中断接收函数
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *CanHandle) {
    /* Get RX message */
    HAL_CAN_GetRxMessage(CanHandle, CAN_RX_FIFO0, &RxHeadertype, pCAN_Data_Class->RxData);
    pCAN_Data_Class->MsgAvailable = 1;
}

void Read_CAN_Test(CAN_Data_Class *CAN_Data) {
    if (CAN_Data->MsgAvailable == 1) {
        unsigned char i;
        for (i = 0; i < 8; i++) {
            CAN_Data->TxData[i] = CAN_Data->RxData[i];
            CAN_Data->RxData[i] = 0;
        }
    }
}