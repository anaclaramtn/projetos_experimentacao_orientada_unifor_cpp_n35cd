int contador = 0;
long timer = 0;

void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop(){
  if(digitalRead(2)){
    Serial.println("Botão pressionado!");
  }
  if(timer < millis()){
    timer = millis() + 1000; //incrementa o contador
    contador = contador + 1; //incrementar a variável
    Serial.println(contador);
  }
/* O código "errado" seria assim, porque o contador pausa em 1 seguno sempre que o botão é pressionado, mostrando que o código nao tem uma boa contagem de tempo, que é o propósito de entender esse código.
  void loop(){
    contador = contador + 1;
    Serial.println(contador);
    delay(1000);
    
    if(digitalRead(2)){
      Serial.println("Botão pressionado!");
  }
*/
}

// RESULTADO ESPERADO: há um contador que será exibido no monitor serial que não possui delay! Demonstrar uma forma mais eficiente de controlar o tempo em um programa Arduino sem usar a função delay(). A função delay() pausa a execução de todo o código, o que pode ser problemático em projetos mais complexos onde você precisa fazer várias coisas ao mesmo tempo. O uso de millis() permite que o Arduino continue executando outras tarefas enquanto verifica se um certo intervalo de tempo já passou.
// EXPECTED RESULT: There is a counter that will be displayed on the serial monitor that has no delay! Demonstrate a more efficient way to control time in an Arduino program without using the delay() function. The delay() function pauses the execution of all code, which can be problematic in more complex projects where you need to do several things at the same time. Using millis() allows the Arduino to continue executing other tasks while checking if a certain amount of time has passed.
