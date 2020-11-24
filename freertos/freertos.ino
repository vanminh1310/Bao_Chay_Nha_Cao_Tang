#include "main.h"
TaskHandle_t Task1;
TaskHandle_t Task2;



void setup() {
  Serial.begin(9600);
  pinMode(ledgr, OUTPUT);
  pinMode(ledred, OUTPUT);

  dht.begin();

  WiFi.begin(WIFI_SSID , WIFI_PASSWORD);

  while ( WiFi.status() != WL_CONNECTED ) {
    digitalWrite(ledred, HIGH);
    delay ( 500 );
    digitalWrite(ledred, LOW);
    delay ( 500 );
    Serial.print ( "." );
  }
  digitalWrite(ledgr, HIGH);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  //create a task that will be executed in the Task1code() function, with priority 1 and executed on core 0
  xTaskCreatePinnedToCore(
    Task1code,   /* Task function. */
    "Task1",     /* name of task. */
    10000,       /* Stack size of task */
    NULL,        /* parameter of the task */
    5,           /* priority of the task  độ ưu tiên*/ 
    &Task1,      /* Task handle to keep track of created task */
    0);          /* pin task to core 0 */

delay(500);
  //create a task that will be executed in the Task2code() function, with priority 1 and executed on core 1
  xTaskCreatePinnedToCore(
    Task2code,   /* Task function. */
    "Task2",     /* name of task. */
    10000,       /* Stack size of task */
    NULL,        /* parameter of the task */
    2,           /* priority of the task */
    &Task2,      /* Task handle to keep track of created task */
    1);          /* pin task to core 1 */
  delay(500);
}

//Task1code: blinks an LED every 1000 ms
void Task1code( void * pvParameters ) {
  Serial.print("Task1 running on core ");
  Serial.println(xPortGetCoreID());

  for (;;) {



    int gas_digital = digitalRead(Gas_digital);
    Firebase.setInt(firebaseData, "Floors1/G", gas_digital);
    int fire_digital = digitalRead(Fire_digital);
    Firebase.setInt(firebaseData, "Floors1/F", fire_digital);
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    Firebase.setFloat(firebaseData, "Floors1/T", t);
    Firebase.setFloat(firebaseData, "Floors1/H", h);
    //
   

  }


}


//Task2code: blinks an LED every 700 ms
void Task2code( void * pvParameters ) {
  Serial.print("Task2 running on core ");
  Serial.println(xPortGetCoreID());

  for (;;) {
    float h = dht.readHumidity();
    float t = dht.readTemperature();
     Serial.print("Nhiet do: ");
    Serial.println(t);
    Serial.print("Do am: ");
    Serial.println(h);


    int fire_digital = digitalRead(Fire_digital);
    Firebase.setInt(firebaseData, "Floors1/F", fire_digital);
    int gas_digital = digitalRead(Gas_digital);
    Firebase.setInt(firebaseData, "Floors1/G", gas_digital);
    // Serial.print("Khi gas: ");
    // Serial.println(gas);
    Serial.print("Gas Class: ");
    Serial.print(gas_digital);
    Serial.println("");
    Serial.print("Fire Class: ");
    Serial.print(fire_digital);
    Serial.println("");

    if (gas_digital == 0||fire_digital == 0)

    {

      buzzer();

    }


  }

 
}

void loop() {

}
