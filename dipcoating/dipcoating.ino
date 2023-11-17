
int IN1 = 8 ;
int IN2 = 7 ;
int velocidade = 0;
int pinoPWM = 3; 
char tecla;

#include "Keyboard.h"

void setup() {
  pinMode(pinoPWM, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  Serial.begin(9600);
  Keyboard.begin();

}

void loop() {


  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
  tecla = Serial.read();
  
   if(tecla=='S'|| tecla=='s'){
    velocidade = 240;
    delay(100);
  }

    if(tecla=='V' || tecla=='v' ){
    velocidade = 110;
    delay(100);
  }

      if(tecla=='P' || tecla=='p'){
    velocidade = 0;
    delay(100);
  }
  
  if(tecla=='U'){
    velocidade = velocidade + 2;
    delay(100);
  }

  if(tecla=='D'){
    if(velocidade>=0){
    velocidade = velocidade - 20;
    }
    else{
      velocidade = 0;
    }
    delay(100);
  }

  Serial.print("Velocidade:");
  Serial.print(velocidade);
  Serial.print("/");
  Serial.println(255);

  Serial.print("TECLA:");
  Serial.println(tecla);

  analogWrite(pinoPWM, velocidade);
  delay(100);

}
