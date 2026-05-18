int pinoBotao = 2; // O botão está ligado ao pino 2
int pinoLED = 13;  // O LED continua no pino 13

void setup() {
  pinMode(pinoLED, OUTPUT); 
  // Configura o pino 2 como ENTRADA e liga o resistor interno do Arduino
  pinMode(pinoBotao, INPUT_PULLUP); 
}

void loop() {
  // O Arduino "lê" o estado do botão (HIGH ou LOW)
  int estadoBotao = digitalRead(pinoBotao);

  // Lembra-te: Com o PULLUP, pressionar o botão dá sinal LOW!
  if (estadoBotao == LOW) {
    digitalWrite(pinoLED, HIGH); // Liga o LED
  } else {
    digitalWrite(pinoLED, LOW);  // Desliga o LED
  }
}