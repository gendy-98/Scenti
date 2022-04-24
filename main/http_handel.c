#include "http_handel.h"



static const char *TAG = "Ghttp_handel";



const httpd_uri_t setRGBLEDS = {
    .uri       = "/setRGBLEDS",
    .method    = HTTP_POST,
    .handler   = setRGBLEDS_post_handler,
    .user_ctx  = NULL
};


const httpd_uri_t motionSensor = {
    .uri       = "/motionSensor",
    .method    = HTTP_POST,
    .handler   = motionSensor_post_handler,
    .user_ctx  = NULL
};

const httpd_uri_t intervals = {
    .uri       = "/intervals",
    .method    = HTTP_POST,
    .handler   = intervals_post_handler,
    .user_ctx  = NULL
};

const httpd_uri_t oil = {
    .uri       = "/oil",
    .method    = HTTP_GET,
    .handler   = oil_get_handler,
    .user_ctx  = NULL
};
const httpd_uri_t wifiConfig = {
    .uri       = "/wifiConfig",
    .method    = HTTP_POST,
    .handler   = wifiConfig_post_handler,
    .user_ctx  = NULL
};
const httpd_uri_t getIp = {
    .uri       = "/getIp",
    .method    = HTTP_GET,
    .handler   = getIp_get_handler,
    .user_ctx  = NULL
};

esp_err_t setRGBLEDS_post_handler(httpd_req_t *req)
{
	ESP_LOGW(TAG,"Some one called URI:%s",req->uri);
	char message[256];
	memset(message,0,256);
	httpd_req_recv(req, message, 256);

	message[strlen(message)] = 0;

	ESP_LOGW(TAG,"Message body:%s",message);

	char responseMessage[] = "{\"type\":\"response\",\"success\":true,\"message\":\"7kayte\"}";
	httpd_resp_send(req, responseMessage, strlen(responseMessage));
	return ESP_OK;
}


/* An HTTP GET handler */
esp_err_t motionSensor_post_handler(httpd_req_t *req)
{
	char responseMessage[] = "{\"type\":\"response\",\"success\":true,\"message\":\"7kayte\"}";
	httpd_resp_send(req, responseMessage, strlen(responseMessage));

    return ESP_OK;
}

esp_err_t intervals_post_handler(httpd_req_t *req)
{
	ESP_LOGW(TAG,"Some one called URI:%s",req->uri);
	char message[256];
	memset(message,0,256);
	httpd_req_recv(req, message, 256);

	message[strlen(message)] = 0;
	json_intervals_message(message);

	char * responseMessage = json_response(true, "7kytnaaa");
	httpd_resp_send(req, responseMessage, strlen(responseMessage));
    return ESP_OK;
}

esp_err_t oil_get_handler(httpd_req_t *req)
{

	ESP_LOGW(TAG,"Some one called URI:%s",req->uri);

	char responseMessage[] = "{\"type\":\"oil\",\"percentage\":60,\"lifetime\":500}\0";
	httpd_resp_set_type(req, "application/json");
	httpd_resp_send(req, responseMessage, strlen(responseMessage));

    return ESP_OK;
}

/* An HTTP POST handler */
esp_err_t wifiConfig_post_handler(httpd_req_t *req)
{
	ESP_LOGW(TAG,"Some one called URI:%s",req->uri);
	char message[256];
	memset(message,0,256);
	httpd_req_recv(req, message, 256);

	message[strlen(message)] = 0;

	json_wifiConfig_message(message);




	//char responseMessage[] = "{\"type\":\"response\",\"success\":true,\"message\":\"7kayte\"}\n";

	httpd_resp_set_type(req, "application/json; charset=UTF-8");


	char * responseMessage = json_response(true, "7kythom");
	ESP_LOGW(TAG,"responseMessage body:%s\n length %d ",responseMessage,strlen(responseMessage));
	httpd_resp_send(req, responseMessage, strlen(responseMessage));
    return ESP_OK;
}



esp_err_t getIp_get_handler(httpd_req_t *req)
{

	char *responseMessage = json_getIp_message();
	httpd_resp_set_type(req, "application/json");
	ESP_LOGW(TAG,"responseMessage body:%s\n length %d ",responseMessage,strlen(responseMessage));

	httpd_resp_send(req, responseMessage, strlen(responseMessage));
    return ESP_OK;
}

esp_err_t http_404_error_handler(httpd_req_t *req, httpd_err_code_t err)
{

    if (strcmp("/hello", req->uri) == 0) {
        httpd_resp_send_err(req, HTTPD_404_NOT_FOUND, "/hello URI is not available");
        /* Return ESP_OK to keep underlying socket open */
        return ESP_OK;
    } else if (strcmp("/echo", req->uri) == 0) {
        httpd_resp_send_err(req, HTTPD_404_NOT_FOUND, "/echo URI is not available");
        /* Return ESP_FAIL to close underlying socket */
        return ESP_FAIL;
    }
    /* For any other URI send 404 and close socket */
    httpd_resp_send_err(req, HTTPD_404_NOT_FOUND, "Some 404 error message");
    return ESP_FAIL;
}

