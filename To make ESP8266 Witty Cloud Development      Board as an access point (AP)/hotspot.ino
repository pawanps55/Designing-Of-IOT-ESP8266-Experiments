#include <ESP8266WiFi.h>
#define led 2
#define red 15
#define green 12
#define blue 13
#define ldr A0
WiFiClient client;
WiFiServer server(80);

void setup() {
  
  pinMode(led,OUTPUT);
  pinMode(red,OUTPUT);  
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  Serial.begin(9600);

WiFi.softAP("JioFiber","7890123456");
Serial.println();
Serial.println("WittyBoard started!");
Serial.println(WiFi.softAPIP());
server.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
 client =server.available();
  if(client==1){
    String request=client.readStringUntil('\n');
    Serial.println(request);
    request.trim();
    if(request=="GET /ledON HTTP/1.1")
    digitalWrite(red,HIGH);
    if(request=="GET /LedOFF HTTP/1.1")
    digitalWrite(red,LOW);
    
    }
}
