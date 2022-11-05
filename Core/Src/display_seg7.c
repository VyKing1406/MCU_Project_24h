/*
 * display_seg7.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Vuong
 */

#include "display_seg7.h"

///////////////////////////////////////////////
uint16_t seg7_pin[7]= {seg1_Pin, seg2_Pin, seg3_Pin, seg4_Pin, seg5_Pin, seg6_Pin, seg7_Pin};
uint8_t number_seg7[10] = { 0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80,
		0x90 };

////////////////////////////////////////////////
void display_seg7(int index) {
	uint8_t num=number_seg7[index];
	for (int i = 0; i < 7; i++) {
		HAL_GPIO_WritePin(GPIOA, seg7_pin[i], ((num>>i)&0x01));
	}
}
