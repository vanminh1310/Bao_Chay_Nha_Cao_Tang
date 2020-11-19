// DATN_LTN_TDH57
// Canh báo chay cho nha cao tang

//Khai bao thu vien
#include <Arduino.h>
#include <Tone32.h>
#include<WiFi.h>
#include <WiFiUdp.h>
#include <FirebaseESP32.h>

//
#include <Wire.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>


// #define SCREEN_WIDTH 128
// #define SCREEN_HEIGHT 64


#define FIREBASE_HOST "vann-53570.firebaseio.com" // ten host cua firebase
#define FIREBASE_AUTH "LC6fDYVqNO7VVBfoymADdWtLZVl6jr6WVJxhONrF" // ma 
#define WIFI_SSID "Joy"
#define WIFI_PASSWORD "012345678"
FirebaseData firebaseData; // firebase datbase

// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// dth11
#include<DHT.h>
#define DHTPIN 5
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

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
int Gas_digital = 23;
int Fire_analog = 4;
int Fire_digital = 2;
//Khai bao ngoai vi 
int ledred = 33;
int ledgr = 32;






// setup
void setup()
{
  Serial.begin(9600);
  pinMode(ledgr,OUTPUT);
  pinMode(ledred,OUTPUT);
  // dislay
  dht.begin();
  // display.begin(SSD1306_SWITCHCAPVCC, 0x78>>1);
  // display.display();
  // delay(2000);
  // display.clearDisplay();
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
// ham doc khi ga
void Gas(void)
{
  int gas = analogRead(Gas_analog);
  int gas_digital = digitalRead(Gas_digital);
  
  Firebase.setInt(firebaseData,"Floors1/G",gas_digital);
  Serial.print("Khi gas: ");
  Serial.println(gas);
  Serial.print("\t");
  Serial.print("Gas Class: ");
  Serial.print(gas_digital);
  Serial.print("\t");
  Serial.print("\t");
   if (gas_digital==0)

  {
    

     tone(BUZZER_PIN,4058,125,0);
    tone(BUZZER_PIN,4058,250,0);
    tone(BUZZER_PIN,4058,125,0);
    tone(BUZZER_PIN,4058,125,0);
    tone(BUZZER_PIN,4058,250,0);
    tone(BUZZER_PIN,4058,125,0);
    tone(BUZZER_PIN,4058,125,0);
    tone(BUZZER_PIN,4058,250,0);
    tone(BUZZER_PIN,4058,125,0);
    tone(BUZZER_PIN,4058,125,0);
    tone(BUZZER_PIN,4058,250,0);
    tone(BUZZER_PIN,4058,125,0);

  }
 

}

void Fire(){
 
   int fire_analog = analogRead(Fire_analog);
   int fire_digital = digitalRead(Fire_digital);
   
    Firebase.setInt(firebaseData,"Floors1/F",fire_digital);
 
  Serial.print("Fire: ");
  Serial.println(fire_analog);
  Serial.print("\t");
  Serial.print("Fire Class: ");
  Serial.print(fire_digital);
  Serial.print("\t");
  Serial.print("\t");
 
  if (fire_digital == 0)

  {
    
    tone(BUZZER_PIN,4058,125,0);
    tone(BUZZER_PIN,4058,250,0);
    tone(BUZZER_PIN,4058,125,0);
    tone(BUZZER_PIN,4058,125,0);
    tone(BUZZER_PIN,4058,250,0);
    tone(BUZZER_PIN,4058,125,0);
    tone(BUZZER_PIN,4058,125,0);
    tone(BUZZER_PIN,4058,250,0);
    tone(BUZZER_PIN,4058,125,0);
    tone(BUZZER_PIN,4058,125,0);
    tone(BUZZER_PIN,4058,250,0);
    tone(BUZZER_PIN,4058,125,0);

    
  }
   
  
}
void dth11(){
  float h = dht.readHumidity();    
  float t = dht.readTemperature(); 
  Firebase.setFloat(firebaseData,"Floors1/T",t);
  Firebase.setFloat(firebaseData,"Floors1/H",h);

  Serial.print("Nhiet do: ");
  Serial.println(t);               
  Serial.print("Do am: ");
  Serial.println(h);  
              
  Serial.println();     



  
  // display.setTextSize(1);
  // display.setCursor(3,0);
  // display.println("Temperature/Humidity");
  // display.setTextSize(2);
  // display.setTextColor(WHITE);
  // display.setCursor(52,10);
  // display.print(t);
  // display.println("C");
  // display.setCursor(52,30);
  // display.print(h);
  // display.println("%");
  // display.setTextSize(1);
  // display.setCursor(52,50);
  // display.println("VanMinh");
  // display.display();
  // display.clearDisplay();          
  // delay(200);    
}




//vong lap
void loop()
{
  unsigned long crtime = millis();
    if (crtime - pretime >= even)
    {
      Gas();
      pretime = crtime;
    }
    if (crtime- pretime1 >= 105)
    {
      Fire();
      pretime1= crtime;
    }
    if (crtime - pretime2>=1000)
    {
      dth11();
      pretime2 = crtime;
    }
    
    
    
 
  // Fire();
  // // dth11();
  // Gas();
  // // digitalWrite(ledred,HIGH);
  // // digitalWrite(ledgr,HIGH);
}

