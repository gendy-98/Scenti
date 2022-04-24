

#include "wifi.h"

#define DEFAULT_SCAN_LIST_SIZE 20

static const char *TAG = "Gwifi";


esp_err_t Wifi_EventHandler(void *ctx, system_event_t *event)
{

	Wifi_PrintEventName(event->event_id);

	switch(event->event_id)
	{
	case SYSTEM_EVENT_STA_START:
		break;
	default :
		break;

	}
	return ESP_OK;
}

void Wifi_ConnectToAp(char * ssid, char * password)
{
	esp_err_t ret;
    ESP_LOGI(TAG, "Connecting to ssid: %s, pass: %s", ssid, password);
    ret = esp_wifi_disconnect();
    ESP_LOGI(TAG, "disconnecting ...");
    while (ret != ESP_OK){
    	vTaskDelay(1/portTICK_PERIOD_MS);
    	ESP_LOGI(TAG, "failed bec. %s",esp_err_to_name(ret));
    	ret = esp_wifi_disconnect();



    }
	wifi_config_t STA_Config = {0};

	strcpy((char *)STA_Config.sta.ssid, ssid);
	strcpy((char *)STA_Config.sta.password, password);

	esp_wifi_set_config(ESP_IF_WIFI_STA, &STA_Config);


	ret = esp_wifi_connect();
	    ESP_LOGI(TAG, "connecting ...");
	    while (ret != ESP_OK){
	    	vTaskDelay(1/portTICK_PERIOD_MS);
	    	ESP_LOGI(TAG, "failed bec. %s",esp_err_to_name(ret));
	    	ret = esp_wifi_connect();



	    }

}


void Wifi_StaConnectedHandler(void* arg, esp_event_base_t event_base,
                            int32_t event_id, void* event_data)
{
	system_event_info_t* info = (system_event_info_t*) event_data;
	Wifi_Show_Station_Connected_Info(*info);
}



void Wifi_Init()
{

	/* Initialize NVS Flash */
	ESP_ERROR_CHECK(nvs_flash_init());

	/* Initialize TCP/IP Stack */
	ESP_ERROR_CHECK(esp_netif_init());

	/* Register Wi-fi Event Handler */
	ESP_ERROR_CHECK(esp_event_loop_create_default());
}

void Wifi_InitSTA()
{

	esp_netif_t *sta_netif = esp_netif_create_default_wifi_sta();
	assert(sta_netif);

}

void Wifi_Start(wifi_mode_t mode)
{
	wifi_init_config_t wifi_init_config = WIFI_INIT_CONFIG_DEFAULT();

	/* Initialize WI-FI Module */
	ESP_ERROR_CHECK(esp_wifi_init(&wifi_init_config));

	/* Set Wi-fi Mode */
	ESP_ERROR_CHECK(esp_wifi_set_mode(mode));
}

void Wifi_InitAP()
{

	/*
	esp_netif_config->ip_info->ip = Wifi_IPtoI(192,168,100,1);
	esp_netif_config->ip_info->gw = Wifi_IPtoI(192,168,100,1);
	esp_netif_config->ip_info->netmask = Wifi_IPtoI(255,255,255,0);
		*/
	esp_netif_t *ap_netif = esp_netif_create_default_wifi_ap();
	assert(ap_netif);


}


void wifi_scan(void)
{
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    esp_netif_t *sta_netif = esp_netif_create_default_wifi_sta();
    assert(sta_netif);

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    uint16_t number = DEFAULT_SCAN_LIST_SIZE;
    wifi_ap_record_t ap_info[DEFAULT_SCAN_LIST_SIZE];
    uint16_t ap_count = 0;
    memset(ap_info, 0, sizeof(ap_info));

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_start());
    esp_wifi_scan_start(NULL, true);
    ESP_ERROR_CHECK(esp_wifi_scan_get_ap_records(&number, ap_info));
    ESP_ERROR_CHECK(esp_wifi_scan_get_ap_num(&ap_count));
    ESP_LOGI(TAG, "Total APs scanned = %u", ap_count);
    for (int i = 0; (i < DEFAULT_SCAN_LIST_SIZE) && (i < ap_count); i++) {
        ESP_LOGI(TAG, "SSID \t\t%s", ap_info[i].ssid);
        ESP_LOGI(TAG, "RSSI \t\t%d", ap_info[i].rssi);
        print_auth_mode(ap_info[i].authmode);
        if (ap_info[i].authmode != WIFI_AUTH_WEP) {
            print_cipher_type(ap_info[i].pairwise_cipher, ap_info[i].group_cipher);
        }
        ESP_LOGI(TAG, "Channel \t\t%d\n", ap_info[i].primary);
    }

}



void Wifi_InitAccessPoint(char * ssid, char * password)
{
	wifi_config_t AP_Config = {0};

	strcpy((char *)AP_Config.ap.ssid, ssid);
	strcpy((char *)AP_Config.ap.password, password);
	AP_Config.ap.ssid_len = strlen(ssid);
	AP_Config.ap.authmode = WIFI_AUTH_WPA2_PSK;
	AP_Config.ap.ssid_hidden = 0;
	AP_Config.ap.max_connection=5;


	esp_wifi_set_config(ESP_IF_WIFI_AP, &AP_Config);
}

