

#include "Ready_spiffs.h"

static const char *TAG = "GSPIFFS";


void spiffs_init (void){


    //"Initializing SPIFFS"
    printf("\nspiffs init\n");
    esp_vfs_spiffs_conf_t conf = {
      .base_path = "/spiffs",
      .partition_label = NULL,
      .max_files = 3,
      .format_if_mount_failed = true
    };
    
    // Use settings defined above to initialize and mount SPIFFS filesystem.
    // Note: esp_vfs_spiffs_register is an all-in-one convenience function.
    esp_err_t ret = esp_vfs_spiffs_register(&conf);
    if (ret != ESP_OK) {
        if (ret == ESP_FAIL) {
            // "Failed to mount or format filesystem"
        } else if (ret == ESP_ERR_NOT_FOUND) {
            // "Failed to find SPIFFS partition"
            printf("\nsimiProplem\n");
            perror("\nThe following error occurred");

        } else {
            //"Failed to initialize SPIFFS ""
            perror("\nThe following error occurred");
        }
        return;
    }
    
    size_t total = 0, used = 0;
    ret = esp_spiffs_info(NULL, &total, &used);
    if (ret != ESP_OK) {
        //"Failed to get SPIFFS partition information"
    } else {
        printf("Partition size: total: %d, used: %d \n", total, used);
    }
}








bool read_file(char * file_name , char *file_return_buffer,uint32_t size){
	char new_dir[30];
    snprintf(new_dir,30,"/spiffs/%s",file_name);
    //"Reading file"
    FILE* f;
    f = fopen(new_dir, "r");
    if (f == NULL) {
        //printf("Failed to open %s for reading \n",file_name);
        return false;
    }
    //fgets(file_return_buffer, sizeof(file_return_buffer), f);
    /*Reads a line from the specified stream and stores it into the string pointed to by str.
     It stops when either (n-1) characters are read,
     the newline character is read,
     or the end-of-file is reached,
     whichever comes first.*/

    
    //use this if needed to read files with has more than one line.
    fseek(f, 0, SEEK_SET);
    fread(file_return_buffer,size,1, f);
    ESP_LOGI(TAG,"read file data : %s from %s\n",file_return_buffer ,file_name);
    fclose(f);
	
 return true;
}


bool write_file(const char* file_name,char file_data[]){
	char new_dir[30];
    snprintf(new_dir,30,"/spiffs/%s",file_name);
	//"Opening file"
    FILE* f = fopen(new_dir, "w"); // w = creates file and open it for wirting and ereases it if exist
    if (f == NULL) {
        printf("\nFailed to open file for writing\n");
        return false;
    }
    ESP_LOGI(TAG,"\nwriting ....%s @ %s\n", file_data, file_name);
    fwrite(file_data,strlen(file_data)+1,1,f); // file_data string must be null terminated
    fclose(f);
    ESP_LOGI(TAG,"file closed \n");
    return true;
}


void append_file(const char* file_name,char file_data[]){
	char new_dir[30];
    snprintf(new_dir,30,"/spiffs/%s",file_name);
	//"Opening file"
    FILE* f = fopen(new_dir, "a"); // a = creates file and open it for wirting and appends it if exist
    if (f == NULL) {
        printf("\nFailed to open file for writing\n");
        return;
    }
    //printf("\nwriting ....%s @ %s\n", file_data, file_name);
    fwrite(file_data,strlen(file_data),1,f); // file_data string must be null terminated
    fclose(f);
    //printf("file closed \n");
    return;
}
