#include <TimerOne.h>

#define PERIODO 1
#define PIN_LED 9
const int sensorPin = A0;

// Parámetros del controlador PID
float Kp = 0.15327;
float Ki = 0.0005448;
float Kd = 0;

int setpoint;  // Temperatura de referencia en grados Celsius

float previousError = 0;
float integral = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(PIN_LED, OUTPUT);
  setpoint = 32;  // Temperatura de referencia en grados Celsius
  Timer1.initialize(PERIODO * 1000);

  //int duty = 40; // Inicializa con un ciclo de trabajo del 40%
  //Timer1.pwm(PIN_LED, 1023L * duty / 100L);
}

void loop()
{
  int value = analogRead(sensorPin);
  float celsius = ((value / 1023.0) * 500)-4;

  // Calcula el error
  float error = setpoint - celsius;

  // Calcula la parte proporcional (P)
  float P = Kp * error;

  // Calcula la parte integral (I)
  integral += Ki * error;

  // Calcula la parte derivativa (D)
  float derivative = Kd * (error - previousError);

  // Calcula la salida del controlador PID
  float output = (P + integral + derivative)*(-10);

  // Ajusta el ciclo de trabajo del LED según la salida del controlador PID
  int duty = constrain(map(output, -10, 10, 0.0, 100.0), 0.0, 100.0);
  Timer1.pwm(PIN_LED, 1023L * duty / 100L);

  // Actualiza el error anterior
  previousError = error;

  // Imprime información en el Monitor Serie
  //Serial.print("Temperatura: ");
  /*Serial.print(celsius);
  Serial.print(",");
  Serial.print(" C - Salida PID: ");
  Serial.print(output);
  Serial.print(" % Duty: ");
  Serial.println(duty);*/
  Serial.print(",");
  Serial.print(celsius);
  /*Serial.print(",");
  Serial.print(Vc2);
  Serial.print(",");
  Serial.print(er_v);
  Serial.print(",");
  Serial.print(Vc2ref);
  Serial.print(",");
  Serial.println();*/
  delay(1000);
}
