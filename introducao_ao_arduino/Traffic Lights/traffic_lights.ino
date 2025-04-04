//Esta função seta pinos especificos e os determina como saídas;
void setup(){
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
}

//Esta função roda o código infinitamente em loop, e a função não necessita de parâmetros
void loop() {
  digitalWrite(8, HIGH) ;
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  delay(5000);
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  delay(2000);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  delay(5000);
}
// RESULTADO ESPERADO: o Led Vermelho(8) acende por 5 segundos e apaga; o Led Amarelo(7) acende por 2 segunndos e apaga; o Led Verde acende por 5 segundos e apaga;
// EXPECTED RESULT: the Red Led (8) turns on for 5 seconds and turns off; the Yellow Led (7) turns on for 2 seconds and turns off; the Green Led turns on for 5 seconds and turns off;
