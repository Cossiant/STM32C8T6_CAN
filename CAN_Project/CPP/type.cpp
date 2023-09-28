//
// Created by Admin on 2023/9/28 0028.
//
#include "include.h"

CAN_Data_Class::CAN_Data_Class() {
    this->CAN_STD_ID = MY_STD_ID;
    this->CAN_EXTI_ID = MY_EXTI_ID;
		this->MsgAvailable = 0;
}