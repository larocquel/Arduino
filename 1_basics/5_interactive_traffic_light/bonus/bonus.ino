// Definir os pinos
int botaoVermelho = 2;
int botaoAmarelo = 3;
int botaoVerde = 4;

int ledVermelho = 10;
int ledAmarelo = 11;
int ledVerde = 12;

void setup() {
  // Configurar os LEDs como SAÍDA
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  
  // Configurar o Botão como ENTRADA com o resistor interno ativado
  pinMode(botaoVermelho, INPUT_PULLUP);
  pinMode(botaoAmarelo, INPUT_PULLUP);
  pinMode(botaoVerde, INPUT_PULLUP);
}

void loop() {
  // O Arduino fica o tempo todo a "vigiar" o estado do botão
  int estadobotaoVermelho = digitalRead(botaoVermelho);
  int estadobotaoAmarelo = digitalRead(botaoAmarelo);
  int estadobotaoVerde = digitalRead(botaoVerde);

  // Lembra-se? LOW significa que o botão foi pressionado!
  if (estadobotaoVermelho == LOW) {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH); 
  } else if (estadobotaoAmarelo == LOW) {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
  } else if (estadobotaoVerde == LOW) {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
  }
}