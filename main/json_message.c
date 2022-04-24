#include "json_message.h"


static const char *TAG = "Gjson_message";



void json_setRGBLEDS_message(char * message){

}

//{"mode":"custom","onTime":8,"offTime":8,"period":5,"power":40}
void json_intervals_message(char * message){
	cJSON * jmessage = cJSON_Parse(message);
	char* mode = cJSON_GetObjectItem(jmessage, "mode")->valuestring;
	if(!strcmp(mode,"low")){
		LED_LOW_MODE();
		diffuser(LOW_ONTIME, LOW_OFFTIME, LOW_PERIOD, LOW_POWER);

	}
	if(!strcmp(mode,"mid")){
		LED_MID_MODE();
		diffuser(MID_ONTIME, MID_OFFTIME, MID_PERIOD, MID_POWER);
	}
	if(!strcmp(mode,"high")){
		diffuser(HIGH_ONTIME, HIGH_OFFTIME, HIGH_PERIOD, HIGH_POWER);
		LED_HIGH_MODE();
	}
	if(!strcmp(mode,"custom")){

		int onTime = cJSON_GetObjectItem(jmessage, "onTime")->valueint;
		int offTime = cJSON_GetObjectItem(jmessage, "offTime")->valueint;
		int period = cJSON_GetObjectItem(jmessage, "period")->valueint * 60 * 60;
		int power = cJSON_GetObjectItem(jmessage, "power")->valueint;

		ESP_LOGW(TAG,"App Power:%d",power);
		LED_CUSTOM_MODE(onTime, offTime, period, power);
		diffuser(onTime, offTime, period, power);
	}
}

//{"ssid":"data","password":"01114573"}
void json_wifiConfig_message(char * message){
	cJSON * jmessage = cJSON_Parse(message);
	char* ssid = cJSON_GetObjectItem(jmessage, "ssid")->valuestring;
	char* password = cJSON_GetObjectItem(jmessage, "password")->valuestring;
	write_file("ssid", ssid);
	write_file("pw", password);
    Wifi_ConnectToAp(ssid, password);

}



//{"type":"ipConfig","ip":"http://192.168.4.1"}
char * json_getIp_message(){

	char ip[32] = {0};
	read_file("ip", ip, 32);
	cJSON * jresponse = cJSON_CreateObject();
	cJSON_AddStringToObject(jresponse, "type", "ipConfig");
	cJSON_AddStringToObject(jresponse, "ip", ip);
	return cJSON_PrintUnformatted(jresponse);
}

//{"type":"response","success":true,"message":"7kayte"}
char * json_response(uint8_t success,char * message) {

	cJSON * jresponse = cJSON_CreateObject();


	cJSON_AddStringToObject(jresponse, "type", "response");
	if (success)
		cJSON_AddBoolToObject(jresponse, "success", 1);
	else
		cJSON_AddBoolToObject(jresponse, "success", 0);


	cJSON_AddStringToObject(jresponse, "message", message);



	return cJSON_PrintUnformatted(jresponse);
}

