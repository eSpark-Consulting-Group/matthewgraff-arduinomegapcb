/*

  This example code is initialing loaded and it enables GSM.

*/

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(34, OUTPUT);   //PC3  GSM_PWR_EN
  pinMode(35, OUTPUT);   //PC2  PWR12V_EN
  pinMode(36, OUTPUT);   //PC1  GSM_RESET
  pinMode(37, OUTPUT);   //PC0  PWRKEY_EN
  
  digitalWrite(34, LOW);
  digitalWrite(35, HIGH);
  digitalWrite(36, LOW);
  digitalWrite(37, HIGH);
  delay(1000); 
  digitalWrite(37, LOW);  
  delay(1000); 
  digitalWrite(37, HIGH);
  delay(5000); 

  digitalWrite(36, HIGH);  
  delay(5000); 
  digitalWrite(36, LOW);

  digitalWrite(37, HIGH);
  delay(1000); 
  digitalWrite(37, LOW);  
}

// the loop function runs over and over again forever
void loop() {
  
 

                      // wait for a second
}
