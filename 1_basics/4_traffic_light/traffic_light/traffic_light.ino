// Damos nomes aos pinos para o código ficar mais fácil de ler
int pinoVerde = 10;
int pinoAmarelo = 11;
int pinoVermelho = 12;

void setup() {
  // Configuramos os três pinos como SAÍDA de energia
  pinMode(pinoVerde, OUTPUT);
  pinMode(pinoAmarelo, OUTPUT);
  pinMode(pinoVermelho, OUTPUT);
}

void loop() {
  // 1. Sinal Verde ABERTO
  digitalWrite(pinoVerde, HIGH);   // Liga o Verde
  delay(3000);                     // Espera 3 segundos
  digitalWrite(pinoVerde, LOW);    // Desliga o Verde
  
  // 2. Sinal Amarelo ATENÇÃO
  digitalWrite(pinoAmarelo, HIGH); // Liga o Amarelo
  delay(1000);                     // Espera 1 segundo
  digitalWrite(pinoAmarelo, LOW);  // Desliga o Amarelo
  
  // 3. Sinal Vermelho FECHADO
  digitalWrite(pinoVermelho, HIGH); // Liga o Vermelho
  delay(3000);                      // Espera 3 segundos
  digitalWrite(pinoVermelho, LOW);  // Desliga o Vermelho
  
  // O loop acaba e volta ao início (acendendo o Verde novamente)
}