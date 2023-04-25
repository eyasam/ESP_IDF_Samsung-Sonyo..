#include <Arduino.h>
#include <ArduinoNvs.h>
#include <WiFiManager.h>
#include <SamsungAC.cpp>
#include <SanyoAC.cpp>
#include <TecoAC.cpp>

const uint16_t kIrLed = 4;  // ESP8266 GPIO pin to use. Recommended: 4 (D2).

String acProt = "";
int timeout = 120; 

void setup() {
  Serial.begin(115200);
  delay(200);
  WiFiManager wm;
  bool res;
  res = wm.autoConnect("AutoConnectAP","12345678");
  if(!res) {
        Serial.println("Failed to connect");
        // ESP.restart();
    } 
    else {
        //if you get here you have connected to the WiFi    
        Serial.println("connected...yeey :)");
    }
  NVS.begin();
  Serial.println("Choose Ac");
}

void loop() {
  acProt = NVS.getString("acProtKey");
  if (acProt == "") {
    if (Serial.available() > 0) {
      String input = Serial.readStringUntil('\n');  // Lire la chaîne de caractères entrée par l'utilisateur
      input.trim();                                 // Supprimer les espaces en début et fin de la chaîne
      if (input == "samsung") {
        acProt = NVS.setString("acProtKey", "samsung");
        Serial.println("you chose samsung");
        // Appeler la fonction correspondant au code a
        SumsungAC();
      } else if (input == "sanyo") {
        acProt = NVS.setString("acProtKey", "sanyo");
        Serial.println("you chose Sanyo");
        // Appeler la fonction correspondant au code b
        SanyoAC();  //koujina

      } else if (input == "teco") {
        acProt = NVS.setString("acProtKey", "teco");
        Serial.println("you chose Teco");
        // Appeler la fonction correspondant au code b
        TecoAC();  //imen

      } else {
        Serial.println("Code invalide");  // Code non reconnu
      }
    }
  } else {
    if (acProt == "samsung") {
      Serial.println("This is samsung");
      // Appeler la fonction correspondant au code a
      SumsungAC();
    } else if (acProt == "sanyo") {
      Serial.println("This is Sanyo");
      // Appeler la fonction correspondant au code b
      SanyoAC();  //koujina

    } else if (acProt == "teco") {
      Serial.println("This is Teco");
      // Appeler la fonction correspondant au code b
      TecoAC();  //imen
    }
  }
  String v;
  if ( Serial.available()>0) {
    
    v= Serial.readString();
    if(v.compareTo("ap")){
      Serial.println("ap now");
    WiFiManager wm;    

    //reset settings - for testing
    //wm.resetSettings();
  
    // set configportal timeout
    wm.setConfigPortalTimeout(timeout);

    if (!wm.startConfigPortal("OnDemandAP")) {
      Serial.println("failed to connect and hit timeout");
      delay(3000);
      //reset and try again, or maybe put it to deep sleep
      ESP.restart();
      delay(5000);
    }

    //if you get here you have connected to the WiFi
    Serial.println("connected...yeey :)");

  }
  }
}