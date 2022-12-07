#include <Adafruit_BME280.h>
#include <Adafruit_BME680.h>
#include <bme68x.h>
#include <bme68x_defs.h>



#include <ArduinoJson.h>
#include <ArduinoJson.hpp>
#include <PubSubClient.h>
#include <WiFi.h>

#include <Wire.h>

#include <SD_MMC.h>
#include <sd_defines.h>

#include <I2S.h>
//----------------------------------------------------------------------------------------------------
//----------------------------------------------CONSTANTS---------------------------------------------
//----------------------------------------------------------------------------------------------------

/*
const char *ssid = "mousse"; // Enter your WiFi name
const char *password = "qweqweqwe";  // Enter WiFi password
*/
char *ssid = "LANCOMBEIA";
char *password = "beialancom";

// MQTT Broker
const char *mqtt_broker = "mqtt.beia-telemetrie.ro";
const char *topic = "bird";
const char *mqtt_username = "";
const char *mqtt_password = "";
const int mqtt_port = 1883;

//----------------------------------------------------------------------------------------------------
//-------------------------------------------------VARIABLES------------------------------------------
//----------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------
//-------------------------------------------------FUNCTIONS------------------------------------------
//----------------------------------------------------------------------------------------------------

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

//uncomment the following lines if you're using SPI
/*#include <SPI.h>
#define BME_SCK 18
#define BME_MISO 19
#define BME_MOSI 23
#define BME_CS 5*/

Adafruit_BME280 MY_bme280; // I2C
//Adafruit_BME280 bme(BME_CS); // hardware SPI
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI
float temperature = 0;
float humidity = 0;

void Start_WIFI(int8_t *atempts)
{
  // WiFi
  int8_t i = 0;
  WiFi.begin(ssid, password);
  while ((WiFi.status() != WL_CONNECTED) && (i < atempts))
  {
    delay(500);
    i++;
    Serial.println("Connecting to WiFi..");
  }
void Connect_MQTT(int8_t *atempts) {

  Start_WIFI(atempts);
  client.setServer(mqtt_broker, mqtt_port);
  client.setCallback(callback);
  while (!client.connected() && (i < atempts))
   {
    String client_id = "esp32-client-";
    client_id += String(WiFi.macAddress());
    Serial.printf("The client %s connects to the BEIA MQTT broker\n", client_id.c_str());
    if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) 
    {
      Serial.println("BEIA MQTT broker connected");
    } else 
    {
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

void MQTT_Send( char *my_data)
{


  
Connect_MQTT(4);

client.publish(topic, my_data);




}


//----------------------------------------------------------------------------------------------------
//-----------------------------------------------MAIN LOOPS-------------------------------------------
//----------------------------------------------------------------------------------------------------

  void setup() {
    // put your setup code here, to run once:
    // Set software serial baud to 115200;
    Serial.begin(115200);

  }

  void loop() {
    // put your main code here, to run repeatedly:

  }
