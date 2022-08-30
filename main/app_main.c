/**
 *    Fernando Carneiro
 *    @fernandoeqc
 *    2022
 *    Telemetria de dados via Mqtt
 */

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "esp_wifi.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "esp_event.h"
#include "esp_netif.h"
#include "protocol_examples_common.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"

#include "lwip/sockets.h"
#include "lwip/dns.h"
#include "lwip/netdb.h"
#include "esp_log.h"

#include "mqtt_lib.h"
#include "adc_lib.h"

static const char *TAG = "MAIN";

/* Functions Prototypes */
static void createTasks(void);
static void vTaskReadAdc(void *arg);
static void vTaskJson(void *arg);
static void vTaskMqtt(void *arg);

void app_main(void)
{   
    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    ESP_ERROR_CHECK(example_connect());

    mqtt_app_start();

    createTasks();
    for(;;)
    {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

static void createTasks(void)
{
    xTaskCreate(vTaskReadAdc,
                "read_adc",
                2048,
                NULL,
                1,
                NULL);

    xTaskCreate(vTaskJson,
                "read_adc",
                2048,
                NULL,
                1,
                NULL);
}

static void vTaskReadAdc(void *arg)
{
    setup_adc();
    for(;;)
    {
        get_adc();
        vTaskDelay(pdMS_TO_TICKS(100));
    }
    vTaskDelete(NULL);
}

static void vTaskJson(void *arg)
{
    for(;;)
    {
        getAverageVolt();
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
    vTaskDelete(NULL);
}