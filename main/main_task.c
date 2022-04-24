#include "main_task.h"

static const char *TAG = "Gmain_task";






uint8_t diffuser_state = 0;
uint32_t diffuser_onTime;
uint32_t diffuser_offTime;
uint32_t diffuser_period;
uint32_t diffuser_power;

void diffuser(uint32_t onTime, uint32_t offTime, uint32_t period, uint32_t power)
{
	diffuser_state ++;

	diffuser_onTime = onTime;
	diffuser_offTime = offTime;
	diffuser_period = period;
	diffuser_power = power;
}


void diffuser_task()
{

	PWM_init();
	ESP_LOGW(TAG, "task..");
	uint32_t i;
	uint32_t totaltime = 0;
	uint32_t local_diffuser_state = diffuser_state;
	while(1)
	{

		if(diffuser_state ){
			local_diffuser_state = diffuser_state;
			ESP_LOGW(TAG, "power %d",diffuser_power);
			PWM_set(diffuser_power);

			for (i = 0; i < diffuser_onTime*2; i++){
				totaltime ++;
				vTaskDelay(500/portTICK_PERIOD_MS);
				if (diffuser_state != local_diffuser_state)
					break;
			}

			PWM_set(0);
			for (i = 0; i < diffuser_offTime*2; i++){
				totaltime ++;
				vTaskDelay(500/portTICK_PERIOD_MS);
				if (diffuser_state != local_diffuser_state )
					break;
			}

			if (totaltime >= diffuser_period*2){
				diffuser_state = 0;

			}
			if (diffuser_state != local_diffuser_state )
				totaltime = 0;
		}
		else{
			vTaskDelay(1000/portTICK_PERIOD_MS);
		}



	}
}
