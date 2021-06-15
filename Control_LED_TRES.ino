int ledPWM = 3;
int pot=4;
int valor=0;
int x=0;
void setup() {
  pinMode(ledPWM,OUTPUT);
  pinMode(pot,INPUT);
}

void loop() {
  valor = digitalRead(pot);
  if(valor==HIGH){
    for(x;x<=255;x++){
      analogWrite(ledPWM,x);
      delay(10);
      }
    }
   if(valor==LOW){
    for(x;x>=0;x--){
      analogWrite(ledPWM,x);
      delay(10);
      }
    } 
}
