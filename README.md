## ESP-IDF Project

Envio de informações de sensores via MQTT, usando wifi. Testado na placa TTGO-TCALL.

#### Configurações:
* Projeto testado com a versão 4.3.3 do ESP-IDF
* Alterar o SSID e a senha no menuconfig, com o comando: `idf.py menuconfig`, na aba `Example Connection Configuration`.


#### To-Do:
- [ ] Enpacotamento dos dados em Json
- [ ] Controle remoto de LED por pacote Json 
- [ ] Leitura de porta analógica
- [ ] Uso de etruturas do RTOS
