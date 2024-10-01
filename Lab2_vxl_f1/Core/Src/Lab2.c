/*
 * Lab2.c
 *
 *  Created on: Sep 12, 2024
 *      Author: Admin
 */


#include <Lab2.h>
#include "software_timer.h"
void System_Lab2_init(){
	timer_init();
	//Led_Matrix_Timer_Scan
	setTimer(2, 150);

}

//////////////////////// LED MATRIX ////////////////////////////////
const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;

//data
unsigned matrix_buffer_col[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
unsigned data_pin_row[8] = {0b0, 0b0, 0b0, 0b0, 0b0, 0b0, 0b0, 0b0};
//scan led
unsigned Col_Code_One_Hot[8] = {0xFE, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF, 0xBF, 0x7F};
unsigned En_Col[8] = {0b1, 0b1, 0b1, 0b1, 0b1, 0b1, 0b1, 0b1};

//////////////////////////////////////////////////////////////////
unsigned characterHEX[][8] = {	// sum = 38 characterHEX
{0xFF, 0x00, 0x00, 0xFC, 0xFC, 0xFC, 0xFC, 0xFF},//L 0
{0xFF, 0xC0, 0x80, 0x33, 0x33, 0x80, 0xC0, 0xFF},//A 1
{0x00, 0x00, 0xAF, 0xCF, 0xCF, 0xAF, 0x00, 0x00},//M 2
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},// khoảng trắng 3
{0xCF, 0x87, 0x83, 0xC1, 0xC1, 0x83, 0x87, 0xCF}// hình trái tim, kí hiệu là '&' 4
};

void En_Col_Led_Matrix(){
	HAL_GPIO_WritePin(ENM_0_GPIO_Port, ENM_0_Pin, En_Col[0]);
	HAL_GPIO_WritePin(ENM_1_GPIO_Port, ENM_1_Pin, En_Col[1]);
	HAL_GPIO_WritePin(ENM_2_GPIO_Port, ENM_2_Pin, En_Col[2]);
	HAL_GPIO_WritePin(ENM_3_GPIO_Port, ENM_3_Pin, En_Col[3]);
	HAL_GPIO_WritePin(ENM_4_GPIO_Port, ENM_4_Pin, En_Col[4]);
	HAL_GPIO_WritePin(ENM_5_GPIO_Port, ENM_5_Pin, En_Col[5]);
	HAL_GPIO_WritePin(ENM_6_GPIO_Port, ENM_6_Pin, En_Col[6]);
	HAL_GPIO_WritePin(ENM_7_GPIO_Port, ENM_7_Pin, En_Col[7]);
}

void Write_data_Row(){
	HAL_GPIO_WritePin(ROW_0_GPIO_Port, ROW_0_Pin, data_pin_row[0]);
	HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin, data_pin_row[1]);
	HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin, data_pin_row[2]);
	HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin, data_pin_row[3]);
	HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin, data_pin_row[4]);
	HAL_GPIO_WritePin(ROW_5_GPIO_Port, ROW_5_Pin, data_pin_row[5]);
	HAL_GPIO_WritePin(ROW_6_GPIO_Port, ROW_6_Pin, data_pin_row[6]);
	HAL_GPIO_WritePin(ROW_7_GPIO_Port, ROW_7_Pin, data_pin_row[7]);
}

void coppy_data_characterHEX_to_buffer(int character){
	for(int i = 0; i < MAX_LED_MATRIX; i++){
		matrix_buffer_col[i] = characterHEX[character][i];
	}
}

void updateLEDMatrix (int index) {

	//buffer
	for(int i = 0; i < MAX_LED_MATRIX; i++){
		data_pin_row[i] = (matrix_buffer_col[index] >> (MAX_LED_MATRIX - 1 - i)) & 0b1;
	}

	//scan led_Matrix
	for(int i = 0; i < MAX_LED_MATRIX; i++){
		En_Col[i] = (Col_Code_One_Hot[index] >> i) & 0b1;
	}

	//display
	En_Col_Led_Matrix();
	Write_data_Row();
}

void animation_shift_down(){

}

void Exercise_10(){
	coppy_data_characterHEX_to_buffer(0);
	if(flag_timer[2]){
		updateLEDMatrix(index_led_matrix++);
		if(index_led_matrix > MAX_LED_MATRIX - 1) index_led_matrix = 0;
		flag_timer[2] = 0;
	}
}



