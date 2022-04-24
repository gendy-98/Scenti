#ifndef _MAIN_TASK_H_
#define _MAIN_TASK_H_


#include "http_handel.h"
#include "LED.h"
#include "PWM.h"


void diffuser(uint32_t onTime, uint32_t offTime, uint32_t period, uint32_t power);
void diffuser_task();

#endif
