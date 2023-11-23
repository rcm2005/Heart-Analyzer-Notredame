#include <WiFi.h>
#include <PubSubClient.h>

const char* SSID = "Wokwi-GUEST";
const char* PASSWORD = "";
const char* BROKER_MQTT = "46.17.108.113";
const int BROKER_PORT = 1883;
const char* TOPICO_PUBLISH = "/TEF/lamp118/attrs";
const char* ID_MQTT = "fiware_118";

WiFiClient espClient;
PubSubClient client(espClient);

const int potRaPin = 33;
const int potLaPin = 34;
const int potLlPin = 32;

void setup() {
  Serial.begin(115200);

  // Conecta-se à rede Wi-Fi
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi...");
  }
  Serial.println("Conectado ao WiFi");

  // Conecta-se ao broker MQTT
  client.setServer(BROKER_MQTT, BROKER_PORT);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Leitura dos potenciômetros
  int potRaValue = analogRead(potRaPin);
  int potLaValue = analogRead(potLaPin);
  int potLlValue = analogRead(potLlPin);

  // Mapeia os valores dos potenciômetros para amplitudes e frequências desejadas
  float amplitudeRa = map(potRaValue, 0, 1023, 0.1, 1.0);
  float amplitudeLa = map(potLaValue, 0, 1023, 0.1, 1.0);
  float amplitudeLl = map(potLlValue, 0, 1023, 0.1, 1.0);

  float frequenciaRa = map(potRaValue, 0, 1023, 0.5, 2.0);
  float frequenciaLa = map(potLaValue, 0, 1023, 0.5, 2.0);
  float frequenciaLl = map(potLlValue, 0, 1023, 0.5, 2.0);

  // Tempo atual
  unsigned long currentMillis = millis();

  // Gera os sinais senoidais defasados no tempo
  float signalRa = amplitudeRa * sin(2 * PI * frequenciaRa * currentMillis / 1000.0);
  float signalLa = amplitudeLa * sin(2 * PI * frequenciaLa * (currentMillis - 300) / 1000.0);
  float signalLl = amplitudeLl * sin(2 * PI * frequenciaLl * (currentMillis - 600) / 1000.0);

  // Imprime os valores no Serial Plotter
  Serial.print(signalRa);
  Serial.print("\t");
  Serial.print(signalLa);
  Serial.print("\t");
  Serial.println(signalLl);

  // Publica os dados no MQTT
  String message = String(signalRa);
  EnviaEstadoOutputMQTT(message);

  delay(10);  // Ajuste conforme necessário
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensagem recebida no tópico: ");
  Serial.println(topic);

  Serial.print("Conteúdo da mensagem: ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void EnviaEstadoOutputMQTT(String message) {
  // Converte a string para um array de caracteres (c-string)
  char messageArray[message.length() + 1];
  message.toCharArray(messageArray, sizeof(messageArray));

  // Publica os dados
  client.publish(TOPICO_PUBLISH, messageArray);
}

void reconnect() {
  while (!client.connected()) {
    Serial.println("Conectando ao MQTT Broker...");
    if (client.connect(ID_MQTT)) {
      Serial.println("Conectado ao MQTT Broker");
      client.subscribe(TOPICO_PUBLISH);
    } else {
      Serial.println("Falha na conexão ao MQTT Broker. Tentando novamente em 5 segundos...");
      delay(5000);
    }
  }
}