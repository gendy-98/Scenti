#ifndef _PWM_H_
#define _PWM_H_


#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/ledc.h"
#include "esp_err.h"
#include <esp_log.h>


#define PWM_GPIO_PIN 19
void PWM_init();
void PWM_set(uint32_t duty);

#endif
