// DATN_LTN_TDH57
// Canh báo chay cho nha cao tang

//Khai bao thu vien
#include <Arduino.h>
#include <Tone32.h>
#define BUZZER_PIN 25
#define BUZZER_CHANNEL 0
// Khai bao chan
// khai bao chan cam bien
int Gas_analog = 15;
int Gas_digital = 23;
int Fire_analog = 4;
int Fire_digital = 2;
//Khai bao ngoai vi 
int buzz = 33;
int ledgr = 32;






// setup
void setup()
{
  Serial.begin(9600);
  pinMode(ledgr,OUTPUT);
  


}
// ham doc khi ga
void Gas()
{
  int gas = analogRead(Gas_analog);
  int gas_digital = digitalRead(Gas_digital);

  Serial.print("Khi gas: ");
  Serial.println(gas);
  Serial.print("\t");
  Serial.print("Gas Class: ");
  Serial.print(gas_digital);
  Serial.print("\t");
  Serial.print("\t");
   if (gas >500)

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
  delay(500);
}

void Fire(){
   int fire_analog = analogRead(Fire_analog);
   int fire_digital = digitalRead(Fire_digital);
  Serial.print("Fire: ");
  Serial.println(fire_analog);
  Serial.print("\t");
  Serial.print("Fire Class: ");
  Serial.print(fire_digital);
  Serial.print("\t");
  Serial.print("\t");
  delay(500); 
  if (fire_analog < 4095)

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


//vong lap
void loop()
{
  Gas();
  Fire();
}

