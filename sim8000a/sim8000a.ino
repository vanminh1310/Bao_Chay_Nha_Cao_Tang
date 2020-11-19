#include <Tone32.h>
#include<WiFi.h>
#include <WiFiUdp.h>
#include <FirebaseESP32.h>
#include <Wire.h>
#define FIREBASE_HOST "vann-53570.firebaseio.com" // ten host cua firebase
#define FIREBASE_AUTH "LC6fDYVqNO7VVBfoymADdWtLZVl6jr6WVJxhONrF" // ma 
#define WIFI_SSID "Joy"
#define WIFI_PASSWORD "012345678"
FirebaseData firebaseData; // 
//sim800l
#include "Adafruit_FONA.h"
#define SIM800L_RX     27
#define SIM800L_TX     26
#define SIM800L_PWRKEY 4
#define SIM800L_RST    5
#define SIM800L_POWER  23
char* sdt;
char replybuffer[255];
HardwareSerial *sim800lSerial = &Serial1;
Adafruit_FONA sim800l = Adafruit_FONA(SIM800L_PWRKEY);

uint8_t readline(char *buff, uint8_t maxbuff, uint16_t timeout = 0);

#define LED_BLUE  13
#define RELAY 14



void setup()
{
 sdt="+84388424530";
  pinMode(LED_BLUE, OUTPUT);
  pinMode(RELAY, OUTPUT);
  pinMode(SIM800L_POWER, OUTPUT);

  digitalWrite(LED_BLUE, HIGH);
  digitalWrite(SIM800L_POWER, HIGH);

  Serial.begin(115200);
  Serial.println(F("ESP32 with GSM SIM800L"));
  Serial.println(F("Initializing....(May take more than 10 seconds)"));
  
  delay(10000);

  // Make it slow so its easy to read!
  sim800lSerial->begin(4800, SERIAL_8N1, SIM800L_TX, SIM800L_RX);
  if (!sim800l.begin(*sim800lSerial)) {
    Serial.println(F("Couldn't find GSM SIM800L"));
    while (1);
  }
  Serial.println(F("GSM SIM800L is OK"));

  char imei[16] = {0}; // MUST use a 16 character buffer for IMEI!
  uint8_t imeiLen = sim800l.getIMEI(imei);
  if (imeiLen > 0) {
    Serial.print("SIM card IMEI: "); Serial.println(imei);
  }

  // Set up the FONA to send a +CMTI notification
  // when an SMS is received
  sim800lSerial->print("AT+CNMI=2,1\r\n");

  Serial.println("GSM SIM800L Ready");


  WiFi.begin(WIFI_SSID ,WIFI_PASSWORD);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
     
}
  

    


long prevMillis = 0;
int interval = 1000;

boolean ledState = false;

void loop()
{
  if (millis() - prevMillis > interval) {
    ledState = !ledState;
    digitalWrite(LED_BLUE, ledState);

    prevMillis = millis();
  }

 if (sim800l.available()) // phai co ham nay nha
 {
//   
//      if (!sim800l.sendSMS(sdt, "Hello")) {
//          Serial.println(F("Failed"));
//        } else {
//          Serial.println(F("Sent!"));
//        }
//        delay(50000);
//      }

//if(Firebase.getFloat(firebaseData,"Floors1/T") ){
//    if (firebaseData.dataType() == "float"){
//      float *h = firebaseData.floatData();
//      Serial.println(h);
//    }
//    }
readGas();
readFire();
}
}
void readGas(){
  //lau1
  if(Firebase.getInt(firebaseData,"Floors1/G") ){
    if (firebaseData.dataType() == "int"){
      int g1 = firebaseData.intData();
      Serial.print("L1: ");
      Serial.println(g1);
      if(g1== 0){
        sim800l.sendSMS(sdt,"Floors1 Fire ");
        delay(10000);
        }
    }
    }
  //lau 2
  if(Firebase.getInt(firebaseData,"Floors2/G") ){
    if (firebaseData.dataType() == "int"){
      int g2 = firebaseData.intData();
      Serial.print("L2: ");
      Serial.println(g2);
      if(g2== 0){
        sim800l.sendSMS(sdt,"Floors2 Fire ");
        delay(10000);
        }
    }
    }
    //lau3
    if(Firebase.getInt(firebaseData,"Floors3/G") ){
    if (firebaseData.dataType() == "int"){
      int g3 = firebaseData.intData();
       Serial.print("L3: ");
      Serial.println(g3);
      if(g3== 0){
        sim800l.sendSMS(sdt,"Floors3 Fire ");
        delay(10000);
        }
    }
    }
    //lau4
    if(Firebase.getInt(firebaseData,"Floors4/G") ){
    if (firebaseData.dataType() == "int"){
      int g4 = firebaseData.intData();
      Serial.print("L4: ");
      Serial.println(g4);
      if(g4== 0){
        sim800l.sendSMS(sdt,"Floors4 Fire ");
        delay(10000);
        }
    }
    }
  
  }
  
void readFire(){
  //lau1
  if(Firebase.getInt(firebaseData,"Floors1/F") ){
    if (firebaseData.dataType() == "int"){
      int F1 = firebaseData.intData();
      Serial.print("F1: ");
      Serial.println(F1);
      if(F1== 0){
        sim800l.sendSMS(sdt,"Floors1 Fire ");
        delay(10000);
        }
    }
    }
  //lau 2
  if(Firebase.getInt(firebaseData,"Floors2/F") ){
    if (firebaseData.dataType() == "int"){
      int F2 = firebaseData.intData();
      Serial.print("F2: ");
      Serial.println(F2);
      if(F2== 0){
        sim800l.sendSMS(sdt,"Floors2 Fire ");
        delay(10000);
        }
    }
    }
    //lau3
    if(Firebase.getInt(firebaseData,"Floors3/F") ){
    if (firebaseData.dataType() == "int"){
      int F3 = firebaseData.intData();
       Serial.print("F3: ");
      Serial.println(F3);
      if(F3== 0){
        sim800l.sendSMS(sdt,"Floors3 Fire ");
        delay(10000);
        }
    }
    }
    //lau4
    if(Firebase.getInt(firebaseData,"Floors4/F") ){
    if (firebaseData.dataType() == "int"){
      int F4 = firebaseData.intData();
      Serial.print("F4: ");
      Serial.println(F4);
      if(F4== 0){
        sim800l.sendSMS(sdt,"Floors4 Fire ");
        delay(10000);
        }
    }
    }
  
  }
