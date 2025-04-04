int leitura = 0; // Essa variável vai guardar o resultado da leitura analógica;
int leituraPorcentagem = 0; // Essa variável será usada para guardar o valor da leitura analógica convertida para uma escala de 0 a 100 (%).

void setup(){ // O código dentro desta função é executado apenas uma vez quando o Arduino é ligado ou resetado.
  Serial.begin(9600); // Prepara o Arduino para enviar e receber dados através da porta USB do computador a uma velocidade de 9600 bps.
  Serial.println("Iniciando..."); // Envia a mensagem "Iniciando..." para o Monitor Serial do Arduino IDE.
}

void loop(){ // O código dentro desta função é executado repetidamente enquanto o Arduino estiver ligado.
  leitura = analogRead(A0); // Lê o valor analógico do pino A0 e armazena na variável leitura. Os valores lidos estão na faixa de 0 a 1023 (para uma resolução de 10 bits) -->  O potenciometro está ligado à porta A0;
  leituraPorcentagem = map(leitura,0,1023,0,100); // Mapeia o valor da variável leitura (que está na faixa de 0 a 1023) para uma nova faixa de 0 a 100.
  Serial.print(leitura);
  Serial.print(",");
  Serial.print(leituraPorcentagem);
  Serial.println("%");
  delay(100);
}

// RESULTADO: sempre que o potenciometro for girado, será mostrado um dado no monitor serial do IDE que corresponde ao valor lido (leitura) e a porcentagem proporcional respectiva (int leituraPorcentagem);
/// RESULT: whenever the potentiometer is turned, data will be displayed on the IDE serial monitor that corresponds to the read value (reading) and the respective proportional percentage (int leituraPorcentagem);
