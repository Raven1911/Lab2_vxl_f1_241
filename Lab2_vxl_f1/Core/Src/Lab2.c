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

	//Data buffer	//Scan_led
	setTimer(0, 250);
	//DOT
	setTimer(1, 1000);

}

unsigned Led_Pos[4] = {1, 1, 1, 1};
unsigned En_Led_Pos[4] = {0b1110, 0b1101, 0b1011, 0b0111};
unsigned Led_Buffer[4] = {1, 2, 3, 0};

uint8_t index_led = 0;
uint8_t Max_Led = 4;
uint8_t Buffer = 0;

void En_led_7_seg(){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, Led_Pos[0]);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, Led_Pos[1]);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, Led_Pos[2]);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, Led_Pos[3]);
}

void update7SEG(int index){
		//DATA BUFFER
		Buffer = Led_Buffer[index];

		//scan led
		for(int i = 0; i < Max_Led; i++){
			Led_Pos[i] = (En_Led_Pos[index] >> i) & 0b1;
		}

		///////////////////////
		display7SEG(Buffer);
		En_led_7_seg();
		flag_timer[0] = 0;


	//DOT BLINK



}


void Exercise_3_4(){
	if(flag_timer[0]){
		update7SEG(index_led++);
		if(index_led > Max_Led - 1) index_led = 0;
		flag_timer[0] = 0;
	}

	if(flag_timer[1]){
		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
		flag_timer[1] = 0;
	}
}


