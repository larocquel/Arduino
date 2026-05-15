void setup() {
  // Configure the inside pin of the LED as OUTPUT
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // Turns ON the LED
  delay(1000);                      // Waits 1 second (1000 miliseconds)
  digitalWrite(LED_BUILTIN, LOW);   // Turn OFF the LED
  delay(1000);
}
