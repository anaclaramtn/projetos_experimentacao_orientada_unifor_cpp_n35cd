int pinoVelEsq = 3;      // Define a velocidade do motor esquerdo (0 a 255)
int pinoVelDir = 6;      // Define a velocidade do motor direito (0 a 255)
int pinoEsqHora = 4;    // Liga o motor esquerdo no sentido horário
int pinoEsqAnti = 2;    // Liga o motor esquerdo no sentido anti-horário
int pinoDirHora = 5;    // Liga o motor direito no sentido horário
int pinoDirAnti = 7;    // Liga o motor direito no sentido anti-horário
int pinoTrig = 9;       // Pino trigger do sensor ultrassônico
int pinoEcho = 8;       // Pino echo do sensor ultrassônico

float distancia = 0;
float duracao = 0;

int menorDistNaBusca = 999; // Inicializa com um valor alto
int localDoInimigo = 0;    // Armazena o índice da menor distância

void setup() {
  pinMode(pinoVelEsq, OUTPUT);
  pinMode(pinoVelDir, OUTPUT);
  pinMode(pinoEsqHora, OUTPUT);
  pinMode(pinoEsqAnti, OUTPUT);
  pinMode(pinoDirHora, OUTPUT);
  pinMode(pinoDirAnti, OUTPUT);
  pinMode(pinoTrig, OUTPUT);
  pinMode(pinoEcho, INPUT);
  Serial.begin(9600);
  Serial.println("Iniciando busca...");
}

void loop() {
  // Resetar variáveis de busca a cada ciclo
  menorDistNaBusca = 999;
  localDoInimigo = 0;
  Serial.println("Nova busca...");

  // Girar para iniciar a busca (aproximadamente 45 graus para a esquerda)
  moverMotorEsq(128, false); // Girar motor esquerdo para trás
  moverMotorDir(128, true);  // Girar motor direito para frente
  delay(900);              // Ajustar este valor para uma rotação de ~45 graus

  // Buscar em um arco (18 incrementos de 500ms de rotação para a direita)
  Serial.println("Varrendo o ambiente...");
  for (int i = 0; i < 18; i++) {
    float dist = medeDist();
    Serial.print("Leitura ");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(dist);
    Serial.println(" cm");
    if (dist < menorDistNaBusca) {
      menorDistNaBusca = dist;
      localDoInimigo = i;
      Serial.print("Menor distância encontrada: ");
      Serial.print(menorDistNaBusca);
      Serial.print(" cm no índice: ");
      Serial.println(localDoInimigo);
    }
    // Girar um pouco para a direita para a próxima leitura
    moverMotorEsq(128, true);  // Girar motor esquerdo para frente
    moverMotorDir(128, false); // Girar motor direito para trás
    delay(500);
  }

  Serial.print("Menor distância final: ");
  Serial.print(menorDistNaBusca);
  Serial.print(" cm no índice: ");
  Serial.println(localDoInimigo);
  Serial.println("Girando para o alvo...");

  // Girar de volta para a posição onde a menor distância foi detectada
  // Desfaz a rotação inicial de 45 graus
  moverMotorEsq(128, true);
  moverMotorDir(128, false);
  delay(900);

  // Gira para a esquerda o número de incrementos necessários
  for (int i = 0; i < localDoInimigo; i++) {
    moverMotorEsq(128, false); // Girar para a esquerda
    moverMotorDir(128, true);
    delay(500);
  }
  pararMotores();
  delay(1000);

  Serial.println("Atacando!");
  paraFrente(255); // ATACAR!
  delay(3000);
  pararMotores();
  delay(2000);
  Serial.println("Fim do ataque, reiniciando busca.");
}

float medeDist() {
  // Disparando o ultrassom
  digitalWrite(pinoTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinoTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinoTrig, LOW);
  // Medindo o tempo de retorno
  duracao = pulseIn(pinoEcho, HIGH);
  distancia = (duracao * 0.0343) / 2;
  return distancia;
}

void moverMotorEsq(int velocidade, bool praFrente) {
  analogWrite(pinoVelEsq, velocidade);
  if (praFrente) {
    digitalWrite(pinoEsqHora, HIGH);
    digitalWrite(pinoEsqAnti, LOW);
  } else {
    digitalWrite(pinoEsqHora, LOW);
    digitalWrite(pinoEsqAnti, HIGH);
  }
}

void moverMotorDir(int velocidade, bool praFrente) {
  analogWrite(pinoVelDir, velocidade);
  if (praFrente) {
    digitalWrite(pinoDirHora, HIGH);
    digitalWrite(pinoDirAnti, LOW);
  } else {
    digitalWrite(pinoDirHora, LOW);
    digitalWrite(pinoDirAnti, HIGH);
  }
}

void paraFrente(int velocidade) {
  // Andando para frente
  analogWrite(pinoVelEsq, velocidade);
  digitalWrite(pinoEsqHora, HIGH);
  digitalWrite(pinoEsqAnti, LOW);
  analogWrite(pinoVelDir, velocidade);
  digitalWrite(pinoDirHora, HIGH);
  digitalWrite(pinoDirAnti, LOW);
}

void pararMotores() {
  // Parando os motores
  digitalWrite(pinoEsqHora, LOW);
  digitalWrite(pinoEsqAnti, LOW);
  digitalWrite(pinoDirHora, LOW);
  digitalWrite(pinoDirAnti, LOW);
  analogWrite(pinoVelEsq, 0); // Garante que a velocidade seja zero
  analogWrite(pinoVelDir, 0); // Garante que a velocidade seja zero
}

void parar() {
  // Adicionando uma função parar()
  pararMotores();
}

//RESULTADO: Em um ciclo contínuo, o robô inicia uma busca girando e varrendo o ambiente com seu sensor ultrassônico para identificar o objeto mais próximo, memorizando a direção em que essa menor distância é detectada; em seguida, ele gira precisamente para essa direção e avança em linha reta por um breve período, simulando um ataque, para então reiniciar o processo de busca por um novo alvo.
// EXPECTED RESULT: In a continuous cycle, the robot initiates a search by turning and scanning its surroundings with its ultrasonic sensor to identify the closest object, memorizing the direction where this shortest distance is detected; it then precisely turns towards that direction and moves straight forward for a short period, simulating an attack, before restarting the search process for a new target.
