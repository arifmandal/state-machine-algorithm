/*
 * statemachine.c
 *
 *  Created on: Sep 16, 2023
 *      Author: Arif Mandal
 */

#include "statemachine.h"

extern int clockCount;
state_Type current_state;
void (*state_table[])(void) = { state_LD1_function,
								state_LD2_function,
								state_LD3_function,
								state_LD4_function

};

void state_machine_init(void){
	current_state = STATE_LD1;
	clockCount = 0;
	HAL_GPIO_WritePin(GPIOD, ld1_Pin | ld2_Pin | ld3_Pin |ld4_Pin, 0);
}

void state_LD1_function(void){
	if (clockCount == 1) {
		current_state = STATE_LD2;
		HAL_GPIO_WritePin(GPIOD, ld1_Pin, 1);
	}
}

void state_LD2_function(void){
	if (clockCount == 2) {
		current_state = STATE_LD3;
		HAL_GPIO_WritePin(GPIOD, ld1_Pin | ld2_Pin, 1);
	}
}

void state_LD3_function(void){
	if (clockCount == 3) {
		current_state = STATE_LD4;
		HAL_GPIO_WritePin(GPIOD, ld1_Pin | ld2_Pin | ld3_Pin, 1);
	}
}

void state_LD4_function(void){
	if (clockCount == 4) {
		current_state = STATE_LD1;
		HAL_GPIO_WritePin(GPIOD, ld1_Pin | ld2_Pin | ld3_Pin| ld4_Pin , 1);
		clockCount = 0;
		HAL_Delay(200);
		HAL_GPIO_WritePin(GPIOD, ld1_Pin | ld2_Pin | ld3_Pin| ld4_Pin , 0);
		HAL_Delay(200);
	}
}
