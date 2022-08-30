#include <stdio.h>
#include "json_lib.h"
#include "esp_log.h"
#include "cJSON.h"
#include "mqtt_lib.h"

void createJson(float data)
{
    char *out = NULL;
    cJSON *root;

	root=cJSON_CreateObject();
	cJSON_AddItemToObject(root, "type", cJSON_CreateString("ADC"));
	cJSON_AddItemToObject(root, "value", cJSON_CreateFloatArray(&data, 1));
	
	out = cJSON_Print(root);
	send_mqtt(out, 0);
	
    printf("%s\n", out);
	cJSON_Delete(root);
}
