#include "LED.h"
static const char *TAG = "GLED";


void LED_INIT(){
    
	ESP_LOGW(TAG, "LED init 21");

    gpio_reset_pin(LED_LOW_T_GPIO_PIN);
    gpio_set_direction(LED_LOW_T_GPIO_PIN,    GPIO_MODE_OUTPUT);

    ESP_LOGW(TAG, "LED init mid");
    gpio_reset_pin(LED_MID_T_GPIO_PIN);
    gpio_set_direction(LED_MID_T_GPIO_PIN,    GPIO_MODE_OUTPUT);

    ESP_LOGW(TAG, "LED init high");
    gpio_reset_pin(LED_HIGH_T_GPIO_PIN);
    gpio_set_direction(LED_HIGH_T_GPIO_PIN,   GPIO_MODE_OUTPUT);

    ESP_LOGW(TAG, "LED init low p");
    gpio_reset_pin(LED_LOW_P_GPIO_PIN);
    gpio_set_direction(LED_LOW_P_GPIO_PIN,    GPIO_MODE_OUTPUT);

    ESP_LOGW(TAG, "LED init kfaya");
    gpio_reset_pin(LED_MID_P_GPIO_PIN);
    gpio_set_direction(LED_MID_P_GPIO_PIN,    GPIO_MODE_OUTPUT);

    gpio_reset_pin(LED_HIGH_P_GPIO_PIN);
    gpio_set_direction(LED_HIGH_P_GPIO_PIN,   GPIO_MODE_OUTPUT);

    gpio_reset_pin(LED_ON_GPIO_PIN);
    gpio_set_direction(LED_ON_GPIO_PIN,       GPIO_MODE_OUTPUT);

    gpio_reset_pin(LED_OFF_GPIO_PIN);
    gpio_set_direction(LED_OFF_GPIO_PIN,      GPIO_MODE_OUTPUT);

    gpio_reset_pin(LED_CUSTOM_T_GPIO_PIN);
    gpio_set_direction(LED_CUSTOM_T_GPIO_PIN, GPIO_MODE_OUTPUT);
}

void LED_LOW_MODE(){
    
    gpio_set_level(LED_LOW_T_GPIO_PIN,    1);
    gpio_set_level(LED_MID_T_GPIO_PIN,    0);
    gpio_set_level(LED_HIGH_T_GPIO_PIN,   0);
    gpio_set_level(LED_CUSTOM_T_GPIO_PIN, 0);
    gpio_set_level(LED_LOW_P_GPIO_PIN,    1);
    gpio_set_level(LED_MID_P_GPIO_PIN,    0);
    gpio_set_level(LED_HIGH_P_GPIO_PIN,   0);
}

void LED_MID_MODE(){
    
    gpio_set_level(LED_LOW_T_GPIO_PIN,    0);
    gpio_set_level(LED_MID_T_GPIO_PIN,    1);
    gpio_set_level(LED_HIGH_T_GPIO_PIN,   0);
    gpio_set_level(LED_CUSTOM_T_GPIO_PIN, 0);
    gpio_set_level(LED_LOW_P_GPIO_PIN,    0);
    gpio_set_level(LED_MID_P_GPIO_PIN,    1);
    gpio_set_level(LED_HIGH_P_GPIO_PIN,   0);
}

void LED_HIGH_MODE(){
    
    gpio_set_level(LED_LOW_T_GPIO_PIN,    0);
    gpio_set_level(LED_MID_T_GPIO_PIN,    0);
    gpio_set_level(LED_HIGH_T_GPIO_PIN,   1);
    gpio_set_level(LED_CUSTOM_T_GPIO_PIN, 0);
    gpio_set_level(LED_LOW_P_GPIO_PIN,    0);
    gpio_set_level(LED_MID_P_GPIO_PIN,    0);
    gpio_set_level(LED_HIGH_P_GPIO_PIN,   1);
}

void LED_CUSTOM_MODE(uint32_t onTime, uint32_t offTime, uint32_t period, uint32_t power)
{
    
	if (onTime == LOW_ONTIME && offTime == LOW_OFFTIME)
	{
		gpio_set_level(LED_LOW_P_GPIO_PIN,    1);
		gpio_set_level(LED_MID_P_GPIO_PIN,    0);
		gpio_set_level(LED_HIGH_P_GPIO_PIN,   0);
	}
	else if (onTime == MID_ONTIME && offTime == MID_OFFTIME)
	{
		gpio_set_level(LED_LOW_P_GPIO_PIN,    0);
		gpio_set_level(LED_MID_P_GPIO_PIN,    1);
		gpio_set_level(LED_HIGH_P_GPIO_PIN,   0);
	}
	else if (onTime == HIGH_ONTIME && offTime == HIGH_OFFTIME)
	{
		gpio_set_level(LED_LOW_P_GPIO_PIN,    0);
		gpio_set_level(LED_MID_P_GPIO_PIN,    0);
		gpio_set_level(LED_HIGH_P_GPIO_PIN,   1);
	}
	else
	{
		gpio_set_level(LED_LOW_P_GPIO_PIN,    0);
		gpio_set_level(LED_MID_P_GPIO_PIN,    0);
		gpio_set_level(LED_HIGH_P_GPIO_PIN,   0);
	}

	if (period == LOW_PERIOD){
		gpio_set_level(LED_LOW_T_GPIO_PIN,    1);
		gpio_set_level(LED_MID_T_GPIO_PIN,    0);
		gpio_set_level(LED_HIGH_T_GPIO_PIN,   0);
		gpio_set_level(LED_CUSTOM_T_GPIO_PIN, 0);
	}
	else if (period == MID_PERIOD){
		gpio_set_level(LED_LOW_T_GPIO_PIN,    0);
		gpio_set_level(LED_MID_T_GPIO_PIN,    1);
		gpio_set_level(LED_HIGH_T_GPIO_PIN,   0);
		gpio_set_level(LED_CUSTOM_T_GPIO_PIN, 0);
	}
	else if (period == HIGH_PERIOD){
		gpio_set_level(LED_LOW_T_GPIO_PIN,    0);
		gpio_set_level(LED_MID_T_GPIO_PIN,    0);
		gpio_set_level(LED_HIGH_T_GPIO_PIN,   1);
		gpio_set_level(LED_CUSTOM_T_GPIO_PIN, 0);
	}
	else if (period == (8 * 60 * 60)){
		gpio_set_level(LED_LOW_T_GPIO_PIN,    0);
		gpio_set_level(LED_MID_T_GPIO_PIN,    0);
		gpio_set_level(LED_HIGH_T_GPIO_PIN,   0);
		gpio_set_level(LED_CUSTOM_T_GPIO_PIN, 1);
	}
	else
	{
		gpio_set_level(LED_LOW_T_GPIO_PIN,    0);
		gpio_set_level(LED_MID_T_GPIO_PIN,    0);
		gpio_set_level(LED_HIGH_T_GPIO_PIN,   0);
		gpio_set_level(LED_CUSTOM_T_GPIO_PIN, 0);
	}

}

void LED_SCENTI_ON(){
    
    gpio_set_level(LED_ON_GPIO_PIN,       1);
    gpio_set_level(LED_OFF_GPIO_PIN,      0);
}

void LED_SCENTI_OFF(){
    
    gpio_set_level(LED_ON_GPIO_PIN,       0);
    gpio_set_level(LED_OFF_GPIO_PIN,      1);
}


