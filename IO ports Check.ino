#define led 2
#define red 15
#define green 12
#define blue 13
#define ldr A0

void setup() {
  // put your setup code here, to run once:
  pinMode (led,OUTPUT);
  pinMode (red,OUTPUT);
  pinMode (green,OUTPUT);
  pinMode (blue,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (led,HIGH);
  delay(1000);
  digitalWrite (led,LOW);
  delay(1000);
  digitalWrite (red,HIGH);
  delay(1000);
  digitalWrite (red,LOW);
  delay(1000);
  digitalWrite (green,HIGH);
  delay(1000);
  digitalWrite (green,LOW);
  delay(1000);
  digitalWrite (blue,HIGH);
  delay(1000);
  digitalWrite (blue,LOW);
  delay(1000);

  Serial.println(analogRead (ldr));
}
