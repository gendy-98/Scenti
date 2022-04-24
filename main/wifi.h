#ifndef _WIFI_H_
#define _WIFI_H_


#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "esp_log.h"
#include "esp_event.h"
#include "nvs_flash.h"


#include "wifi_helper.h"


esp_err_t Wifi_EventHandler(void *ctx, system_event_t *event);
void Wifi_ConnectToAp(char * ssid, char * password);
void Wifi_Init();
void wifi_scan(void);
void Wifi_InitAccessPoint(char * ssid, char * password);
void Wifi_StaConnectedHandler(void* arg, esp_event_base_t event_base,
                            int32_t event_id, void* event_data);
void Wifi_InitAP();
void Wifi_Start(wifi_mode_t mode);
void Wifi_InitSTA();

#endif
