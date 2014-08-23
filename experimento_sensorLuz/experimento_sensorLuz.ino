/*Sensor de luz

Ejemplo de un sensor de luz que enciende, en funcion 
de la cantidad de luz que reciba, una serie de leds.

Poca luz, apaga todos los leds
mucha luz, enciende los cuatro

*/

/*
El sensor de luz va conectado a A0 ademas de llevar una resistencia
con ground. En la otra pata va a 5v
*/

const int ledPin1=12;
const int ledPin2=11;
const int ledPin3=10;
const int ledPin4=9;
int sensorValue = 0;
int sensorLow = 100;
int sensorHigh = 0;

void setup(){
  //comenzamos la calibracion. Lo indicamos iluminando todos los leds
  pinMode(ledPin1, OUTPUT);
  digitalWrite(ledPin1, HIGH);
  pinMode(ledPin2, OUTPUT);
  digitalWrite(ledPin2, HIGH);
  pinMode(ledPin3, OUTPUT);
  digitalWrite(ledPin3, HIGH);
  pinMode(ledPin4, OUTPUT);
  digitalWrite(ledPin4, HIGH);
  
  //calibramos durante 5 segundos
  while (millis() < 5000) {
    sensorValue=analogRead(A0);
    
    if(sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    
    if(sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  } //fin del while
  
  //apagamos las luces
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
}

void loop() {
  sensorValue = analogRead(A0);
  
  int luces=map(sensorValue, sensorLow, sensorHigh, 0, 4);
  
  switch (luces) {
    case 0:
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, LOW);
      break;
    case 1:
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, LOW);
      break;
    case 2:
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, LOW);
      break;
    case 3:
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, LOW);
      break;
    case 4:
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, HIGH);
      break;
    default:
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, HIGH);
      break;
  } //fin del case
  
  delay(10);
}
