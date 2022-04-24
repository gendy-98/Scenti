
#include"wifi_helper.h"


static const char *TAG = "Gwifi_helper";


void Wifi_Show_Station_Disconnected_Info(system_event_info_t info)
{
	printf("Event : SYSTEM_EVENT_STA_DISCONNECTED\n");
	printf("Disconnected From AP SSID: %s\n",info.disconnected.ssid);
	printf("SSID Length: %d\n",info.disconnected.ssid_len);
	printf("MAC Address: %s \n",Wifi_ConvertMacToString(info.disconnected.bssid));
	printf("Disconnection Reason : %s\n",Wifi_GetReasonName(info.disconnected.reason));
}


void Wifi_Show_Station_Got_IP_Info(system_event_info_t info)
{
	printf("IP : ");
	Wifi_PrintIPString(info.got_ip.ip_info.ip.addr);
	printf("\n");

	printf("Netmask : ");
	Wifi_PrintIPString(info.got_ip.ip_info.netmask.addr);
	printf("\n");

	printf("Gateway : ");
	Wifi_PrintIPString(info.got_ip.ip_info.gw.addr);
	printf("\n");

}

void Wifi_Show_Station_Connected_Info(system_event_info_t info)
{
	printf("Station Connected AP SSID: %s\n",info.connected.ssid);
	printf("SSID Length: %d\n",info.connected.ssid_len);
	printf("MAC Address: %02X:%02X:%02X:%02X:%02X:%02X\n",info.connected.bssid[0],
			info.connected.bssid[1],info.connected.bssid[2],
			info.connected.bssid[3],info.connected.bssid[4],
			info.connected.bssid[5]);
	printf("Channel : %d\n",info.connected.channel);
	printf("Authentication Mode : %s\n",Wifi_GetAuthModeName(info.connected.authmode));


}


void print_auth_mode(int authmode)
{
    switch (authmode) {
    case WIFI_AUTH_OPEN:
        ESP_LOGI(TAG, "Authmode \tWIFI_AUTH_OPEN");
        break;
    case WIFI_AUTH_WEP:
        ESP_LOGI(TAG, "Authmode \tWIFI_AUTH_WEP");
        break;
    case WIFI_AUTH_WPA_PSK:
        ESP_LOGI(TAG, "Authmode \tWIFI_AUTH_WPA_PSK");
        break;
    case WIFI_AUTH_WPA2_PSK:
        ESP_LOGI(TAG, "Authmode \tWIFI_AUTH_WPA2_PSK");
        break;
    case WIFI_AUTH_WPA_WPA2_PSK:
        ESP_LOGI(TAG, "Authmode \tWIFI_AUTH_WPA_WPA2_PSK");
        break;
    case WIFI_AUTH_WPA2_ENTERPRISE:
        ESP_LOGI(TAG, "Authmode \tWIFI_AUTH_WPA2_ENTERPRISE");
        break;
    case WIFI_AUTH_WPA3_PSK:
        ESP_LOGI(TAG, "Authmode \tWIFI_AUTH_WPA3_PSK");
        break;
    case WIFI_AUTH_WPA2_WPA3_PSK:
        ESP_LOGI(TAG, "Authmode \tWIFI_AUTH_WPA2_WPA3_PSK");
        break;
    default:
        ESP_LOGI(TAG, "Authmode \tWIFI_AUTH_UNKNOWN");
        break;
    }
}

void print_cipher_type(int pairwise_cipher, int group_cipher)
{
    switch (pairwise_cipher) {
    case WIFI_CIPHER_TYPE_NONE:
        ESP_LOGI(TAG, "Pairwise Cipher \tWIFI_CIPHER_TYPE_NONE");
        break;
    case WIFI_CIPHER_TYPE_WEP40:
        ESP_LOGI(TAG, "Pairwise Cipher \tWIFI_CIPHER_TYPE_WEP40");
        break;
    case WIFI_CIPHER_TYPE_WEP104:
        ESP_LOGI(TAG, "Pairwise Cipher \tWIFI_CIPHER_TYPE_WEP104");
        break;
    case WIFI_CIPHER_TYPE_TKIP:
        ESP_LOGI(TAG, "Pairwise Cipher \tWIFI_CIPHER_TYPE_TKIP");
        break;
    case WIFI_CIPHER_TYPE_CCMP:
        ESP_LOGI(TAG, "Pairwise Cipher \tWIFI_CIPHER_TYPE_CCMP");
        break;
    case WIFI_CIPHER_TYPE_TKIP_CCMP:
        ESP_LOGI(TAG, "Pairwise Cipher \tWIFI_CIPHER_TYPE_TKIP_CCMP");
        break;
    default:
        ESP_LOGI(TAG, "Pairwise Cipher \tWIFI_CIPHER_TYPE_UNKNOWN");
        break;
    }

    switch (group_cipher) {
    case WIFI_CIPHER_TYPE_NONE:
        ESP_LOGI(TAG, "Group Cipher \tWIFI_CIPHER_TYPE_NONE");
        break;
    case WIFI_CIPHER_TYPE_WEP40:
        ESP_LOGI(TAG, "Group Cipher \tWIFI_CIPHER_TYPE_WEP40");
        break;
    case WIFI_CIPHER_TYPE_WEP104:
        ESP_LOGI(TAG, "Group Cipher \tWIFI_CIPHER_TYPE_WEP104");
        break;
    case WIFI_CIPHER_TYPE_TKIP:
        ESP_LOGI(TAG, "Group Cipher \tWIFI_CIPHER_TYPE_TKIP");
        break;
    case WIFI_CIPHER_TYPE_CCMP:
        ESP_LOGI(TAG, "Group Cipher \tWIFI_CIPHER_TYPE_CCMP");
        break;
    case WIFI_CIPHER_TYPE_TKIP_CCMP:
        ESP_LOGI(TAG, "Group Cipher \tWIFI_CIPHER_TYPE_TKIP_CCMP");
        break;
    default:
        ESP_LOGI(TAG, "Group Cipher \tWIFI_CIPHER_TYPE_UNKNOWN");
        break;
    }
}



void Wifi_PrintEventName(system_event_id_t event)
{
	char * eventNameList[] =
	{
		    "SYSTEM_EVENT_WIFI_READY",
		    "SYSTEM_EVENT_SCAN_DONE",
		    "SYSTEM_EVENT_STA_START",
		    "SYSTEM_EVENT_STA_STOP",
		    "SYSTEM_EVENT_STA_CONNECTED",
		    "SYSTEM_EVENT_STA_DISCONNECTED",
		    "SYSTEM_EVENT_STA_AUTHMODE_CHANGE",
		    "SYSTEM_EVENT_STA_GOT_IP",
		    "SYSTEM_EVENT_STA_LOST_IP",
		    "SYSTEM_EVENT_STA_BSS_RSSI_LOW",
		    "SYSTEM_EVENT_STA_WPS_ER_SUCCESS",
		    "SYSTEM_EVENT_STA_WPS_ER_FAILED",
		    "SYSTEM_EVENT_STA_WPS_ER_TIMEOUT",
		    "SYSTEM_EVENT_STA_WPS_ER_PIN",
		    "SYSTEM_EVENT_STA_WPS_ER_PBC_OVERLAP",
		    "SYSTEM_EVENT_AP_START",
		    "SYSTEM_EVENT_AP_STOP",
		    "SYSTEM_EVENT_AP_STACONNECTED",
		    "SYSTEM_EVENT_AP_STADISCONNECTED",
		    "SYSTEM_EVENT_AP_STAIPASSIGNED",
		    "SYSTEM_EVENT_AP_PROBEREQRECVED",
		    "SYSTEM_EVENT_ACTION_TX_STATUS",
		    "SYSTEM_EVENT_ROC_DONE",
		    "SYSTEM_EVENT_STA_BEACON_TIMEOUT",
		    "SYSTEM_EVENT_FTM_REPORT",
		    "SYSTEM_EVENT_GOT_IP6",
		    "SYSTEM_EVENT_ETH_START",
		    "SYSTEM_EVENT_ETH_STOP",
		    "SYSTEM_EVENT_ETH_CONNECTED",
		    "SYSTEM_EVENT_ETH_DISCONNECTED",
		    "SYSTEM_EVENT_ETH_GOT_IP",
		    "SYSTEM_EVENT_MAX"
	};

	printf("%s\n",eventNameList[event]);
}


char * Wifi_GetAuthModeName(wifi_auth_mode_t authMode)
{
	char * AuthModeNameList[] =
	{
			"open",
			"WEP",
			"WPA_PSK",
			"WPA2_PSK",
			"WPA_WPA2_PSK",
			"WPA2_ENTERPRISE",
			"WPA3_PSK",
			"WPA2_WPA3_PSK"
	};

	return AuthModeNameList[authMode];
}

uint64_t Wifi_IPtoI(uint64_t ip1, uint32_t ip2, uint16_t ip3, uint16_t ip4)
{
	uint64_t ip = ip4  + (ip3 << 8) + (ip2 << 16) + (ip1 << 24);
	ESP_LOGI(TAG, "ip1:%lld\nip1 24:%lld\nip2:%d\nip2 16:%d\nip3:%d\nip3 8:%d\nip4:%d\nip4 0:%d\n",ip1, (ip1 << 24), ip2, (ip2 << 16), ip3, (ip3 << 8), ip4, ip4);
	return ip;
}
char  message[64];
char * Wifi_PrintIPString(uint32_t ip )
{
	uint8_t Byte0 = ip & 0xFF;
	uint8_t Byte1 = (ip >> 8) & 0xFF;
	uint8_t Byte2 = (ip >> 16) & 0xFF;
	uint8_t Byte3 = (ip >> 24) & 0xFF;

	printf("%d.%d.%d.%d",Byte0,Byte1,Byte2,Byte3);
	sprintf(message, "http://%d.%d.%d.%d",Byte0,Byte1,Byte2,Byte3);


	return message;

}


char * Wifi_ConvertMacToString(uint8_t Mac[])
{
	static char str[18];

	sprintf(str,"%02X:%02X:%02X:%02X:%02X:%02X",Mac[0],Mac[1],Mac[2],Mac[3],Mac[4],Mac[5]);

	str[17] = '\0';

	return str;
}



char * Wifi_GetReasonName(uint8_t reason)
{
	char * retval;

	switch (reason)
	{
	case 1 :
		retval = "WIFI_REASON_UNSPECIFIED";
		break;
	case 2 :
		retval = "WIFI_REASON_AUTH_EXPIRE";
		break;
	case 3 :
		retval = "WIFI_REASON_AUTH_LEAVE";
		break;
	case 4 :
		retval = "WIFI_REASON_ASSOC_EXPIRE";
		break;
	case 5 :
		retval = "WIFI_REASON_ASSOC_TOOMANY";
		break;
	case 6 :
		retval = "WIFI_REASON_NOT_AUTHED";
		break;
	case 7 :
		retval = "WIFI_REASON_NOT_ASSOCED";
		break;
	case 8 :
		retval = "WIFI_REASON_ASSOC_LEAVE";
		break;
	case 9 :
		retval = "WIFI_REASON_ASSOC_NOT_AUTHED";
		break;
	case 10 :
		retval = "WIFI_REASON_DISASSOC_PWRCAP_BAD";
		break;
	case 11 :
		retval = "WIFI_REASON_DISASSOC_SUPCHAN_BAD";
		break;
	case 13 :
		retval = "WIFI_REASON_IE_INVALID";
		break;
	case 14 :
		retval = "WIFI_REASON_MIC_FAILURE";
		break;
	case 15 :
		retval = "WIFI_REASON_4WAY_HANDSHAKE_TIMEOUT";
		break;
	case 16 :
		retval = "WIFI_REASON_GROUP_KEY_UPDATE_TIMEOUT";
		break;
	case 17 :
		retval = "WIFI_REASON_IE_IN_4WAY_DIFFERS";
		break;
	case 18 :
		retval = "WIFI_REASON_GROUP_CIPHER_INVALID";
		break;
	case 19 :
		retval = "WIFI_REASON_PAIRWISE_CIPHER_INVALID";
		break;
	case 20 :
		retval = "WIFI_REASON_AKMP_INVALID";
		break;
	case 21 :
		retval = "WIFI_REASON_UNSUPP_RSN_IE_VERSION";
		break;
	case 22 :
		retval = "WIFI_REASON_INVALID_RSN_IE_CAP";
		break;
	case 23 :
		retval = "WIFI_REASON_802_1X_AUTH_FAILED";
		break;
	case 24 :
		retval = "WIFI_REASON_CIPHER_SUITE_REJECTED";
		break;
	case 53 :
		retval = "WIFI_REASON_INVALID_PMKID";
		break;
	case 200 :
		retval = "WIFI_REASON_BEACON_TIMEOUT";
		break;
	case 201 :
		retval = "WIFI_REASON_NO_AP_FOUND";
		break;
	case 202 :
		retval = "WIFI_REASON_AUTH_FAIL";
		break;
	case 203 :
		retval = "WIFI_REASON_ASSOC_FAIL";
		break;
	case 204 :
		retval = "WIFI_REASON_HANDSHAKE_TIMEOUT";
		break;
	case 205 :
		retval = "WIFI_REASON_CONNECTION_FAIL";
		break;
	case 206 :
		retval = "WIFI_REASON_AP_TSF_RESET";
		break;
	case 207 :
		retval = "WIFI_REASON_ROAMING";
		break;
	default :
		retval = "Unknown reason !!";
		break;
	}

	return retval;
}


