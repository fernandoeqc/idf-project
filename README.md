## ESP-IDF Project

Envio de informações de sensores via MQTT, usando wifi. Testado na placa TTGO-TCALL.

#### Configurações:
* Projeto testado com ESP-IDF v4.3.3, python 3.10 
* Alterar o SSID e a senha no menuconfig, com o comando: `idf.py menuconfig`, na aba `Example Connection Configuration`.

#### Descrição:
O sistema tem duas tasks. Uma para leltura do pino adc e outra para envio das leituras via mqtt.
Elas compartilham entre si uma queue para transferencia dos dados lidos.

#### To-Do:
- [x] Enpacotamento dos dados em Json
- [ ] Controle remoto de LED por pacote Json 
- [x] Leitura de porta analógica
- [x] Uso de etruturas do RTOS
- [ ] Leituras de dados seriais
