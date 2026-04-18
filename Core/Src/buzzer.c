/*
 * buzzer.c
 *
 *  Created on: Apr 18, 2026
 *      Author: tomo1
 */


#include "global.h"

void start_buzzer_pwm(void)
{
	//TIM2のPWMを開始する
	HAL_TIM_PWM_Start(&htim16, TIM_CHANNEL_1);
}

void stop_buzzer_pwm(void)
{
	//TIM2のPWMを停止する
	HAL_TIM_PWM_Stop(&htim16, TIM_CHANNEL_1);
}

void set_buzzer_pwm_duty(uint16_t duty)
{
	//TIM2のPWMのデューティ比を設定する
	__HAL_TIM_SET_COMPARE(&htim16, TIM_CHANNEL_1, duty);
}

void set_buzzer_pwm_freq(uint16_t freq)
{
	__HAL_TIM_SET_AUTORELOAD(&htim16, freq);
	set_buzzer_pwm_duty(freq / 2); //デューティ比を50%にする
}