#ifndef TYPE_H
#define TYPE_H

#include "include.h"

//标准标识符
#define MY_STD_ID 0x601
//设置拓展标识符
#define MY_EXTI_ID 0x000

class CAN_Data_Class {
public:
    uint32_t CAN_STD_ID;
    uint32_t CAN_EXTI_ID;
    uint8_t TxData[8] = {0x23, 0x81, 0x60, 0x00, 0x55, 0x55, 0x08, 0x00};
		uint8_t	RxData[8] = {0};
		uint8_t MsgAvailable;
    CAN_Data_Class();
};

#endif