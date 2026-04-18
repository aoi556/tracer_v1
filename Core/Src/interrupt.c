/*
 * interrupt.c
 *
 *  Created on: Apr 18, 2026
 *      Author: tomo1
 */
#include "global.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	//1mmsごとに呼び出されるタイマー割り込み
	if (htim->Instance == TIM6) {
		//ここに割り込み処理を書く





	}
}