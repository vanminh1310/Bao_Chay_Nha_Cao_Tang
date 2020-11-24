
#include <Tone32.h>
#include<WiFi.h>
#include <WiFiUdp.h>
#include <FirebaseESP32.h>


#include <Wire.h>
#define FIREBASE_HOST "vann-53570.firebaseio.com" // ten host cua firebase
#define FIREBASE_AUTH "LC6fDYVqNO7VVBfoymADdWtLZVl6jr6WVJxhONrF" // ma 
#define WIFI_SSID "Joy"
#define WIFI_PASSWORD "012345678"
FirebaseData firebaseData; // firebase datb

//timer 



//buzzer
#define BUZZER_PIN 25
#define BUZZER_CHANNEL 0
// Khai bao chan
// khai bao chan cam bien
int Gas_analog = 15;
int Gas_digital = 2;
int Fire_analog = 4;
int Fire_digital = 23;
//Khai bao ngoai vi 
int ledred = 33;
int ledgr = 32;

 //dth11
 #include<DHT.h>
 #define DHTPIN 5
 #define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

//#include <dht_nonblocking.h>

//#define DHT_SENSOR_TYPE DHT_TYPE_11
//static const int DHT_SENSOR_PIN = 5;
//
//DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );

void buzzer(){
     tone(BUZZER_PIN,4058,125,0);
    // tone(BUZZER_PIN,4058,250,0);
//     tone(BUZZER_PIN,4058,125,0);
//     tone(BUZZER_PIN,4058,125,0);
//     tone(BUZZER_PIN,4058,250,0);
//     tone(BUZZER_PIN,4058,125,0);
//     tone(BUZZER_PIN,4058,125,0);
//     tone(BUZZER_PIN,4058,250,0);
//     tone(BUZZER_PIN,4058,125,0);
//     tone(BUZZER_PIN,4058,125,0);
//     tone(BUZZER_PIN,4058,250,0);
//     tone(BUZZER_PIN,4058,125,0);
//     tone(BUZZER_PIN,4058,125,0);
//     tone(BUZZER_PIN,4058,250,0);
//     tone(BUZZER_PIN,4058,125,0);
//     tone(BUZZER_PIN,4058,125,0);
//     tone(BUZZER_PIN,4058,250,0);
//     tone(BUZZER_PIN,4058,125,0);
//     tone(BUZZER_PIN,4058,125,0);
//     tone(BUZZER_PIN,4058,250,0);
//     tone(BUZZER_PIN,4058,125,0);
//     tone(BUZZER_PIN,4058,125,0);
//     tone(BUZZER_PIN,4058,250,0);
//     tone(BUZZER_PIN,4058,125,0);
    }
    
