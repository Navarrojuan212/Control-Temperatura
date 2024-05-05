#include <TimerOne.h>
#define PERIODO 1
#define PIN_LED 9
const int sensorPin= A0;
//#define heater1 3   //PWM
void setup()
{
  Serial.begin(9600);
    pinMode(PIN_LED, OUTPUT);

  Timer1.initialize(PERIODO * 5000000);//Timer1.initialize(1000000); un segundo
  
  int duty = 40; // 40% HIGH, 60% LOW
  Timer1.pwm(PIN_LED, 1023L * duty / 100L);
}

void loop()
{
  int value = analogRead(sensorPin);
  float celsius= ((value / 1023.0) * 500);
  Serial.print(celsius);
  Serial.println(" C");
  delay(1000);
}