#include <stdio.h>
#include "esp_log.h"
#include "json_lib.h"
#include "cJSON.h"
void getJson(void)
{
    cJSON *root,*fmt;
	root=cJSON_CreateObject();
	cJSON_AddItemToObject(root, "name", cJSON_CreateString("Jack (\"Bee\") Nimble"));
	cJSON_AddItemToObject(root, "format", fmt=cJSON_CreateObject());
	cJSON_AddStringToObject(fmt,"type",		"rect");
	cJSON_AddNumberToObject(fmt,"width",		1920);
	cJSON_AddNumberToObject(fmt,"height",		1080);
	cJSON_AddFalseToObject (fmt,"interlace");
	cJSON_AddNumberToObject(fmt,"frame rate",	24);

	char *rendered=cJSON_Print(root);
	ESP_LOG_BUFFER_CHAR("buf", rendered, 202);
}
