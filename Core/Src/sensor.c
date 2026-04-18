/*
 * sensor.c
 *
 *  Created on: Apr 17, 2026
 *      Author: tomo1
 */

#include "global.h"
#include "adc.h"
#include "sensor.h"


int get_adc_value(ADC_HandleTypeDef* hadc, uint32_t channel) {

    ADC_ChannelConfTypeDef sConfig = { 0 };

    sConfig.Channel = channel;
    sConfig.Rank = ADC_REGULAR_RANK_1;
    sConfig.SamplingTime = ADC_SAMPLETIME_19CYCLES_5;
    sConfig.Offset = 0;
    HAL_ADC_Stop(hadc);
    HAL_ADC_ConfigChannel(hadc, &sConfig);

    HAL_ADC_Start(hadc);                    // AD変換を開始する
    HAL_ADC_PollForConversion(hadc, 100);   // AD変換終了まで待機する
    HAL_ADC_Stop(hadc);
    return HAL_ADC_GetValue(hadc);          // AD変換結果を取得する
}

//+++++++++++++++++++++++++++++++++++++++++++++++
//get_sensor_value_r
// Sensor R の値を読み取る
// 引数：無し
// 戻り値：電圧値（12bit分解能）
//+++++++++++++++++++++++++++++++++++++++++++++++
int get_sensor_value_r() {
    return get_adc_value(&hadc2, ADC_CHANNEL_1);
}

//+++++++++++++++++++++++++++++++++++++++++++++++
//get_sensor_value_fl
// Sensor FL の値を読み取る
// 引数：無し
// 戻り値：電圧値（12bit分解能）
//+++++++++++++++++++++++++++++++++++++++++++++++
int get_sensor_value_fl() {
    return get_adc_value(&hadc2, ADC_CHANNEL_3);
}

//+++++++++++++++++++++++++++++++++++++++++++++++
//get_sensor_value_fr
// Sensor FR の値を読み取る
// 引数：無し
// 戻り値：電圧値（12bit分解能）
//+++++++++++++++++++++++++++++++++++++++++++++++
int get_sensor_value_fr() {
    return get_adc_value(&hadc2, ADC_CHANNEL_2);
}

//+++++++++++++++++++++++++++++++++++++++++++++++
//get_sensor_value_l
// Sensor L の値を読み取る
// 引数：無し
// 戻り値：電圧値（12bit分解能）
//+++++++++++++++++++++++++++++++++++++++++++++++
int get_sensor_value_l() {
    return get_adc_value(&hadc2, ADC_CHANNEL_4);
}