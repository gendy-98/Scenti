#include "PWM.h"

static const char *TAG = "GPWM";
void PWM_init()
{
    
    ESP_LOGW(TAG, ">> task_motor_speed");
    ledc_timer_config_t timer_conf;
    timer_conf.duty_resolution  	= LEDC_TIMER_15_BIT;
    timer_conf.freq_hz    	= 500;
    timer_conf.speed_mode 	= LEDC_HIGH_SPEED_MODE;
    timer_conf.timer_num  	= LEDC_TIMER_0;
    timer_conf.clk_cfg 		= LEDC_AUTO_CLK;
    ledc_timer_config(&timer_conf);

    
    ledc_channel_config_t ledc_conf;
    ledc_conf.channel     	= LEDC_CHANNEL_0;
    ledc_conf.duty        	= 3000;
    ledc_conf.gpio_num    	= PWM_GPIO_PIN;
    ledc_conf.intr_type   	= LEDC_INTR_DISABLE;
    ledc_conf.speed_mode  	= LEDC_HIGH_SPEED_MODE;
    ledc_conf.timer_sel   	= LEDC_TIMER_0;
    ledc_conf.hpoint 		= 0;
    ledc_channel_config(&ledc_conf);


}

void PWM_set(uint32_t duty)
{
	uint32_t maxValue = 1<<LEDC_TIMER_15_BIT;
	ESP_LOGW(TAG, "Percentage: %d",duty);
	uint32_t real_duty;
	real_duty = (duty*maxValue)/100;
	ESP_LOGW(TAG, "real num: %d",real_duty);
	ledc_set_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0, real_duty);
	ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0);
}
