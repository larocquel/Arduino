// Definir os pinos
int pinoBotao = 2;
int pinoVerde = 10;
int pinoAmarelo = 11;
int pinoVermelho = 12;

void setup() {
  // Configurar os LEDs como SAÍDA
  pinMode(pinoVerde, OUTPUT);
  pinMode(pinoAmarelo, OUTPUT);
  pinMode(pinoVermelho, OUTPUT);
  
  // Configurar o Botão como ENTRADA com o resistor interno ativado
  pinMode(pinoBotao, INPUT_PULLUP);
  
  // Condição inicial: O semáforo começa Verde para os carros
  digitalWrite(pinoVerde, HIGH);
}

void loop() {
  // O Arduino fica o tempo todo a "vigiar" o estado do botão
  int estadoBotao = digitalRead(pinoBotao);

  // Lembra-se? LOW significa que o botão foi pressionado!
  if (estadoBotao == LOW) { 
    
    // 1. Alguém apertou o botão! Esperamos 1 segundo antes de mudar
    delay(1000);

    // 2. Apaga o Verde e liga o Amarelo (Atenção carros!)
    digitalWrite(pinoVerde, LOW);
    digitalWrite(pinoAmarelo, HIGH);
    delay(2000); // Fica amarelo por 2 segundos

    // 3. Apaga o Amarelo e liga o Vermelho (Podem atravessar!)
    digitalWrite(pinoAmarelo, LOW);
    digitalWrite(pinoVermelho, HIGH);
    delay(5000); // Fica vermelho por 5 segundos para a travessia

    // 4. A travessia acabou. Apaga o Vermelho e volta ao Verde
    digitalWrite(pinoVermelho, LOW);
    digitalWrite(pinoVerde, HIGH);
    
    // O código volta ao início do loop e fica à espera do próximo aperto de botão
  }
}