#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <ir_Samsung.h>

IRSamsungAc ac(4);     // Set the GPIO to be used for sending messages.

// void printState() {
//   // Display the settings.
//   Serial.println("Samsung A/C remote is in the following state:");
//   Serial.printf("  %s\n", ac.toString().c_str());
//   // Display the encoded IR sequence.
//   unsigned char* ir_code = ac.getRaw();
//   Serial.print("IR Code: 0x");
//   for (uint8_t i = 0; i < ac.getStateLength(); i++)
//     Serial.printf("%02X", ir_code[i]);
//   Serial.println();
// }
void SumsungAC(){

  ac.begin();
  Serial.begin(115200);
  delay(200);
Serial.println("Sumsung AC"); // Code non reconnu

  // Set up what we want to send. See ir_Toshiba.cpp for all the options.
  Serial.println("Default state of the remote.");
  //printState();
  Serial.println("Setting desired state for A/C.");
  ac.on();
  ac.setFan(1);
  
  ac.setMode(kSamsungAcDry);
  ac.setTemp(26);

  
while (true){ // same as while (1)  // Now send the IR signal.
#if SEND_SAMSUNG_AC
  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c == '+' && ac.getMode()!= 4) {
      int newTemp = ac.getTemp() + 1;      // increase the temperature by 1 degree
      if (newTemp <= kSamsungAcMaxTemp) {  // check if the new temperature is within the valid range
        ac.setTemp(newTemp);
        Serial.print("Temperature increased to ");
        Serial.print(newTemp);
        Serial.println(" degrees");
        ac.send();
        //printState();
      } else {
        Serial.println("Maximum temperature reached");
      }
    } else if (c == '-' && ac.getMode()!= 4) {
      int newTemp = ac.getTemp() - 1;      // increase the temperature by 1 degree
      if (newTemp >= kSamsungAcMinTemp) {  // check if the new temperature is within the valid range
        ac.setTemp(newTemp);
        Serial.print("Temperature decreased to ");
        Serial.print(newTemp);
        Serial.println(" degrees");
        ac.send();
        //printState();
      } else {
        Serial.println("Minimum temperature reached");
      }
    }else if (c=='m') {
      if (ac.getMode() == 4) {
        int newMode = 0;
        ac.setMode(newMode);
        Serial.println("Automatic Mode");
        ac.send();
        //printState();
      } else {
        int newMode = ac.getMode() + 1;
        ac.setMode(newMode);
        Serial.println("Mode switch");
        ac.send();
        //printState();
      }
  
    } else if (c == 'f' && ac.getMode() != 2) {
      if (ac.getFan() == 5) {
        int newFan = 0;
        ac.setFan(newFan);
        Serial.println("Automatic Fan");
        ac.send();
        //printState();
      } else {
        int newFan = ac.getFan() + 1;
        ac.setFan(newFan);
        Serial.println("fan up");
        ac.send();
        //printState();
      }
    }else if (c== 'f'){
      ac.off();
      ac.send();
      Serial.println("AC turned off");
    }else if (c== 'o'){
      ac.on();
      ac.send();
      Serial.println("AC turned on");
    }else if (c== 's'){
      if(ac.getSwing()){
        ac.setSwing(false);
        ac.send();
        Serial.println("swing off");
      }
      else{
        ac.setSwing(true);
        ac.send();
        Serial.println("swing on");
      }
    }
  }

#endif  // SEND_TOSHIBA_AC
}}