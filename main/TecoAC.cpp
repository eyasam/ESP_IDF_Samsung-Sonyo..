#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <ir_Teco.h>

IRTecoAc tecoAc(4);     // Set the GPIO to be used for sending messages.
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
void TecoAC(){

  tecoAc.begin();
  Serial.begin(115200);
  delay(200);
    Serial.println("Teco AC"); // Code non reconnu

  // Set up what we want to send. See ir_Toshiba.cpp for all the options.
  Serial.println("Default state of the remote.");
  //printState();
  Serial.println("Setting desired state for A/C.");
  tecoAc.on();
  tecoAc.setFan(1);
  
  tecoAc.setMode(kTecoDry);
  tecoAc.setTemp(26);


while (true){ // same as while (1)  // Now send the IR signal.
  // Now send the IR signal.
#if SEND_TECO
  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c == '+' && tecoAc.getMode()!= 4) {
      int newTemp = tecoAc.getTemp() + 1;      // increase the temperature by 1 degree
      if (newTemp <= kTecoMaxTemp) {  // check if the new temperature is within the valid range
        tecoAc.setTemp(newTemp);
        Serial.print("Temperature increased to ");
        Serial.print(newTemp);
        Serial.println(" degrees");
        tecoAc.send();
        //printState();
      } else {
        Serial.println("Maximum temperature reached");
      }
    } else if (c == '-' && tecoAc.getMode()!= 4) {
      int newTemp = tecoAc.getTemp() - 1;      // increase the temperature by 1 degree
      if (newTemp >= kTecoMinTemp) {  // check if the new temperature is within the valid range
        tecoAc.setTemp(newTemp);
        Serial.print("Temperature decreased to ");
        Serial.print(newTemp);
        Serial.println(" degrees");
        tecoAc.send();
        //printState();
      } else {
        Serial.println("Minimum temperature reached");
      }
    }else if (c=='m') {
      if (tecoAc.getMode() == 4) {
        int newMode = 0;
        tecoAc.setMode(newMode);
        Serial.println("Automatic Mode");
        tecoAc.send();
        //printState();
      } else {
        int newMode = tecoAc.getMode() + 1;
        tecoAc.setMode(newMode);
        Serial.println("Mode switch");
        tecoAc.send();
        //printState();
      }
  
    } else if (c == 'f' && tecoAc.getMode() != 2) {
      if (tecoAc.getFan() == 5) {
        int newFan = 0;
        tecoAc.setFan(newFan);
        Serial.println("Automatic Fan");
        tecoAc.send();
        //printState();
      } else {
        int newFan = tecoAc.getFan() + 1;
        tecoAc.setFan(newFan);
        Serial.println("fan up");
        tecoAc.send();
        //printState();
      }
    }else if (c== 'x'){
      tecoAc.off();
      tecoAc.send();
      Serial.println("AC turned off");
    }else if (c== 'o'){
      tecoAc.on();
      tecoAc.send();
      Serial.println("AC turned on");
    }else if (c== 's'){
      if(tecoAc.getSwing()){
        tecoAc.setSwing(false);
        tecoAc.send();
        Serial.println("swing off");
      }
      else{
        tecoAc.setSwing(true);
        tecoAc.send();
        Serial.println("swing on");
      }
    }
  }

#endif  
}}