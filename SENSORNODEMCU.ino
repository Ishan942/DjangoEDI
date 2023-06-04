// Define the analog pin that the LM35 temperature sensor is connected to

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ThingSpeak.h>
#include <DHT.h>
#include <SoftwareSerial.h>

// SoftwareSerial abc(13,15); 
#define DHTPIN D5  // Pin connected to the DHT sensor
const int waterSensorPin = A0;  
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
// String str;
//Put WiFi SSID & Password/
const char* ssid = "Galaxy A718FEF";  // Enter SSID here
const char* password = "ishan@11";      // Enter Password here
WiFiClient client;

bool LEDstatus = LOW;
int signal=0;
int flag=0;
long myChannelNumber = 2092912;
const char myWriteAPIKey[] = "IRWDE4R8LMT4GMSP";
// bool LEDstatus = LOW;
ESP8266WebServer server(80);
void setup() {
  Serial.begin(115200);
  // abc .begin(115200);
  Serial.setTimeout(10);
  delay(100);
  pinMode(D4, OUTPUT);

  Serial.println("Connecting to ");
  Serial.println(ssid);

  //connect to your local wi-fi network
  WiFi.begin(ssid, password);

  //check NodeMCU is connected to Wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");
  Serial.println(WiFi.localIP());
  server.begin();
  ThingSpeak.begin(client);
  // Start serial communication
  // Serial.begin(9600);
  dht.begin();

}

void loop() {
  // Read the voltage from the LM35 temperature sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

   if (isnan(humidity) || isnan(temperature)) {
     Serial.println("Failed to read from DHT sensor!");
     return;
   }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
  int waterLevel = analogRead(waterSensorPin);

  // Convert analog value to a percentage (0-100%)
  int percentage = map(waterLevel, 0, 1023, 0, 100);

  

 
  int per = 100 - percentage;
  // Serial.println(t);
  Serial.print("Water Level: ");
  Serial.print(per);
  Serial.println("%");
  Serial.print("Debug - Humidity: ");
  Serial.print(humidity);
  Serial.print(", Water Level: ");
  Serial.println(per);

  // Serial.println(h);
  if (!isnan(temperature) && !isnan(humidity) && per >= 0 && per <= 100) {
     ThingSpeak.setField(1, temperature);
    ThingSpeak.setField(2, humidity);
    ThingSpeak.setField(3, per);

    // Write all fields to ThingSpeak
    ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  }
  server.handleClient();
   delay(10000);


}
