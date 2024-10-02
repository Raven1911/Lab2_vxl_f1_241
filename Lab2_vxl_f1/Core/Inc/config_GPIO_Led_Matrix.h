/*
 * config_GPIO_Led_Matrix.h
 *
 *  Created on: Oct 2, 2024
 *      Author: Admin
 */

#ifndef INC_CONFIG_GPIO_LED_MATRIX_H_
#define INC_CONFIG_GPIO_LED_MATRIX_H_

#include <stdint.h>
#include "main.h"
#include "stm32f1xx_hal.h"

extern unsigned En_Col[8];
extern unsigned data_pin_row[8];
void En_Col_Led_Matrix();
void Write_data_Row();

#endif /* INC_CONFIG_GPIO_LED_MATRIX_H_ */
