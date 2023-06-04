#include <ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);
int flag=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
WiFi.begin("11111111","12341234");
while(WiFi.status() !=WL_CONNECTED)
{delay(500);
Serial.print(".");
}
Serial.println();
Serial.println("NodeMCU is Connected");
Serial.println(WiFi.localIP());
server.begin();
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  digitalWrite(D1,LOW);
  digitalWrite(D2,LOW);
  digitalWrite(D3,LOW);
  digitalWrite(D4,LOW);
}

void loop() {
   
  // put your main code here, to run repeatedly:
client=server.available();
if(client==1)
{
  String request =client.readStringUntil('\n');
  Serial.println(request);
  request.trim();
  if(request =="GET /Open HTTP/1.1")
  {
    Serial.println("opening");
    digitalWrite(D1,HIGH);
  digitalWrite(D2,LOW);
  digitalWrite(D3,HIGH);
  digitalWrite(D4,LOW);
  delay(3000);
  digitalWrite(D1,LOW);
  digitalWrite(D2,LOW);
  digitalWrite(D3,LOW);
  digitalWrite(D4,LOW);
  delay(3000);
  
  }
  if(request =="GET /Close HTTP/1.1")
  {
    Serial.println("closing");
    digitalWrite(D1,LOW);
  digitalWrite(D2,HIGH);
  digitalWrite(D3,LOW);
  digitalWrite(D4,HIGH);
  delay(3000);
  digitalWrite(D1,LOW);
  digitalWrite(D2,LOW);
  digitalWrite(D3,LOW);
  digitalWrite(D4,LOW);
  delay(3000);
  }
  }
}
