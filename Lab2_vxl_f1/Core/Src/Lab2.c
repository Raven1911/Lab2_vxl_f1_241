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
//	{SEG_0_GPIO_Port, SEG_0_Pin},  //  a
//	{SEG_1_GPIO_Port, SEG_1_Pin},  //  b
//	{SEG_2_GPIO_Port, SEG_2_Pin},  //  c
//	{SEG_3_GPIO_Port, SEG_3_Pin},  //  d
//	{SEG_4_GPIO_Port, SEG_4_Pin},  //  e
//	{SEG_5_GPIO_Port, SEG_5_Pin},  //  f
//	{SEG_6_GPIO_Port, SEG_6_Pin}   //  g
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

void Led_test(){
	if(flag_timer[0]){
		HAL_GPIO_TogglePin(Led_GPIO_Port, Led_Pin);
		flag_timer[0] = 0;
	}
}

