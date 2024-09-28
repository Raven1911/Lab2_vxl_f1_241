/*
 * Lab2.c
 *
 *  Created on: Sep 12, 2024
 *      Author: Admin
 */


#include <Lab2.h>
#include "Led7Seg_Display.h"
#include "software_timer.h"


////////// INIT GPIO ///////////////////////////////

GPIO_7SEG_Config Led_7Seg_Array[7] = {
	{SEG0_0_GPIO_Port, SEG0_0_Pin},  //  a
	{SEG0_1_GPIO_Port, SEG0_1_Pin},  //  b
	{SEG0_2_GPIO_Port, SEG0_2_Pin},  //  c
	{SEG0_3_GPIO_Port, SEG0_3_Pin},  //  d
	{SEG0_4_GPIO_Port, SEG0_4_Pin},  //  e
	{SEG0_5_GPIO_Port, SEG0_5_Pin},  //  f
	{SEG0_6_GPIO_Port, SEG0_6_Pin}   //  g
};
void System_Lab2_init(){
	Led7Seg_int(Led_7Seg_Array);
	timer_init();

	//timer scan led
	setTimer(0, 1000);
	setTimer(1, 1000);
}

unsigned Led_Pos[2] = {1, 1};
uint8_t Buffer = 0;
uint8_t Count_Led_Pos = 0;

void Exercise_1(){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
	if(flag_timer[0]){
		Buffer++;
		if(Buffer > 9){
			Buffer = 0;
		}
		display7SEG(Buffer);
		flag_timer[0] = 0;
	}

	//scan led
	if(flag_timer[1]){

		//HAL_GPIO_WritePin(GPIOx, GPIO_Pin, Led_Pos[0]);
		//HAL_GPIO_WritePin(GPIOx, GPIO_Pin, Led_Pos[1]);
		flag_timer[1] = 0;
	}

}

//void Led_test(){
//	if(flag_timer[0]){
//		HAL_GPIO_TogglePin(LED_T_GPIO_Port, LED_T_Pin);
//		flag_timer[0] = 0;
//	}
//}

