#ifndef _HTTP_SERVER_H_
#define _HTTP_SERVER_H_



#include "http_handel.h"





httpd_handle_t start_webserver(void);


void stop_webserver(httpd_handle_t server);

void disconnect_handler(void* arg, esp_event_base_t event_base,
                               int32_t event_id, void* event_data);

void connect_handler(void* arg, esp_event_base_t event_base,
                            int32_t event_id, void* event_data);
#endif