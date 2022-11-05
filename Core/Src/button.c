/*
 * button.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Vuong
 */

#include "button.h"

static GPIO_PinState debounceButtonBuffer0[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer3[NO_OF_BUTTONS];
int timer_buttonpress_counter[NO_OF_BUTTONS];
int COUNT = 0;
uint16_t Pin_input[NO_OF_BUTTONS] = { RESET_Pin, INC_Pin, DEC_Pin };

///////////////////////////////////////////////////////////////////

void button_reading() {
	for (int i = 0; i < NO_OF_BUTTONS; i++) {
		debounceButtonBuffer0[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = debounceButtonBuffer2[i];
		debounceButtonBuffer2[i] = HAL_GPIO_ReadPin(GPIOB, Pin_input[i]);
		if ((debounceButtonBuffer0[i] == debounceButtonBuffer1[i])
				&& (debounceButtonBuffer1[i] == debounceButtonBuffer2[i])) {
			if (debounceButtonBuffer3[i] != debounceButtonBuffer2[i]) {
				debounceButtonBuffer3[i] = debounceButtonBuffer2[i];

				if (debounceButtonBuffer2[i] == BUTTON_IS_PRESSED) {
					button_process(Pin_input[i]);
					timer_buttonpress_counter[i] = NU_OF_DEBOUNCE;
				}
			} else {
				timer_buttonpress_counter[i]--;
				if (timer_buttonpress_counter[i] == 0) {
					if (debounceButtonBuffer2[i] == BUTTON_IS_PRESSED) {
						button_process(Pin_input[i]);
					}
					timer_buttonpress_counter[i] = NU_OF_AUTO_COUNTER;
				} else {
					STATE_4();
				}
			}
		}
	}
}

/////////////////////////////////////////////////////////

void button_process(uint16_t BUTTON) {
	switch (BUTTON) {
	case RESET_Pin:
		STATE_0();
		break;
	case INC_Pin:
		if(COUNT==9)
		{
			STATE_0();
			break;
		}
		STATE_1();
		break;
	case DEC_Pin:
		if(COUNT==0)
		{
			STATE_2();
			break;
		}
		STATE_3();
		break;
	}
}


void STATE_0() {
	COUNT = 0;
	display_seg7(COUNT);
}
//////////////////////////////////////////////////


void STATE_1() {
	COUNT++;
	display_seg7(COUNT);
}
////////////////////////////////////////////////


//STATE 2
void STATE_2()
{
	COUNT = 9;
	display_seg7(COUNT);
}


//STATE 3 + STATE 4
void STATE_3() {
	COUNT--;
	display_seg7(COUNT);
}
////////////////////////////////////////////////
void STATE_4() {
	if (timer_flag[1] == 1) {
		COUNT--;
		if (COUNT < 0)
			setTimer(1, 10000);
			STATE_0();
			return;
	}
}

