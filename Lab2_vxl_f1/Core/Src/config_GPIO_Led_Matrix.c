/*
 * config_GPIO_Led_Matrix.c
 *
 *  Created on: Oct 2, 2024
 *      Author: Admin
 */

#include "config_GPIO_Led_Matrix.h"

unsigned int En_Col[8] = {0b1, 0b1, 0b1, 0b1, 0b1, 0b1, 0b1, 0b1};
unsigned int data_pin_row[8] = {0b0, 0b0, 0b0, 0b0, 0b0, 0b0, 0b0, 0b0};
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
