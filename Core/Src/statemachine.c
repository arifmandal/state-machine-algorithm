/*
 * statemachine.c
 *
 *  Created on: Sep 16, 2023
 *      Author: Arif Mandal
 */

#include "statemachine.h"
extern TIM_HandleTypeDef htim4;
extern volatile uint8_t buttonCounter;
extern int clockCount;
state_Type current_state;
void (*state_table[])(void) = { state_machine_init,
		                        state_LD1_function,
								state_LD2_function,
								state_LD3_function,
								state_LD4_function

};

void state_machine_init(void){
	current_state = STATE_LD1;
	CDC_Transmit_FS((uint8_t*)"Init State\n" , 11);
	HAL_Delay(200);
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 0);
}

void state_LD1_function(void){
	CDC_Transmit_FS((uint8_t*)"State-1\n" , 8);
	HAL_Delay(200);
	if (buttonCounter%4 == 1) {
		current_state = STATE_LD2;
		__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 125);
	}
}

void state_LD2_function(void){
	CDC_Transmit_FS((uint8_t*)"State-2\n" , 8);
	HAL_Delay(200);
	if (buttonCounter%4 == 2) {
		current_state = STATE_LD3;
		__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 250);
	}
}

void state_LD3_function(void){
	CDC_Transmit_FS((uint8_t*)"State-3\n" , 8);
	HAL_Delay(200);
	if (buttonCounter%4 == 3) {
		current_state = STATE_LD4;
		__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 375);
	}
}

void state_LD4_function(void){
	CDC_Transmit_FS((uint8_t*)"State-4\n" , 8);
	HAL_Delay(200);
	if (buttonCounter%4 == 0) {
		current_state = STATE_INIT;
		__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 500);
	}
}
