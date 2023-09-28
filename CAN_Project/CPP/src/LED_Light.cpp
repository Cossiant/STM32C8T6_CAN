//
// Created by Admin on 2023/9/28 0028.
//
#include "include.h"

void LED_Init_Function() {
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
}

void LED_Light_Function(int Delay_Time) {
    //    HAL_GPIO_WritePin(LED_GPIO_Port,LED_Pin,GPIO_PIN_SET);
    //    HAL_Delay(1000);
    HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
    HAL_Delay(Delay_Time);
		HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
    HAL_Delay(Delay_Time);
}