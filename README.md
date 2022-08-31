## ESP-IDF Project

Envio de informações de sensores via MQTT, usando wifi. Testado na placa TTGO-TCALL.

#### Configurações:
* Projeto testado com ESP-IDF v4.3.3, python 3.10 
* Alterar o SSID e a senha no menuconfig, com o comando: `idf.py menuconfig`, na aba `Example Connection Configuration`.
* Comando para recebimento de pacotes via MQTT:
`mosquitto_sub -h "mqtt.eclipseprojects.io" -t "/diel/sensor/" -d`
* Comando para envio de pacotesVIA MQTT:
    * `mosquitto_pub -h "mqtt.eclipseprojects.io" -t "/diel/command/" -m "LOW" -d`
    * `mosquitto_pub -h "mqtt.eclipseprojects.io" -t "/diel/command/" -m "HIGH" -d`

#### Descrição:
O sistema tem duas tasks. Uma para leltura do pino adc e outra para envio das leituras via mqtt.
Elas compartilham entre si uma queue para transferencia dos dados lidos.

#### Done
- [x] Enpacotamento dos dados em Json
- [x] Controle remoto de LED por pacote Json 
- [x] Leitura de porta analógica
- [x] Uso de etruturas do RTOS
#### To-Do:
- [ ] Leituras de dados seriais
- [ ] Refatoração das tasks
