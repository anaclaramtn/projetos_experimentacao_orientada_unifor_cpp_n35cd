bool foiApertado = false;

// Isso é o mesmo que escrever algo tipo:
// int botao = 2;
// int led = 13;
// (ln 13) pinMode(botao, INPUT);
// (ln 16) pinMode(led, OUTPUT);
// (ln 18) foiApertado = digitalRead(2);
// (ln 20) digitalWrite(led, HIGH);
// (ln 23) digitalWrite(led, LOW);

void setup() {
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
}

void loop(){
  foiApertado = digitalRead(2); 
  if (foiApertado == true){
  	digitalWrite(13, HIGH);
  	delay(1000);
  } else {
  	digitalWrite(13, LOW);
  } 
}
