#ifndef _HTTP_HANDEL_H_
#define _HTTP_HANDEL_H_



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
#include "PWM.h"

#include "json_message.h"

/* An HTTP GET handler */

esp_err_t setRGBLEDS_post_handler(httpd_req_t *req);
esp_err_t motionSensor_post_handler(httpd_req_t *req);
esp_err_t intervals_post_handler(httpd_req_t *req);
esp_err_t oil_get_handler(httpd_req_t *req);
esp_err_t wifiConfig_post_handler(httpd_req_t *req);
esp_err_t getIp_get_handler(httpd_req_t *req);

esp_err_t http_404_error_handler(httpd_req_t *req, httpd_err_code_t err);


#endif
