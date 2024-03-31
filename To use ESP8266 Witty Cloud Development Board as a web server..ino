#include <ESP8266WiFi.h>
#define led 2
#define red 15
#define green 12
#define blue 13
#define ldr A0
WiFiClient client;
WiFiServer server(80);
void setup() {
// put your setup code here, to run once:
pinMode(led,OUTPUT);
pinMode(red,OUTPUT);
pinMode(green,OUTPUT);
pinMode(blue,OUTPUT);
Serial.begin(9600);
WiFi.begin("POCO X2","7890123456");
while(WiFi.status() != WL_CONNECTED){
Serial.print('.');
delay(200);
}
Serial.println();
Serial.println("Witty Board Connected!");
Serial.println(WiFi.localIP());
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
digitalWrite(green,HIGH);
if(request=="GET /LedOFF HTTP/1.1")
digitalWrite(green,LOW);
}
}
