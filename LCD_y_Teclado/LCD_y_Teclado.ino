// LCD y Teclado

//#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal.h>
#include <Keypad.h>

char pulso;       // almacena la tecla pulsada
int  contador = 1;    // cuenta el nivel del menu en el que se esta
const byte ROWS = 4;  //Cuatro Filas
const byte COLS = 4;  //Cuatro Columnas 
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9,8,7,6}; //Puntos de conexion del teclado al arduino FILAS
byte colPins[COLS] = {5,4,3,2}; //Puntos de conexion del teclado al arduino COLUMNAS
Keypad Teclado1 = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //Configura el teclado
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5); 

/* ----------------- Void Setup --------------------- */
void intro();
void menu1();
void seleccion1();
void menu2();
void seleccion2();
void menu3();
void seleccion3();
void menu4();
void seleccion4();
void parpadeo();

void setup() {
  lcd.begin(ROWS,COLS);
 pinMode(12, OUTPUT);
 intro();             // muestra el intro de  bienvenida
  // put your setup code here, to run once:

}

void loop() {
  pulso = Teclado1.getKey() ;  // Lee la tecla pulsada
 if (pulso != 0) {      
    lcd.clear();
    delay(100);
 } 
 if(contador == 4){ menu4();seleccion4();}
 if(contador == 3){ menu3();seleccion3();}
 if(contador == 2){ menu2();seleccion2();}
 if(contador == 1){ menu1();seleccion1();}
  // put your main code here, to run repeatedly:

}
/* ------------------  Intro ------------------------ */
void intro(){ 
 lcd.clear();  // Borra el  LCD
 lcd.setCursor(3,0);         // Se posiciona en la Columna 3, Fila 0
 lcd.print("BIENVENIDO ");
 lcd.setCursor(1,1);
 lcd.print("PRUEBA DE MENU");
 delay(4000);                // espera 4 segundos mostrando el intro
 lcd.clear();
}
/* ------------------ Menu 1 ------------------------ */
void menu1(){ 
   lcd.setCursor(0,0);
   lcd.print("ON    >1  ");
   lcd.setCursor(10,0);
   lcd.print("OFF >2");   
   lcd.setCursor(0,1);
   lcd.print("INTER >3  "); 
   lcd.setCursor(10,1);
   lcd.print("MAS >*");
}
/* ------------------ Seleccion 1 ------------------- */
void seleccion1(){ 
  if(pulso == '1') digitalWrite(12,HIGH);
  if(pulso == '2') digitalWrite(12,LOW);
  if(pulso == '3') parpadeo();
  if(pulso == '*') contador=2;
}
/* ------------------ Menu 2 ------------------------ */
void menu2(){ 
   lcd.setCursor(0,0);
   lcd.print("LUZ  >1   ");
   lcd.setCursor(8,0);
   lcd.print("TIEMPO>2");
   lcd.setCursor(0,1);
   lcd.print("MENU >#          ");
}
/* ------------------ Seleccion 2 ------------------- */
void seleccion2(){ 
  if(pulso == '1') contador=3;
  if(pulso == '2') contador=4;
  if(pulso == '#') contador=1;
}
/* ------------------ Menu 3 ------------------------ */
void menu3(){ 
   lcd.setCursor(0,0);
   lcd.print("LUZ :           ");
   lcd.setCursor(5,0);
   lcd.print(analogRead(A0));  
   lcd.setCursor(0,1);
   lcd.print("MENU>#      <--0");
}
/* ------------------ Seleccion 3 ------------------- */
void seleccion3(){ 
  if(pulso == '#') contador=1;
  if(pulso == '0') contador=2;
}
/* ------------------ Menu 4 ------------------------ */
void menu4(){ 
   unsigned long tiempo1 = (millis()/1000);  
   lcd.setCursor(0,0);
   lcd.print("TIEMPO:            ");
   lcd.setCursor(8,0);
   lcd.print(tiempo1);  
   lcd.setCursor(0,1);
   lcd.print("MENU>#      <--0");
}
/* ------------------ Seleccion 4 ------------------- */
void seleccion4(){ 
  if(pulso == '#') contador=1;
  if(pulso == '0') contador=2;
}
/* ------------------   Parpadeo  ------------------- */
void parpadeo(){ 
  digitalWrite(12,HIGH);
  delay(300);
  digitalWrite(12,LOW);
  delay(300);
  digitalWrite(12,HIGH);
  delay(300);
  digitalWrite(12,LOW);
  delay(300);
}
