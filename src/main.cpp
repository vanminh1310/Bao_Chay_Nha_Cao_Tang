// DATN_LTN_TDH57
// Canh báo chay cho nha cao tang

//Khai bao thu vien
#include <Arduino.h>
#include <Tone32.h>
#include<WiFi.h>
#include <WiFiUdp.h>
#include <FirebaseESP32.h>
#include "main.h"

//
#include <Wire.h>
#define FIREBASE_HOST "vann-53570.firebaseio.com" // ten host cua firebase
#define FIREBASE_AUTH "LC6fDYVqNO7VVBfoymADdWtLZVl6jr6WVJxhONrF" // ma 
#define WIFI_SSID "Joy"
#define WIFI_PASSWORD "012345678"
FirebaseData firebaseData; // firebase datbase

// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// dth11
// #include<DHT.h>
// // #define DHTPIN 0
// #define DHTTYPE DHT11   // DHT 11
// DHT dht(DHTPIN, DHTTYPE);

//timer 
const unsigned long even = 100;
unsigned long pretime = 0;
unsigned long pretime1 = 0;
unsigned long pretime2 = 0;


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

#include <dht_nonblocking.h>

#define DHT_SENSOR_TYPE DHT_TYPE_11
static const int DHT_SENSOR_PIN = 5;

DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );




// setup
void setup()
{
  Serial.begin(9600);
  pinMode(ledgr,OUTPUT);
  pinMode(ledred,OUTPUT);

  // dht.begin();

  WiFi.begin(WIFI_SSID ,WIFI_PASSWORD);

  while ( WiFi.status() != WL_CONNECTED ) {
    digitalWrite(ledred,HIGH);
    delay ( 500 );
    digitalWrite(ledred,LOW);
    delay ( 500 );
    Serial.print ( "." );
  }
  digitalWrite(ledgr,HIGH);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  


}

static bool measure_environment( float *temperature, float *humidity )
{
  static unsigned long measurement_timestamp = millis( );

  if( millis( ) - measurement_timestamp > 1000 )
  {
    if( dht_sensor.measure( temperature, humidity ) == true )
    {
      measurement_timestamp = millis( );
      return( true );
    }
  }
  return( false );
}


// ham doc khi ga
void Gas(void)
{
  // int gas = analogRead(Gas_analog);
  int gas_digital = digitalRead(Gas_digital);
  Firebase.setInt(firebaseData,"Floors1/G",gas_digital);
  // Serial.print("Khi gas: ");
  // Serial.println(gas);
  Serial.print("Gas Class: ");
  Serial.print(gas_digital);
  Serial.println("");
 
   if (gas_digital==0)

  {
    
    buzzer();

  }
 

}

void Fire(){
 
  //  int fire_analog = analogRead(Fire_analog);
   int fire_digital = digitalRead(Fire_digital);
  Firebase.setInt(firebaseData,"Floors1/F",fire_digital);
  // Serial.print("Fire: ");
  // Serial.println(fire_analog);
  Serial.print("Fire Class: ");
  Serial.print(fire_digital);
 Serial.println("");
 
  if (fire_digital == 0)

  {
   
    buzzer();
    
  }
   
  
}
// void dth11(){
//   float h = dht.readHumidity();    
//   float t = dht.readTemperature(); 
//   Firebase.setFloat(firebaseData,"Floors1/T",t);
//   Firebase.setFloat(firebaseData,"Floors1/H",h);

//   Serial.print("Nhiet do: ");
//   Serial.println(t);               
//   Serial.print("Do am: ");
//   Serial.println(h);              
 
// }




//vong lap
void loop()
{ 
  float temperature;
  float humidity;
  if( measure_environment( &temperature, &humidity ) == true )
  {
   
    Serial.print( "Temperature = " );
    Serial.print( temperature, 1 );
     Firebase.setFloat(firebaseData,"Floors1/T",temperature);
    Serial.print( " *C,tHumidity = " );
    Serial.print( humidity, 1 );
    Serial.println( "%" );
     Firebase.setFloat(firebaseData,"Floors1/H",humidity);
      Fire();
    Gas();
   
  }
  

    
  
 
}



    