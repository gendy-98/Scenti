#ifndef _ESP_ENUM_HELPER_H_
#define _ESP_ENUM_HELPER_H_

#include "esp_event.h"
#include "string.h"

char* esp_enum_to_name(esp_event_base_t event_base, int32_t event_id);
#endif
