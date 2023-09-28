//
// Created by Admin on 2023/9/28 0028.
//

#ifndef CAN_COMMUNICATION_H
#define CAN_COMMUNICATION_H

void CANcommunication_Init_Function(CAN_Data_Class * CAN_Data);
void CANcommunication_Send_Function(CAN_Data_Class * CAN_Data);

void Read_CAN_Test(CAN_Data_Class *CAN_Data);

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *CanHandle);

#endif //CAN_PROJECT_CAN_COMMUNICATION_H
