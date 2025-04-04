int pinoVelEsq = 3;		//define a velocidade, de 0 a 255
int pinoVelDir = 6;		//define a velocidade, de 0 a 255
int pinoEsqHora = 4;	//liga o motor esquerdo sentido horário
int pinoEsqAnti = 2;	//liga o motor esquerdo sentido anti-horário
int pinoDirHora = 5;	//liga o motor direito sentido horário
int pinoDirAnti = 7;	//liga o motor direito sentido anti-horário

void setup(){
  pinMode(pinoVelEsq, OUTPUT);
  pinMode(pinoVelDir, OUTPUT);
  pinMode(pinoEsqHora, OUTPUT);
  pinMode(pinoEsqAnti, OUTPUT);
  pinMode(pinoDirHora, OUTPUT);
  pinMode(pinoDirAnti, OUTPUT);
}

void loop(){
  paraFrente(100);
  delay(3000);
  parar();
  delay(1000);
  girarEsq();
  delay(3000);
  parar();
  delay(1000);
  girarDir(); // Adicionando a chamada para a função de girar à direita
  delay(3000);
  parar();
  delay(1000);
}

void parar(){
  digitalWrite(pinoEsqHora, LOW);
  digitalWrite(pinoEsqAnti, LOW);
  digitalWrite(pinoDirHora, LOW);
  digitalWrite(pinoDirAnti, LOW);
}

void paraFrente(int velocidade){
  //PARA FRENTE EM % PORCENTO
  //Chama a função dando um valor de 0 a 100
  int velFinal = map(velocidade, 0, 100, 85, 255);
  digitalWrite(pinoEsqHora, HIGH);
  digitalWrite(pinoEsqAnti, LOW);
  digitalWrite(pinoDirHora, HIGH);
  digitalWrite(pinoDirAnti, LOW);
  analogWrite(pinoVelEsq, velFinal);
  analogWrite(pinoVelDir, velFinal);
}

void girarEsq(){
  //Motor da esq para frente, da dir para trás
  digitalWrite(pinoEsqHora, HIGH);
  digitalWrite(pinoEsqAnti, LOW);
  digitalWrite(pinoDirHora, LOW);
  digitalWrite(pinoDirAnti, HIGH);
  analogWrite(pinoVelEsq, 128);
  analogWrite(pinoVelDir, 128);
}

void girarDir(){
  //Motor da esq para trás, da dir para frente
  digitalWrite(pinoEsqHora, LOW);
  digitalWrite(pinoEsqAnti, HIGH);
  digitalWrite(pinoDirHora, HIGH);
  digitalWrite(pinoDirAnti, LOW);
  analogWrite(pinoVelEsq, 128);
  analogWrite(pinoVelDir, 128);
}

// RESULTADO ESPERADO:Este código Arduino controla um robô de duas rodas. Ele define pinos para controlar a velocidade e a direção de dois motores (esquerdo e direito). A função loop faz o robô ir para frente por 3 segundos, parar por 1 segundo, virar à esquerda por 3 segundos e parar novamente, repetindo essa sequência. O código inclui funções para fazer o robô ir para frente em uma velocidade específica, virar à esquerda e parar ambos os motores.
// EXPECTED RESULT: This Arduino code controls a two-wheeled robot. It defines pins for controlling the speed and direction of two motors (left and right). The loop function makes the robot move forward for 3 seconds, then stop for 1 second, then turn left for 3 seconds, and finally stop again, repeating this sequence. The code includes functions to make the robot move forward at a specified speed, turn left, and stop both motors.
