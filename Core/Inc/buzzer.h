/*
 * buzzer.h
 *
 *  Created on: Apr 18, 2026
 *      Author: tomo1
 */

#ifndef INC_BUZZER_H_
#define INC_BUZZER_H_
void start_buzzer_pwm(void);

void stop_buzzer_pwm(void);

void set_buzzer_pwm_duty(uint16_t duty);

void set_buzzer_pwm_freq(uint16_t freq);

#endif /* INC_BUZZER_H_ */


