/**
 * @file MultiThermometer.ino
 * Read temperatures from multiple Termopar Nanoshields, with different thermocouple types.
 * 
 * Copyright (c) 2015 Circuitar
 * This software is released under the MIT license. See the attached LICENSE file for details.
 */
#include <SPI.h>
#include "Nanoshield_Termopar.h"

// Create an array of five thermocouples of different types
Nanoshield_Termopar tc[] = {
  Nanoshield_Termopar(22, TC_TYPE_K, TC_AVG_OFF),
  Nanoshield_Termopar(23, TC_TYPE_K, TC_AVG_OFF),
  Nanoshield_Termopar(24, TC_TYPE_K, TC_AVG_OFF),
  Nanoshield_Termopar(25, TC_TYPE_K, TC_AVG_OFF),
};

const int numModules = sizeof(tc) / sizeof(Nanoshield_Termopar);

void setup()
{
  Serial.begin(9600);
  Serial.println("------------------");
  Serial.println(" MultiThermometer");
  Serial.println("------------------");
  Serial.println();

  // Initialize each Termopar Nanoshield
  for(int i = 0; i < numModules; i++) {
    tc[i].begin();
  }
}

void printErrors(Nanoshield_Termopar tc) {
  if (tc.isOpen()) {
    Serial.print("(Open circuit) ");
  } else if (tc.isOverUnderVoltage()) {
    Serial.print("(Overvoltage/Undervotage) ");
  } else if (tc.isInternalOutOfRange()) {
    Serial.print("(Internal temperature out of range) ");
  } else if (tc.isExternalOutOfRange()) {
    Serial.print("(External temperature out of range) ");
  }
}

void loop()
{
  for(int i = 0; i < numModules; i++) {
    // Read thermocouple data
    tc[i].read();
    
    // Print thermocouple number
    Serial.print(i + 1);
    Serial.print(": ");
  
    // Print temperature in the serial port, checking for errors
    if (tc[i].hasError()) {
      printErrors(tc[i]);
    } else {
      Serial.print("Internal: ");
      Serial.print(tc[i].getInternal());
      Serial.print(" | External: ");
      Serial.print(tc[i].getExternal());
    }
    Serial.println();
  }
  Serial.println();

  // Wait for next second
  delay(1000);
}
