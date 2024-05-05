const int pin = 9;
 
void setup()
{
  Serial.begin(9600);    //iniciar puerto serie
  pinMode(pin, OUTPUT);  //definir pin como salida
}
 
void loop()
{
  digitalWrite(pin, HIGH);   // poner el Pin en HIGH
  delay(5000);               // esperar diez segundos
  digitalWrite(pin, LOW);    // poner el Pin en LOW
  delay(5000);               // esperar diez segundos
}