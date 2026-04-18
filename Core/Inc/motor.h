/*
 * motor.h
 *
 *  Created on: Apr 17, 2026
 *      Author: tomo1
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_
void start_pwm(void);

void stop_pwm(void);

void set_pwm_duty_r(uint16_t duty);

void set_pwm_duty_l(uint16_t duty);

void forward(void);

void backward(void);



#endif /* INC_MOTOR_H_ */
