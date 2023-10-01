/*
 * statemachine.h
 *
 *  Created on: Sep 16, 2023
 *      Author: Arif Mandal
 */

#ifndef INC_STATEMACHINE_H_
#define INC_STATEMACHINE_H_

#include "main.h"
#include "usbd_cdc_if.h"

typedef enum{
	STATE_LD1 = 0,
	STATE_LD2,
	STATE_LD3,
	STATE_LD4

}state_Type;

void state_machine_init(void);
void state_LD1_function(void);
void state_LD2_function(void);
void state_LD3_function(void);
void state_LD4_function(void);
#endif /* INC_STATEMACHINE_H_ */
