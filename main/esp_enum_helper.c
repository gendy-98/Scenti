#include"esp_enum_helper.h"





char* esp_enum_to_name(esp_event_base_t event_base, int32_t event_id)
{

	char* retval;
	int32_t eventval = -1;
	if (!strcmp(IP_EVENT, event_base))
		eventval = 0;
	else if (!strcmp(WIFI_EVENT, event_base))
		eventval = 1;


	const char* ip_event_name[] = {
				    "IP_EVENT_STA_GOT_IP",               /*!< station got IP from connected AP */
				    "IP_EVENT_STA_LOST_IP",              /*!< station lost IP and the IP is reset to 0 */
				    "IP_EVENT_AP_STAIPASSIGNED",         /*!< soft-AP assign an IP to a connected station */
				    "IP_EVENT_GOT_IP6",                  /*!< station or ap or ethernet interface v6IP addr is preferred */
				    "IP_EVENT_ETH_GOT_IP",               /*!< ethernet got IP from connected AP */
				    "IP_EVENT_PPP_GOT_IP",               /*!< PPP interface got IP */
				    "IP_EVENT_PPP_LOST_IP",              /*!< PPP interface lost IP */
				};
	const char* wifi_event_name[] = {
				"WIFI_EVENT_WIFI_READY",           /**< ESP32 WiFi ready */
				"WIFI_EVENT_SCAN_DONE",                /**< ESP32 finish scanning AP */
				"WIFI_EVENT_STA_START",                /**< ESP32 station start */
				"WIFI_EVENT_STA_STOP",                 /**< ESP32 station stop */
				"WIFI_EVENT_STA_CONNECTED",            /**< ESP32 station connected to AP */
				"WIFI_EVENT_STA_DISCONNECTED",         /**< ESP32 station disconnected from AP */
				"WIFI_EVENT_STA_AUTHMODE_CHANGE",      /**< the auth mode of AP connected by ESP32 station changed */

				"WIFI_EVENT_STA_WPS_ER_SUCCESS",       /**< ESP32 station wps succeeds in enrollee mode */
				"WIFI_EVENT_STA_WPS_ER_FAILED",        /**< ESP32 station wps fails in enrollee mode */
				"WIFI_EVENT_STA_WPS_ER_TIMEOUT",       /**< ESP32 station wps timeout in enrollee mode */
				"WIFI_EVENT_STA_WPS_ER_PIN",           /**< ESP32 station wps pin code in enrollee mode */
				"WIFI_EVENT_STA_WPS_ER_PBC_OVERLAP",   /**< ESP32 station wps overlap in enrollee mode */

				"WIFI_EVENT_AP_START",                 /**< ESP32 soft-AP start */
				"WIFI_EVENT_AP_STOP",                  /**< ESP32 soft-AP stop */
				"WIFI_EVENT_AP_STACONNECTED",          /**< a station connected to ESP32 soft-AP */
				"WIFI_EVENT_AP_STADISCONNECTED",       /**< a station disconnected from ESP32 soft-AP */
				"WIFI_EVENT_AP_PROBEREQRECVED",        /**< Receive probe request packet in soft-AP interface */

				"WIFI_EVENT_FTM_REPORT",               /**< Receive report of FTM procedure */

				/* Add next events after this only */
				"WIFI_EVENT_STA_BSS_RSSI_LOW",         /**< AP's RSSI crossed configured threshold */
				"WIFI_EVENT_ACTION_TX_STATUS",         /**< Status indication of Action Tx operation */
				"WIFI_EVENT_ROC_DONE",                 /**< Remain-on-Channel operation complete */

				"WIFI_EVENT_STA_BEACON_TIMEOUT",       /**< ESP32 station beacon timeout */

				"WIFI_EVENT_MAX"                      /**< Invalid WiFi event ID */
			};
	switch(eventval)
		{
		case 0://IP_EVENT:
			retval = ip_event_name[event_id];
			break;
		case 1://WIFI_EVENT:
			retval = wifi_event_name[event_id];
			break;
		default:

			return event_base;
		}

	return retval;


}
