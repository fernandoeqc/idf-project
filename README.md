## ESP-IDF Project

Envio de informações de sensores via MQTT, usando wifi. Testado na placa TTGO-TCALL.

O SSID e a senha devem ser alterados no menuconfig, com o comando: `idf.py menuconfig`, na aba `Example Connection Configuration`.

#### To-Do:
- [ ] Enpacotamento dos dados em Json
- [ ] Controle remoto de LED por pacote Json 
- [ ] Leitura de porta analógica
- [ ] Uso de etruturas do RTOS
