#ifndef _WIFI_HELPER_H_
#define _WIFI_HELPER_H_



#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "esp_log.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "json_message.h"
#include "Ready_spiffs.h"



uint64_t Wifi_IPtoI(uint64_t ip1, uint32_t ip2, uint16_t ip3, uint16_t ip4);
void Wifi_Show_Station_Disconnected_Info(system_event_info_t info);
void Wifi_Show_Station_Got_IP_Info(system_event_info_t info);
void Wifi_Show_Station_Connected_Info(system_event_info_t info);
char * Wifi_GetAuthModeName(wifi_auth_mode_t authMode);
void Wifi_PrintEventName(system_event_id_t event);
char * Wifi_PrintIPString(uint32_t ip);
char * Wifi_ConvertMacToString(uint8_t Mac[]);
char * Wifi_GetReasonName(uint8_t reason);
void print_auth_mode(int authmode);
void print_cipher_type(int pairwise_cipher, int group_cipher);



#endif
