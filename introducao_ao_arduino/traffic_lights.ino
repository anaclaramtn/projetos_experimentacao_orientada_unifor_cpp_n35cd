//Esta função seta pinos especificos e os determina como saídas;
void setup(){
    pinMode(8, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(6, OUTPUT);
  }
  
  //Esta função roda o código infinitamente em loop, e não retorna nenhum valor
  void loop() {
    digitalWrite(8, HIGH) ;
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    delay(5000);
    digitalWrite(8, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    delay(2000);
    digitalWrite(4, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(6, LOW);
    delay(5000);
  }
