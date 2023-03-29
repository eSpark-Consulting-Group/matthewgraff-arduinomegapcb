/*
  AnalogReadSerial

*/

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(34, OUTPUT);
  pinMode(35, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
    digitalWrite(34, LOW);
  digitalWrite(35, HIGH);
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
   int sensorValue1 = analogRead(A1);
  // print out the value you read:
  Serial.print("ADC0 = ");
  Serial.print(sensorValue);
  Serial.print("  ADC1 = ");
  Serial.println(sensorValue1);
  delay(300);  // delay in between reads for stability
}
