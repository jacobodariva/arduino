/*
Experimento 2. Un led parpadea en funcion de un potenciometro lineal

*/

const int potPin=0;

const int ledPin=13;

int val=0;

void setup(){
  pinMode(ledPin, OUTPUT);
}

void loop(){
  val = analogRead(potPin);
  digitalWrite(ledPin, HIGH);
  delay(val);
  digitalWrite(ledPin, LOW);
  delay(val);
}
