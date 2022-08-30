/**
 *    Fernando Carneiro
 *    @fernandoeqc
 *    2022
 */

#ifndef MQTT_LIB_H
#define MQTT_LIB_H

/* Functions Prototypes */
void mqtt_app_start(void);
void send_mqtt(char *data, int len);
static void recv_mqtt(void);

#endif //MQTT_LIB_H
