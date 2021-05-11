#include <Arduino.h>
#define btnIN A0 //entrada analogica
#define LED 10   //salida digital

enum funMode
{
  OFF,
  BLINK1,
  BLINK2,
  BLINK3,
  BLINK4,
  NBSTATE
};

int L_STD = LOW;
unsigned long pre_Millis, pas_Millis;
unsigned long lastDeTime= 0;//ultimo tiempo definido como 0 o inicio (rebote)
int LstBSTD = HIGH; //ultimo estado pre-definido
int btnSTD =0;//estado presente
int funcSTD= 0; //estados para la seleccion de menu
unsigned long BP1 = 50, BP2 = 100, BP3 = 200; //Blink intermidiate time
int interB = 100;                  //Blink intermidiate time general
int br=0, inte=5, led=3;
unsigned long tiempo, A=0, retraso=100;

void setup() {
  pinMode(btnIN, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  pinMode(led,OUTPUT );
  // put your setup code here, to run once:

}

void loop() {
  func1(); 
  func2();
  funcB4(interB);
  funcB5();
  // put your main code here, to run repeatedly:

}
void func1(){
    int reading = digitalRead(btnIN);
  if(reading!= LstBSTD){ //ultimo estado definido del buton
    lastDeTime=millis();//lastDeubonceTime
    if((millis()-lastDeTime)>100){
    if(reading != btnSTD){
      btnSTD = reading;
    }
    if(btnSTD==HIGH){
      funcSTD += 1;
    }
  }
  LstBSTD= reading;
  funcSTD=funcSTD%NBSTATE;
  }
  // put your main code here, to run repeatedly
}
  void func2()
{
  switch (funcSTD)
  {
  case OFF:
    //FuncionOFF - LED
    digitalWrite(LED, LOW);
    break;
  case BLINK1:
    //FuncionBlink1 - LED
    funcB1(BP1);
    break;
  case BLINK2:
    //FuncionBlink2 - LED
    funcB2(BP2);
    break;
  case BLINK3:
  //FuncionBlink3 - LED
    funcB3(BP3);
    break;
  //FuncionBlink4 - LED
  case BLINK4:
    funcB4(interB);
    break;
  }
}
void funcB1(int BP1)
{
  delay(BP1);
  digitalWrite(LED, LOW);
  delay(BP1);
  digitalWrite(LED, HIGH);
}
void funcB2(int BP2)
{
  delay(BP2);
  digitalWrite(LED, LOW);
  delay(BP2);
  digitalWrite(LED, HIGH);
}
void funcB3(int BP3)
{
  delay(BP3);
  digitalWrite(LED, LOW);
  delay(BP3);
  digitalWrite(LED, HIGH);
}
void funcB4(int interB) {
  pre_Millis = millis();
  if ((pre_Millis - pas_Millis) >= interB) {
    pas_Millis = pre_Millis;
    if(L_STD = LOW) {
      L_STD = HIGH;
    } else {
      L_STD = LOW;
    }
  }
}
void funcB5(){
  tiempo= millis ();
if (tiempo> A+retraso)
{
A=tiempo;
 analogWrite(led, br);
br+=inte;

 if(br==0 || br == 255)
{
inte = -inte;
}
}
}
