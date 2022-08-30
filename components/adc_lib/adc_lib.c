/**
 *    Fernando Carneiro
 *    @fernandoeqc
 *    2022
 */

#include "driver/adc.h"
#include "esp_log.h"
#include "adc_lib.h"


static const char *TAG = "ADC";
static int read_raw;
static int count_reads;
static float voltage;

void setup_adc(void)
{
    adc2_config_channel_atten( ADC2_CHANNEL_0, ADC_ATTEN_0db );
}

void get_adc(void)
{
    esp_err_t r = adc2_get_raw( ADC2_CHANNEL_0, ADC_WIDTH_12Bit, &read_raw);
    if ( r == ESP_OK ) {
        printf("raw: %d\n", read_raw);
        voltage += (read_raw * 3.3 ) / (4095);
        count_reads++;
    
    } else if ( r == ESP_ERR_TIMEOUT ) {
        ESP_LOGW(TAG, "ADC2 used by Wi-Fi");

    }
}

float getAverageVolt(void)
{
    float ret;
    ret = voltage / count_reads;
    count_reads = 0;
    voltage = 0;

    printf("Avrg volt: %.2f\n", ret);
    return ret;
}