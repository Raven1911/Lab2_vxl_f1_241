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
	setTimer(0, 250);
	setTimer(1, 250);
	//DOT
	setTimer(2, 1000);
}

unsigned Led_Pos[2] = {1, 1};
unsigned En_Led_Pos[2] = {0b10, 0b01};

uint8_t Counter_Led_Pos = 0;
uint8_t Max_Led = 2;
uint8_t Buffer = 0;

void En_led_7_seg(){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, Led_Pos[0]);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, Led_Pos[1]);
}

void Exercise_2(){
	//DATA
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

		for(int i = 0; i < Max_Led; i++){
			Led_Pos[i] = (En_Led_Pos[Counter_Led_Pos] >> i) & 0b1;
		}

		Counter_Led_Pos++;
		if(Counter_Led_Pos > Max_Led - 1){
			Counter_Led_Pos = 0;
		}

		En_led_7_seg();
		flag_timer[1] = 0;
	}

	//DOT BLINK
	if(flag_timer[2]){
		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
		flag_timer[2] = 0;
	}

}


