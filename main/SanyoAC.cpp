#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <ir_Sanyo.h>

IRSanyoAc sanyoAc(4);  // Set the GPIO to be used for sending messages.
/*
void printState() {
   // Display the settings.
   Serial.println("Samsung A/C remote is in the following state:");
   Serial.printf("  %s\n", ac.toString().c_str());
   // Display the encoded IR sequence.
  unsigned char* ir_code = ac.getRaw();
   Serial.print("IR Code: 0x");
   for (uint8_t i = 0; i < ac.getStateLength(); i++)
    Serial.printf("%02X", ir_code[i]);
   Serial.println();
 }*/

void SanyoAC() {
  sanyoAc.begin();
  Serial.begin(115200);
  delay(200);
    Serial.println("Sonyo AC"); // Code non reconnu

  // Set up what we want to send. See ir_Toshiba.cpp for all the options.
  Serial.println("Default state of the remote.");
  //printState();
  Serial.println("Setting desired state for A/C.");
  sanyoAc.on();
  sanyoAc.setFan(1);
  
  sanyoAc.setMode(kSanyoAcDry);
  sanyoAc.setTemp(26);


while (true){ // same as while (1)  // Now send the IR signal.
  // Now send the IR signal.
#if SEND_SANYO_AC
  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c == '+' && sanyoAc.getMode()!= 4) {
      int newTemp = sanyoAc.getTemp() + 1;      // increase the temperature by 1 degree
      if (newTemp <= kSanyoAcTempMax) {  // check if the new temperature is within the valid range
        sanyoAc.setTemp(newTemp);
        Serial.print("Temperature increased to ");
        Serial.print(newTemp);
        Serial.println(" degrees");
        sanyoAc.send();
        //printState();
      } else {
        Serial.println("Maximum temperature reached");
      }
    } else if (c == '-' && sanyoAc.getMode()!= 4) {
      int newTemp = sanyoAc.getTemp() - 1;      // increase the temperature by 1 degree
      if (newTemp >= kSanyoAcTempMin) {  // check if the new temperature is within the valid range
        sanyoAc.setTemp(newTemp);
        Serial.print("Temperature decreased to ");
        Serial.print(newTemp);
        Serial.println(" degrees");
        sanyoAc.send();
        //printState();
      } else {
        Serial.println("Minimum temperature reached");
      }
    }else if (c=='m') {
      if (sanyoAc.getMode() == 4) {
        int newMode = 0;
        sanyoAc.setMode(newMode);
        Serial.println("Automatic Mode");
        sanyoAc.send();
        //printState();
      } else {
        int newMode = sanyoAc.getMode() + 1;
        sanyoAc.setMode(newMode);
        Serial.println("Mode switch");
        sanyoAc.send();
        //printState();
      }
  
    } else if (c == 'f' && sanyoAc.getMode() != 2) {
      if (sanyoAc.getFan() == 5) {
        int newFan = 0;
        sanyoAc.setFan(newFan);
        Serial.println("Automatic Fan");
        sanyoAc.send();
        //printState();
      } else {
        int newFan = sanyoAc.getFan() + 1;
        sanyoAc.setFan(newFan);
        Serial.println("fan up");
        sanyoAc.send();
        //printState();
      }
    }else if (c== 'x'){
      sanyoAc.off();
      sanyoAc.send();
      Serial.println("AC turned off");
    }else if (c== 'o'){
      sanyoAc.on();
      sanyoAc.send();
      Serial.println("AC turned on");
    }else if (c== 's'){
      if(sanyoAc.getSwingV()){
        sanyoAc.setSwingV(false);
        sanyoAc.send();
        Serial.println("swing off");
      }
      else{
        sanyoAc.setSwingV(true);
        sanyoAc.send();
        Serial.println("swing on");
      }
    }
  }

#endif  // SEND_TOSHIBA_AC
}}