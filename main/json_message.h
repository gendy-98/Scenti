#ifndef _JSON_MESSAGE_H_
#define _JSON_MESSAGE_H_


#include <esp_wifi.h>
#include <esp_event.h>
#include <esp_log.h>
#include <esp_system.h>
#include <nvs_flash.h>
#include <sys/param.h>
#include "nvs_flash.h"
#include "esp_netif.h"
#include "esp_eth.h"
#include "protocol_examples_common.h"

#include <esp_http_server.h>

#include "cJson.h"
#include "main_task.h"

#include "wifi.h"
#include "Ready_spiffs.h"


#define LOW_ONTIME 60
#define LOW_OFFTIME 300
#define LOW_PERIOD (1 * 60 * 60)
#define LOW_POWER 70


#define MID_ONTIME 60
#define MID_OFFTIME 60
#define MID_PERIOD (2 * 60 * 60)
#define MID_POWER 85


#define HIGH_ONTIME 60
#define HIGH_OFFTIME 30
#define HIGH_PERIOD (4 * 60 * 60)
#define HIGH_POWER 100

char * json_response(uint8_t success,char * message);
void json_wifiConfig_message(char * message);
void json_intervals_message(char * message);
void json_setIp(char * message);
char * json_getIp_message();

#endif
