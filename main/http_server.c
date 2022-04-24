#include "http_server.h"

extern const httpd_uri_t setRGBLEDS;
extern const httpd_uri_t motionSensor;
extern const httpd_uri_t intervals;
extern const httpd_uri_t oil;
extern const httpd_uri_t wifiConfig;
extern const httpd_uri_t getIp;



static const char *TAG = "Ghttp_server";

httpd_handle_t start_webserver(void)
{
    httpd_handle_t server = NULL;
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    config.lru_purge_enable = true;


    // Start the httpd server
    ESP_LOGI(TAG, "Starting server on port: '%d'", config.server_port);
    if (httpd_start(&server, &config) == ESP_OK) {
        // Set URI handlers
        ESP_LOGI(TAG, "Registering URI handlers");
        httpd_register_uri_handler(server, &setRGBLEDS);
        httpd_register_uri_handler(server, &motionSensor);
        httpd_register_uri_handler(server, &intervals);
        httpd_register_uri_handler(server, &oil);
        httpd_register_uri_handler(server, &wifiConfig);
        httpd_register_uri_handler(server, &getIp);
        return server;
    }

    ESP_LOGI(TAG, "Error starting server!");
    return NULL;
}

void stop_webserver(httpd_handle_t server)
{
    // Stop the httpd server
    httpd_stop(server);
}

void disconnect_handler(void* arg, esp_event_base_t event_base,
                               int32_t event_id, void* event_data)
{

    httpd_handle_t* server = (httpd_handle_t*) arg;
    if (*server) {
        ESP_LOGI(TAG, "Stopping web server");
        stop_webserver(*server);
        *server = NULL;
    }
}

void connect_handler(void* arg, esp_event_base_t event_base,
                            int32_t event_id, void* event_data)
{

	ESP_LOGE(TAG, "we are here\n");
	system_event_info_t* info = (system_event_info_t*) event_data;
	char message[32];
	char * ip = Wifi_PrintIPString(info->got_ip.ip_info.ip.addr);
	strcpy(message, ip);

	ESP_LOGE(TAG, "message: %s\n", message);

	write_file("ip", message);

	char test[32] = {0};

	read_file("ip", test, 32);

	ESP_LOGE(TAG, "test: %s\n", test);
	LED_SCENTI_ON();
}



