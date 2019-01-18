/*INCLUDES*/
#include "Arduino.h"
#include "PCF8574.h"

PCF8574 pcf0(32);
PCF8574 pcf1(33);
PCF8574 pcf2(34);
PCF8574 pcf3(35);
PCF8574 pcf4(36);


boolean boton_int_izquierdo = false;
boolean boton_int_derecho = false;
boolean boton_laser_encendido = true;

int pinBuzzer = 9;


int int_izq = 2;
int int_dcha = 3;
int claxon_btn = 8;
int frenos = 6;

boolean laser_encendido = false;

void pinesDeSalida()
{
  int i;

  //pcf0
  for (i = 0; i < 8; i++)
    pcf0.pinMode(i, OUTPUT);

  pcf0.begin();
  //pcf1
  for (i = 0; i < 8; i++)
    pcf1.pinMode(i, OUTPUT);

  pcf1.begin();
  //pcf2
  for (i = 0; i < 8; i++)
    pcf2.pinMode(i, OUTPUT);

  pcf2.begin();
  //pcf3
  for (i = 0; i < 8; i++)
    pcf3.pinMode(i, OUTPUT);

  pcf3.begin();
  //pcf4
  for (i = 0; i < 8; i++)
    pcf4.pinMode(i, OUTPUT);
  pcf4.begin();

  pinMode(int_izq, INPUT);
  pinMode(int_dcha, INPUT);
  pinMode(claxon_btn, INPUT);
}

/*EFECTO DE ENCENDIDO*/
void efectoEncendido()
{
  Serial.println("Efecto de encedido");
  for (int i = 0; i < 5; i++)
  {
    deDentroHaciaFuera();
  }
  parpadeo_cinco();
}

void deDentroHaciaFuera()
{
  pcf2.digitalWrite(0, HIGH); //_ _ _ _ _ _ _ _ 1 _ _ _ _ _ _ _ _ //
  delay(100);

  pcf1.digitalWrite(6, HIGH); //_ _ _ _ _ _ _ 1 1 1 _ _ _ _ _ _ _ //
  pcf2.digitalWrite(2, HIGH);
  delay(100);

  pcf1.digitalWrite(4, HIGH); //_ _ _ _ _ _ 1 1 1 1 1 _ _ _ _ _ _ //
  pcf2.digitalWrite(4, HIGH);
  delay(100);

  pcf1.digitalWrite(2, HIGH); //_ _ _ _ _ 1 1 1 _ 1 1 1 _ _ _ _ _ //
  pcf2.digitalWrite(6, HIGH);
  pcf2.digitalWrite(0, LOW);
  delay(100);

  pcf1.digitalWrite(0, HIGH); //_ _ _ _ 1 1 1 _ _ _ 1 1 1 _ _ _ _ //
  pcf3.digitalWrite(0, HIGH);
  pcf1.digitalWrite(6, LOW);
  pcf2.digitalWrite(2, LOW);
  delay(100);

  pcf0.digitalWrite(6, HIGH); //_ _ _ 1 1 1 _ _ _ _ _ 1 1 1 _ _ _ //
  pcf3.digitalWrite(2, HIGH);
  pcf1.digitalWrite(4, LOW);
  pcf2.digitalWrite(4, LOW);
  delay(100);

  pcf0.digitalWrite(4, HIGH); //_ _ 1 1 1 _ _ _ _ _ _ _ 1 1 1 _ _ //
  pcf3.digitalWrite(4, HIGH);
  pcf1.digitalWrite(2, LOW);
  pcf2.digitalWrite(6, LOW);
  delay(100);

  pcf0.digitalWrite(2, HIGH); //_ 1 1 1 _ _ _ _ _ _ _ _ _ 1 1 1 _ //
  pcf3.digitalWrite(6, HIGH);
  pcf1.digitalWrite(0, LOW);
  pcf3.digitalWrite(0, LOW);
  delay(100);

  pcf0.digitalWrite(0, HIGH); //1 1 1 _ _ _ _ _ _ _ _ _ _ _ 1 1 1 //
  pcf4.digitalWrite(0, HIGH);
  pcf0.digitalWrite(6, LOW);
  pcf3.digitalWrite(2, LOW);
  delay(100);

  pcf0.digitalWrite(4, LOW); //1 1 _ _ _ _ _ _ _ _ _ _ _ _ _ 1 1 //
  pcf3.digitalWrite(4, LOW);
  delay(100);

  pcf0.digitalWrite(2, LOW); //1 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 1 //
  pcf3.digitalWrite(6, LOW);
  delay(100);

  pcf0.digitalWrite(0, LOW); //_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ //
  pcf4.digitalWrite(0, LOW);
  delay(100);
}

void parpadeo_cinco()
{
  int i;
  for (i = 0; i < 5; i++)
  {
    pcf4.digitalWrite(2, HIGH);
    pcf1.digitalWrite(2, HIGH);
    pcf1.digitalWrite(4, HIGH);
    pcf1.digitalWrite(6, HIGH);
    pcf2.digitalWrite(0, HIGH);
    pcf2.digitalWrite(2, HIGH);
    pcf2.digitalWrite(4, HIGH);
    pcf2.digitalWrite(6, HIGH);
    delay(250);
    pcf1.digitalWrite(2, LOW);
    pcf1.digitalWrite(4, LOW);
    pcf1.digitalWrite(6, LOW);
    pcf2.digitalWrite(0, LOW);
    pcf2.digitalWrite(2, LOW);
    pcf2.digitalWrite(4, LOW);
    pcf2.digitalWrite(6, LOW);
    pcf4.digitalWrite(2, LOW);
    delay(250);
  }
}

/*FUNCIONES MANDO*/
void intIzq()
{
  Serial.println("int izq");
  lucesPosicionOff();

  pcf1.digitalWrite(2, HIGH);
  pcf1.digitalWrite(3, HIGH);
  delay(70);
  pcf1.digitalWrite(4, HIGH);
  pcf1.digitalWrite(5, HIGH);
  delay(70);
  pcf1.digitalWrite(6, HIGH);
  pcf1.digitalWrite(7, HIGH);
  delay(70);
  pcf2.digitalWrite(0, HIGH);
  pcf2.digitalWrite(1, HIGH);
  delay(70);
  pcf2.digitalWrite(2, HIGH);
  pcf2.digitalWrite(3, HIGH);
  pcf1.digitalWrite(2, LOW);
  pcf1.digitalWrite(3, LOW);
  delay(70);
  pcf2.digitalWrite(4, HIGH);
  pcf2.digitalWrite(5, HIGH);
  pcf1.digitalWrite(4, LOW);
  pcf1.digitalWrite(5, LOW);
  delay(70);
  pcf2.digitalWrite(6, HIGH);
  pcf2.digitalWrite(7, HIGH);
  pcf1.digitalWrite(6, LOW);
  pcf1.digitalWrite(7, LOW);
  delay(70);
  pcf3.digitalWrite(0, HIGH);
  pcf3.digitalWrite(1, HIGH);
  pcf2.digitalWrite(0, LOW);
  pcf2.digitalWrite(1, LOW);
  delay(70);
  pcf3.digitalWrite(2, HIGH);
  pcf3.digitalWrite(3, HIGH);
  pcf2.digitalWrite(2, LOW);
  pcf2.digitalWrite(3, LOW);
  delay(70);
  pcf3.digitalWrite(4, HIGH);
  pcf3.digitalWrite(5, HIGH);
  pcf2.digitalWrite(4, LOW);
  pcf2.digitalWrite(5, LOW);
  delay(70);
  pcf3.digitalWrite(6, HIGH);
  pcf3.digitalWrite(7, HIGH);
  pcf2.digitalWrite(6, LOW);
  pcf2.digitalWrite(7, LOW);
  delay(70);
  pcf4.digitalWrite(0, HIGH);
  pcf4.digitalWrite(1, HIGH);
  pcf3.digitalWrite(0, LOW);
  pcf3.digitalWrite(1, LOW);
  delay(70);
  pcf3.digitalWrite(2, LOW);
  pcf3.digitalWrite(3, LOW);
  delay(70);
  pcf3.digitalWrite(4, LOW);
  pcf3.digitalWrite(5, LOW);
  delay(70);
  pcf3.digitalWrite(6, LOW);
  pcf3.digitalWrite(7, LOW);
  delay(70);
  pcf4.digitalWrite(0, LOW);
  pcf4.digitalWrite(1, LOW);
  delay(70);
}

void intDcha()
{
  Serial.println("int dcha");
  lucesPosicionOff();

  pcf2.digitalWrite(6, HIGH);
  pcf2.digitalWrite(7, HIGH);
  delay(70);
  pcf2.digitalWrite(4, HIGH);
  pcf2.digitalWrite(5, HIGH);
  delay(70);
  pcf2.digitalWrite(2, HIGH);
  pcf2.digitalWrite(3, HIGH);
  delay(70);
  pcf2.digitalWrite(0, HIGH);
  pcf2.digitalWrite(1, HIGH);
  delay(70);
  pcf1.digitalWrite(6, HIGH);
  pcf1.digitalWrite(7, HIGH);
  pcf2.digitalWrite(6, LOW);
  pcf2.digitalWrite(7, LOW);
  delay(70);
  pcf1.digitalWrite(4, HIGH);
  pcf1.digitalWrite(5, HIGH);
  pcf2.digitalWrite(4, LOW);
  pcf2.digitalWrite(5, LOW);
  delay(70);
  pcf1.digitalWrite(2, HIGH);
  pcf1.digitalWrite(3, HIGH);
  pcf2.digitalWrite(2, LOW);
  pcf2.digitalWrite(3, LOW);
  delay(70);
  pcf1.digitalWrite(0, HIGH);
  pcf1.digitalWrite(1, HIGH);
  pcf2.digitalWrite(0, LOW);
  pcf2.digitalWrite(1, LOW);
  delay(70);
  pcf0.digitalWrite(6, HIGH);
  pcf0.digitalWrite(7, HIGH);
  pcf1.digitalWrite(6, LOW);
  pcf1.digitalWrite(7, LOW);
  delay(70);
  pcf0.digitalWrite(4, HIGH);
  pcf0.digitalWrite(5, HIGH);
  pcf1.digitalWrite(4, LOW);
  pcf1.digitalWrite(5, LOW);
  delay(70);
  pcf0.digitalWrite(2, HIGH);
  pcf0.digitalWrite(3, HIGH);
  pcf1.digitalWrite(2, LOW);
  pcf1.digitalWrite(3, LOW);
  delay(70);
  pcf0.digitalWrite(0, HIGH);
  pcf0.digitalWrite(1, HIGH);
  pcf1.digitalWrite(0, LOW);
  pcf1.digitalWrite(1, LOW);
  delay(70);
  pcf0.digitalWrite(6, LOW);
  pcf0.digitalWrite(7, LOW);
  delay(70);
  pcf0.digitalWrite(4, LOW);
  pcf0.digitalWrite(5, LOW);
  delay(70);
  pcf0.digitalWrite(2, LOW);
  pcf0.digitalWrite(3, LOW);
  delay(70);
  pcf0.digitalWrite(0, LOW);
  pcf0.digitalWrite(1, LOW);
  delay(70);
}

void claxon()
{
  Serial.println("claxon");
  tone(pinBuzzer, 440);
  delay(1100);
  noTone(pinBuzzer);
}

void int_frenos()
{
  Serial.println("frenos");
  while (digitalRead(frenos) == LOW)
  {
    pcf4.digitalWrite(2, HIGH);
  }
  pcf4.digitalWrite(2, LOW);
}

void lucesPosicionOn()
{
  pcf1.digitalWrite(2, HIGH);
  pcf1.digitalWrite(4, HIGH);
  pcf1.digitalWrite(6, HIGH);
  pcf2.digitalWrite(0, HIGH);
  pcf2.digitalWrite(2, HIGH);
  pcf2.digitalWrite(4, HIGH);
  pcf2.digitalWrite(6, HIGH);
}

void lucesPosicionOff()
{
  pcf1.digitalWrite(2, LOW);
  pcf1.digitalWrite(4, LOW);
  pcf1.digitalWrite(6, LOW);
  pcf2.digitalWrite(0, LOW);
  pcf2.digitalWrite(2, LOW);
  pcf2.digitalWrite(4, LOW);
  pcf2.digitalWrite(6, LOW);
}

/*FUNCIONES INTERRUPCIONES*/
void interrupcionIntermitenteIzquierdo()
{
  boton_int_izquierdo = !boton_int_izquierdo;
  boton_int_derecho = false;
}

void interrupcionIntermitenteDerecho()
{
  boton_int_derecho = !boton_int_derecho;
  boton_int_izquierdo = false;
}

void setup()
{
  Serial.begin(9600);
  pinesDeSalida();
  efectoEncendido();
  attachInterrupt(0, interrupcionIntermitenteIzquierdo,  FALLING); 
  attachInterrupt(1, interrupcionIntermitenteDerecho, FALLING); 
  Serial.println("bici operativa");
}

void loop()
{
  if (boton_int_izquierdo)
    intIzq();

  else if (boton_int_derecho)
    intDcha();
  
  else if (digitalRead(claxon_btn) == LOW)
    claxon();

  lucesPosicionOn();
}