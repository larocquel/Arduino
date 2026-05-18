const int pinoIR = 7;

void setup() {
  // Inicializa a via de comunicação com o computador
  Serial.begin(9600);  
  
  // Configura o pino apenas como ENTRADA, pois o sensor resolve o resto sozinho
  pinMode(pinoIR, INPUT);
}

void loop() {
  // Lê o estado atual enviado pelo sensor (HIGH ou LOW)
  int estadoIR = digitalRead(pinoIR);

  // Exibe o resultado no monitor
  if (estadoIR == HIGH) {
    Serial.println("Preto!");
  } else {
    Serial.println("Branco!");
  }

  // Pequena pausa para não inundar o monitor serial com texto rápido demais
  delay(200); 
}