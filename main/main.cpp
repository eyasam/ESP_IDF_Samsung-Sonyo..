/*
#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <ir_Toshiba.h>

const uint16_t kIrLed = 4;  // ESP8266 GPIO pin to use. Recommended: 4 (D2).
IRToshibaAC ac(kIrLed);     // Set the GPIO to be used for sending messages.

void printState() {
  // Display the settings.
  Serial.println("Toshiba A/C remote is in the following state:");
  Serial.printf("  %s\n", ac.toString().c_str());
  // Display the encoded IR sequence.
  unsigned char* ir_code = ac.getRaw();
  Serial.print("IR Code: 0x");
  for (uint8_t i = 0; i < ac.getStateLength(); i++)
    Serial.printf("%02X", ir_code[i]);
  Serial.println();
}

void setup() {
  ac.begin();
  Serial.begin(115200);
  delay(200);

  // Set up what we want to send. See ir_Toshiba.cpp for all the options.
  Serial.println("Default state of the remote.");
  printState();
  Serial.println("Setting desired state for A/C.");
  ac.on();
  ac.setFan(1);
  
  ac.setMode(kToshibaAcDry);
  ac.setTemp(26);
}

void loop() {
  // Now send the IR signal.
#if SEND_TOSHIBA_AC
  if (Serial.available() > 0) {
    char c = Serial.read();
    
if (c == '+' && ac.getMode()!= 4) {
      int newTemp = ac.getTemp() + 1;      // increase the temperature by 1 degree
      if (newTemp <= kToshibaAcMaxTemp) {  // check if the new temperature is within the valid range
        ac.setTemp(newTemp);
        Serial.print("Temperature increased to ");
        Serial.print(newTemp);
        Serial.println(" degrees");
        ac.send();
        printState();
      } else {
        Serial.println("Maximum temperature reached");
      }
    } else if (c == '-' && ac.getMode()!= 4) {

      int newTemp = ac.getTemp() - 1;      // increase the temperature by 1 degree
      if (newTemp >= kToshibaAcMinTemp) {  // check if the new temperature is within the valid range
        ac.setTemp(newTemp);
        Serial.print("Temperature decreased to ");
        Serial.print(newTemp);
        Serial.println(" degrees");
        ac.send();
        printState();
      } else {
        Serial.println("Minimum temperature reached");
      }
    }else if (c=='m') {
      if (ac.getMode() == 4) {
        int newMode = 0;
        ac.setMode(newMode);
        Serial.println("Automatic Mode");
        ac.send();
        printState();
      } else {
        int newMode = ac.getMode() + 1;
        ac.setMode(newMode);
        Serial.println("Mode switch");
        ac.send();
        printState();
      }
  
    } else if (c == 'f' && ac.getMode() != 2) {
      if (ac.getFan() == 5) {
        int newFan = 0;
        ac.setFan(newFan);
        Serial.println("Automatic Fan");
        ac.send();
        printState();
      } else {
        int newFan = ac.getFan() + 1;
        ac.setFan(newFan);
        Serial.println("fan up");
        ac.send();
        printState();
      }
    }
  }

#endif  // SEND_TOSHIBA_AC
}*/
/*
#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <ir_Mirage.h>

const uint16_t kIrLed = 4;  // ESP8266 GPIO pin to use. Recommended: 4 (D2).
IRMirageAc ac(kIrLed);     // Set the GPIO to be used for sending messages.
*/
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
/*
void setup() {
  ac.begin();
  Serial.begin(115200);
  delay(200);

  // Set up what we want to send. See ir_Toshiba.cpp for all the options.
  Serial.println("Default state of the remote.");
  //printState();
  Serial.println("Setting desired state for A/C.");
  ac.on();
  ac.setFan(1);
  
  ac.setMode(kMirageAcDry);
  ac.setTemp(26);
}

void loop() {
  // Now send the IR signal.
#if SEND_MIRAGE
  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c == '+' && ac.getMode()!= 4) {
      int newTemp = ac.getTemp() + 1;      // increase the temperature by 1 degree
      if (newTemp <= kMirageAcMaxTemp) {  // check if the new temperature is within the valid range
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
      if (newTemp >= kMirageAcMinTemp) {  // check if the new temperature is within the valid range
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
    }else if (c== 'x'){
      ac.off();
      ac.send();
      Serial.println("AC turned off");
    }else if (c== 'o'){
      ac.on();
      ac.send();
      Serial.println("AC turned on");
    }else if (c== 's'){
      if(ac.getSwingH()){
        ac.setSwingH(false);
        ac.send();
        Serial.println("swing off");
      }
      else{
        ac.setSwingH(true);
        ac.send();
        Serial.println("swing on");
      }
    }
  }

#endif  // SEND_MIRAGE
}
*/

#include <Arduino.h>
#include <SamsungAC.cpp>
#include <SanyoAC.cpp>
#include <TecoAC.cpp>


void setup() {
  Serial.begin(115200);
  delay(200);
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // Lire la chaîne de caractères entrée par l'utilisateur
    input.trim(); // Supprimer les espaces en début et fin de la chaîne
    if (input == "1") {
      // Appeler la fonction correspondant au code a
      SamsungAC();
    } else if (input == "2") {
      // Appeler la fonction correspondant au code b
      SanyoAC();//koujina
    } else if (input == "3") {
      // Appeler la fonction correspondant au code b
      TecoAC();//imen
    }else {
      Serial.println("Code invalide"); // Code non reconnu
    }
  }
}
