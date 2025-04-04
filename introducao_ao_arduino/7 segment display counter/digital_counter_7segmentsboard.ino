int pinoA = 6;
int pinoB = 7;
int pinoC = 8;
int pinoD = 9;
int pinoE = 10;
int pinoF = 5;
int pinoG = 4;

void setup()
{
  pinMode(pinoA, OUTPUT);
  pinMode(pinoB, OUTPUT);
  pinMode(pinoC, OUTPUT);
  pinMode(pinoD, OUTPUT);
  pinMode(pinoE, OUTPUT);
  pinMode(pinoF, OUTPUT);
  pinMode(pinoG, OUTPUT);
}

void loop(){
  // PARA O DIGITO 0
  digitalWrite(pinoA, HIGH);
  digitalWrite(pinoB, HIGH);
  digitalWrite(pinoC, HIGH);
  digitalWrite(pinoD, HIGH);
  digitalWrite(pinoE, HIGH);
  digitalWrite(pinoF, HIGH);
  delay(1000); 
  apagarLed();
  // PARA O DIGITO 1
  digitalWrite(pinoB, HIGH);
  digitalWrite(pinoC, HIGH);
  delay(1000);
  apagarLed();
  // PARA O DIGITO 2
  digitalWrite(pinoA, HIGH);
  digitalWrite(pinoB, HIGH);
  digitalWrite(pinoG, HIGH);
  digitalWrite(pinoE, HIGH);
  digitalWrite(pinoD, HIGH);
  delay(1000); 
  apagarLed();
  // PARA O DIGITO 3
  digitalWrite(pinoA, HIGH);
  digitalWrite(pinoB, HIGH);
  digitalWrite(pinoG, HIGH);
  digitalWrite(pinoC, HIGH);
  digitalWrite(pinoD, HIGH);
  delay(1000); 
  apagarLed();
  // PARA O DIGITO 4
  digitalWrite(pinoB, HIGH);
  digitalWrite(pinoC, HIGH);
  digitalWrite(pinoF, HIGH);
  digitalWrite(pinoG, HIGH);
  delay(1000); 
  apagarLed();
  // PARA O DIGITO 5
  digitalWrite(pinoA, HIGH);
  digitalWrite(pinoC, HIGH);
  digitalWrite(pinoD, HIGH);
  digitalWrite(pinoF, HIGH);
  digitalWrite(pinoG, HIGH);
  delay(1000); 
  apagarLed();
  // PARA O DIGITO 6
  digitalWrite(pinoC, HIGH);
  digitalWrite(pinoD, HIGH);
  digitalWrite(pinoE, HIGH);
  digitalWrite(pinoF, HIGH);
  digitalWrite(pinoG, HIGH);
  delay(1000); 
  apagarLed();
  // PARA O DIGITO 7
  digitalWrite(pinoA, HIGH);
  digitalWrite(pinoB, HIGH);
  digitalWrite(pinoC, HIGH);
  delay(1000); 
  apagarLed();
  // PARA O DIGITO 8
  digitalWrite(pinoA, HIGH);
  digitalWrite(pinoB, HIGH);
  digitalWrite(pinoC, HIGH);
  digitalWrite(pinoD, HIGH);
  digitalWrite(pinoE, HIGH);
  digitalWrite(pinoF, HIGH);
  digitalWrite(pinoG, HIGH);
  delay(1000); 
  apagarLed();
  // PARA O DIGITO 9
  digitalWrite(pinoA, HIGH);
  digitalWrite(pinoB, HIGH);
  digitalWrite(pinoC, HIGH);
  digitalWrite(pinoG, HIGH);
  digitalWrite(pinoF, HIGH);
  delay(1000); 
  apagarLed();
}

void apagarLed() {
  // apaga todos os leds do display
  digitalWrite(pinoA, LOW);
  digitalWrite(pinoB, LOW);
  digitalWrite(pinoC, LOW);
  digitalWrite(pinoD, LOW);
  digitalWrite(pinoE, LOW);
  digitalWrite(pinoF, LOW);
  digitalWrite(pinoG, LOW);
}

// RESULTADO: o placar vai contar de 0 a 9 e reiniciar a contagem infinitamente;
// RESULT: the scoreboard will count from 0 to 9 and restart counting infinitely;
