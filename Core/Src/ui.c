/*
 * ui.c
 *
 *  Created on: Apr 17, 2026
 *      Author: tomo1
 */

#include "global.h"
#include "usart.h"
//LEDを制御する関数
void set_led_r(bool on) {
	if (on) {
		HAL_GPIO_WritePin(led_0_GPIO_Port, led_0_Pin, GPIO_PIN_SET);
	} else {
		HAL_GPIO_WritePin(led_0_GPIO_Port, led_0_Pin, GPIO_PIN_RESET);
	}
}

void set_led_fr(bool on) {
	if (on) {
		HAL_GPIO_WritePin(led_1_GPIO_Port, led_1_Pin, GPIO_PIN_SET);
	} else {
		HAL_GPIO_WritePin(led_1_GPIO_Port, led_1_Pin, GPIO_PIN_RESET);
	}
}

void set_led_fl(bool on) {
	if (on) {
		HAL_GPIO_WritePin(led_2_GPIO_Port, led_2_Pin, GPIO_PIN_SET);
	}
	else {
		HAL_GPIO_WritePin(led_2_GPIO_Port, led_2_Pin, GPIO_PIN_RESET);
	}
}

void set_led_l(bool on) {
	if (on) {
		HAL_GPIO_WritePin(led_3_GPIO_Port, led_3_Pin, GPIO_PIN_SET);
	}
	else {
		HAL_GPIO_WritePin(led_3_GPIO_Port, led_3_Pin, GPIO_PIN_RESET);
	}
}

bool get_push_0(void) {
	return HAL_GPIO_ReadPin(push_0_GPIO_Port, push_0_Pin) == GPIO_PIN_RESET;
}

bool get_push_1(void) {
	return HAL_GPIO_ReadPin(push_1_GPIO_Port, push_1_Pin) == GPIO_PIN_RESET;
}

 /*------------------------------------------------------------
	 printf 用
 ------------------------------------------------------------*/
 //+++++++++++++++++++++++++++++++++++++++++++++++
 //__io_putchar
 // printf を使うために必要
 //+++++++++++++++++++++++++++++++++++++++++++++++
int __io_putchar(int ch) {
	uint8_t c = (uint8_t)ch;

	if (c == '\n') {
		uint8_t cr = '\r';
		HAL_UART_Transmit(&huart2, &cr, 1, HAL_MAX_DELAY);
	}

	HAL_UART_Transmit(&huart2, &c, 1, HAL_MAX_DELAY);
	return ch;
}