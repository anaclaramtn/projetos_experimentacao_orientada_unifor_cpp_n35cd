int pinoVelEsq = 3;
int pinoVelDir = 6;
int pinoEsqHora = 4;
int pinoEsqAnti = 2;
int pinoDirHora = 5;
int pinoDirAnti = 7;
// PRETO = LOW (0) E BRANCO = HIGH (1)
int sensorDireitaPin = A0;
int sensorCentroPin = A1;
int sensorEsquerdaPin = A2;
int velBase = 200; // Velocidade base para seguir a linha
int velCurvaSuave = 150; // Velocidade para curvas suaves

void setup(){
  pinMode(pinoVelEsq, OUTPUT);
  pinMode(pinoVelDir, OUTPUT);
  pinMode(pinoEsqHora, OUTPUT);
  pinMode(pinoEsqAnti, OUTPUT);
  pinMode(pinoDirHora, OUTPUT);
  pinMode(pinoDirAnti, OUTPUT);
  pinMode(sensorDireitaPin, INPUT_PULLUP); // Configura pinos como entrada com pull-up
  pinMode(sensorCentroPin, INPUT_PULLUP);
  pinMode(sensorEsquerdaPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop(){
  // Leitura dos sensores
  bool sensorDireita = !digitalRead(sensorDireitaPin);
  bool sensorCentro = !digitalRead(sensorCentroPin);
  bool sensorEsquerda = !digitalRead(sensorEsquerdaPin);

if (sensorCentro == true && sensorDireita == false && sensorEsquerda == false) {
    Serial.println("Frente");
    moverMotorDir(velBase, true);
    moverMotorEsq(velBase, true);
  }
  else if (sensorEsquerda == true && sensorCentro == false && sensorDireita == false) {
    Serial.println("Esquerda");
    moverMotorDir(velBase, true);
    moverMotorEsq(0, true);
  }
  else if (sensorDireita == true && sensorCentro == false && sensorEsquerda == false) {
    Serial.println("Direita");
    moverMotorDir(0, true);
    moverMotorEsq(velBase, true);
  }
  else if (sensorEsquerda == true && sensorCentro == true && sensorDireita == false) {
    Serial.println("Suave para direita");
    moverMotorDir(velBase, true);
    moverMotorEsq(velCurvaSuave, true);
  }
  else if (sensorDireita == true && sensorCentro == true && sensorEsquerda == false) {
    Serial.println("Suave para esquerda");
    moverMotorDir(velCurvaSuave, true);
    moverMotorEsq(velBase, true);
  }
  else if (sensorEsquerda == true && sensorDireita == true && sensorCentro == false) {
    Serial.println("Cruzamento/Linha Grossa - Reto");
    moverMotorDir(velBase, true);
    moverMotorEsq(velBase, true);
  } else {
    Serial.println("Perdido");
    
  }

void moverMotorEsq(int velocidade, bool praFrente){
  analogWrite(pinoVelEsq, velocidade);
  if(praFrente){
    digitalWrite(pinoEsqHora, HIGH);
    digitalWrite(pinoEsqAnti, LOW);
  } else {
    digitalWrite(pinoEsqHora, LOW);
    digitalWrite(pinoEsqAnti, HIGH);
  }
}

void moverMotorDir(int velocidade, bool praFrente){
  analogWrite(pinoVelDir, velocidade);
  if(praFrente){
    digitalWrite(pinoDirHora, HIGH);
    digitalWrite(pinoDirAnti, LOW);
  } else {
    digitalWrite(pinoDirHora, LOW);
    digitalWrite(pinoDirAnti, HIGH);
  }
}

void pararMotores(){
  digitalWrite(pinoEsqHora, LOW);
  digitalWrite(pinoEsqAnti, LOW);
  digitalWrite(pinoDirHora, LOW);
  digitalWrite(pinoDirAnti, LOW);
  analogWrite(pinoVelEsq, 0);
  analogWrite(pinoVelDir, 0);
}
