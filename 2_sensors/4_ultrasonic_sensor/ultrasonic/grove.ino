int pinoSig = 8; // O nosso único pino de comunicação

void setup() {
  // Iniciamos a comunicação de texto com o computador
  Serial.begin(9600); 
}

void loop() {
  // 1. MODO EMISSOR (Falar)
  pinMode(pinoSig, OUTPUT); // Transformamos o pino em Saída
  digitalWrite(pinoSig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinoSig, HIGH); // Dispara o som
  delayMicroseconds(10);
  digitalWrite(pinoSig, LOW);
  
  // 2. MODO RECETOR (Ouvir)
  pinMode(pinoSig, INPUT); // Transformamos o pino em Entrada rapidamente!
  long duracao = pulseIn(pinoSig, HIGH); // Mede o tempo do eco
  
  // 3. A MATEMÁTICA
  int distancia = duracao * 0.034 / 2;
  
  // 4. Imprimimos o resultado no Monitor Serial
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
  
  delay(500); // Espera meio segundo antes de medir de novo
}