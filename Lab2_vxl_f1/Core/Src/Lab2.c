/*
 * Lab2.c
 *
 *  Created on: Sep 12, 2024
 *      Author: Admin
 */


#include <Lab2.h>
void System_Lab2_init(){
	timer_init();
	setTimer(1, 800);
	//Led_Matrix_Timer_Scan
	setTimer(2, 100);

}

//////////////////////// LED MATRIX ////////////////////////////////
const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
//data
unsigned matrix_buffer_col[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
//scan led
unsigned Col_Code_One_Hot[8] = {0xFE, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF, 0xBF, 0x7F};


//////////////////////////////////////////////////////////////////
unsigned characterHEX[][8] = {	// sum = 3 characterHEX
{0xFF, 0x00, 0x00, 0xFC, 0xFC, 0xFC, 0xFC, 0xFF},//L 0
{0xFF, 0xC0, 0x80, 0x33, 0x33, 0x80, 0xC0, 0xFF},//A 1
{0xFF, 0x00, 0xA0, 0xCF, 0xCF, 0xA0, 0x00, 0xFF},//M 2
};

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

uint8_t data_character = 0;
uint8_t counter = MAX_LED_MATRIX - 1;
void animation_shift_left(){
	for(int i = 0; i < MAX_LED_MATRIX; i++){
		if(i <  7){
			matrix_buffer_col[i] = matrix_buffer_col[i+1];
		}
		if(i >= 7){
			matrix_buffer_col[i] = characterHEX[data_character][(MAX_LED_MATRIX - 1) - counter];
			counter--;
		}
		if(counter <= 0) {
			data_character++;
			counter = MAX_LED_MATRIX - 1;
			if(data_character > 2) data_character = 0;

		}
	}
}

uint8_t counter_character = 0;
void Exercise_10(){
	if(flag_timer[2]){
		updateLEDMatrix(index_led_matrix++);
		if(index_led_matrix > MAX_LED_MATRIX - 1) index_led_matrix = 0;
		flag_timer[2] = 0;
	}
	if(flag_timer[1]){
		animation_shift_left();
		flag_timer[1] = 0;
	}
}



