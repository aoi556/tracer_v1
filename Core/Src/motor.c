/*
 * motor.c
 *
 *  Created on: Apr 17, 2026
 *      Author: tomo1
 */


#include "global.h"
#include "motor.h"

void start_pwm(void) {
	//右
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	//左
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
}

void stop_pwm(void) {
	//右
	HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
	//左
	HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_4);
}

void set_pwm_duty_r(uint16_t duty) {
	//右
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, duty);
}

void set_pwm_duty_l(uint16_t duty) {
	//左
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, duty);
}
//正転
void forward(void)
{
	//左
	HAL_GPIO_WritePin(BIN1_GPIO_Port, BIN1_Pin, GPIO_PIN_SET);
	//右
	HAL_GPIO_WritePin(AIN1_GPIO_Port, AIN1_Pin, GPIO_PIN_RESET);
}
//逆転
void backward(void)
{
	HAL_GPIO_WritePin(BIN1_GPIO_Port, BIN1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(AIN1_GPIO_Port, AIN1_Pin, GPIO_PIN_SET);
}