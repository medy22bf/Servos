/*
En esta práctica vamos poner en funcionamiento un servomotor,
este será contralado mediante un potenciometro, este potenciometro,
este lo que hará es cuando nosotros movamos el potenciometro
hacia algún lado el servo motor irá dirigido hacia ese lado o esa
posición.
 */ 

// Alumno: Mehdi Boumhara Farhane

#include <Servo.h>   //En este apatadado vamos utilizar esta
                    // HERRAMIENTA

//Pin de control del servomotor
#define CTRL 3

//Pin de lectura del potenciometro
#define POT A5

//Declaramos nuestros obxectos tanto la velocidad como la 
//posicion

Servo motor;
int angulo = 0;
int veloc = 100;

void setup() { 
  //Aqui estamos haciendo la declaración de las entradas
  //diciendole a nuestro progrma que hay conectado en cada pin
  motor.attach(CTRL);
}

void loop() {
  //Lectura del potenciometro
  angulo = analogRead(POT);
  angulo = map(angulo, 0, 1023, 0, 180);
  //Actualiza servo (realimentación)
  motor.write(angulo);
  delay(veloc);
}
