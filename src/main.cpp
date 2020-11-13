// DATN_LTN_TDH57
// Canh báo chay cho nha cao tang

//Khai bao thu vien
#include <Arduino.h>

// Khai bao chan
int Gas_analog = 34;

// setup
void setup()
{
  Serial.begin(9600);
}
//vong lap
void loop()
{
  readGas();
}

// ham doc khi ga
void readGas()
{
  int gas = analogRead(Gas_analog);
  Serial.println("Khi gas: ", gas);
}