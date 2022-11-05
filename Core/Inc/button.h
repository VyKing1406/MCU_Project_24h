/*
 * button.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Vuong
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
////////////////////////////////////////////////

#define NO_OF_BUTTONS 3
#define NU_OF_DEBOUNCE 300
#define NU_OF_AUTO_COUNTER 100
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET
////////////////////////////////////////////////

#include "main.h"
#include "display_seg7.h"
#include "interrupt_timer.h"


extern int COUNT;

///////////////////////////////////////////////////
void button_reading();
void button_process(uint16_t BUTTON);
void STATE_1();
void STATE_2();
void STATE_3();
void STATE_4();



#endif /* INC_BUTTON_H_ */
