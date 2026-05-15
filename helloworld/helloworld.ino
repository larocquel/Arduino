const int ledPin = 13;

void setup()
{
  // Configure the pin 13 as an energy OUTPUT
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  digitalWrite(ledPin, HIGH); // Sends 5V (Turn ON the LED)
  delay(10000);                 // Delays the processor for N milisseconds

  digitalWrite(ledPin, LOW);
  delay(10000);

}
