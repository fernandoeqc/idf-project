/**
 *    Fernando Carneiro
 *    @fernandoeqc
 *    2022
 */

#include "driver/adc.h"
#include "esp_log.h"
#include "adc_lib.h"

#define CHANNEL_ADC ADC1_CHANNEL_6

static const char *TAG = "ADC";

void setup_adc(void)
{
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(CHANNEL_ADC, ADC_ATTEN_DB_0);
}

float get_adc(void)
{
    int read_raw = adc1_get_raw(CHANNEL_ADC);
    return  (read_raw * 3.3 ) / (4095);
}
