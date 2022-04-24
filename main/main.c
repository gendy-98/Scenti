


#include "http_handel.h"
#include "http_server.h"


#include "wifi_helper.h"
#include "wifi.h"


#include "esp_enum_helper.h"
#include "Ready_spiffs.h"
#include "PWM.h"
#include "json_message.h"
#include "LED.h"

/* A simple example that demonstrates how to create GET and POST
 * handlers for the web server.
 */

static const char *TAG = "Gmain";

/*

extern const httpd_uri_t hello;
extern const httpd_uri_t ctrl;
extern const httpd_uri_t echo;

*/

void general_event_handler(void* arg, esp_event_base_t event_base,
                            int32_t event_id, void* event_data)
{
	ESP_LOGW(TAG, "Event Base:%s, Event ID:%s",event_base, esp_enum_to_name(event_base, event_id));

}


#define STA_SSID "data\0"
#define STA_PASS "01147944302@ah\0"

#define AP_SSID "ESP_gendy\0"
#define AP_PASS "123456789\0"
void app_main(void)
{


	PWM_init();
	PWM_set(0);
	spiffs_init ();
	LED_INIT();
	LED_SCENTI_OFF();
	//vTaskDelay(100000);
    ESP_LOGI(TAG, "###########Start MAin###########\n");

    ESP_LOGI(TAG, "IP int: %lld",(uint64_t)Wifi_IPtoI((uint64_t)192, 168, 4, 1));
    char sta_ssid[64];
    char sta_pass[64];

    wifi_mode_t mode = WIFI_MODE_APSTA;
    Wifi_Init();
    Wifi_InitAP();
    Wifi_InitSTA();
    Wifi_Start(mode);

    memset(sta_ssid, 0, 64);
    memset(sta_pass, 0, 64);




    esp_wifi_start();

    Wifi_InitAccessPoint(AP_SSID, AP_PASS);


	ESP_ERROR_CHECK(esp_event_handler_instance_register(ESP_EVENT_ANY_BASE, ESP_EVENT_ANY_ID, &general_event_handler, NULL, NULL));
	ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT, WIFI_EVENT_STA_CONNECTED, &Wifi_StaConnectedHandler, NULL, NULL));
	ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &connect_handler, NULL, NULL));

	 if (read_file("ssid", sta_ssid, 64)){
	    	if(read_file("pw", sta_pass, 64)){
	    	    Wifi_ConnectToAp(sta_ssid, sta_pass);
	    	}
	    }

	//ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT, WIFI_EVENT_STA_DISCONNECTED, &disconnect_handler, &server, NULL));

	//xTaskCreate(deffuser_task, pcName, usStackDepth, pvParameters, uxPriority, pvCreatedTask)
	//xTaskCreate(diusser, pcName, usStackDepth, pvParameters, uxPriority, pvCreatedTask)

	xTaskCreate(diffuser_task, "diffuser", 8000, NULL, 15, NULL);
    start_webserver();
}
