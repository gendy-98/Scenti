#ifndef _READY_SPIFFS_H_
#define _READY_SPIFFS_H_

#include <stdio.h>
#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include <math.h>
#include "esp_err.h"
#include "esp_log.h"
#include "esp_spiffs.h"


void spiffs_init (void);
bool read_file(char * file_name , char file_return_buffer[],uint32_t size);
bool write_file(const char* file_name,char file_data[]);
void append_file(const char* file_name,char file_data[]);




#endif