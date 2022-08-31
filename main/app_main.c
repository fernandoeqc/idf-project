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
#include "json_lib.h"

static const char *TAG = "MAIN";
QueueHandle_t q_voltage_reads;

/* Functions Prototypes */
static void createTasks(void);
static void vTaskReadVoltage(void *arg);
static void vTaskJsonPacket(void *arg);

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
    xTaskCreate(vTaskReadVoltage,
                "readV",
                2048,
                NULL,
                1,
                NULL);

    xTaskCreate(vTaskJsonPacket,
                "jsonPack",
                4090,
                NULL,
                1,
                NULL);
    q_voltage_reads = xQueueCreate( 50, sizeof( float ) );
}

static void vTaskReadVoltage(void *arg)
{   
    int count = 0;
    float snd; 

    ESP_LOGI(TAG, "vTaskReadVoltage created...");
    
    setup_adc();
    for(;;)
    {   

        snd = get_adc();
        
        xQueueSend(q_voltage_reads, &snd, pdMS_TO_TICKS(20));
        printf("count: %i\n", count);
        count++;

        vTaskDelay(pdMS_TO_TICKS(2000));
    }
    vTaskDelete(NULL);
}

static void vTaskJsonPacket(void *arg)
{
    float rcv;
    ESP_LOGI(TAG, "vTaskJsonPacket created...");
    for(;;)
    {
        while (xQueueReceive(q_voltage_reads, &rcv, pdMS_TO_TICKS(500)) == true)
        {
            createJson(rcv);
            // send_mqtt(rcv, 5);
        }
        

        vTaskDelay(pdMS_TO_TICKS(10000));
    }
    vTaskDelete(NULL);
}