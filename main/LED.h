#ifndef LED_H
#define LED_H

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"


#include <esp_log.h>
#include <esp_system.h>
#include <nvs_flash.h>
#include <sys/param.h>
#include "nvs_flash.h"
#include "esp_netif.h"
#include "esp_eth.h"
#include "protocol_examples_common.h"
#include "json_message.h"

#define LED_LOW_T_GPIO_PIN      4  //21
#define LED_MID_T_GPIO_PIN      5  //26
#define LED_HIGH_T_GPIO_PIN    18  //18
#define LED_CUSTOM_T_GPIO_PIN  21  //14
#define LED_LOW_P_GPIO_PIN     25  //33
#define LED_MID_P_GPIO_PIN     33  //25
#define LED_HIGH_P_GPIO_PIN    32  //32
#define LED_ON_GPIO_PIN        13  //23
#define LED_OFF_GPIO_PIN       22  //22

void LED_INIT();
void LED_LOW_MODE();
void LED_MID_MODE();
void LED_HIGH_MODE();
void LED_CUSTOM_MODE(uint32_t onTime, uint32_t offTime, uint32_t period, uint32_t power);
void LED_SCENTI_ON();
void LED_SCENTI_OFF();

#endif
