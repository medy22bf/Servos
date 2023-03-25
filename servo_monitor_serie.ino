/*
 En esta práctica apoyandonos en el montaje anterior, vamos crear
 un codigo con el fin de poder gobernar el servomotor mediante
 el potenciomtro como la practica anterior y a su vez mediante
 impulsos escritos que le vamos enviar a traves del programa. 
 En mi sistema va a prevalecer la poscion del potenciometr,
 lo que quiero decir es que cumplirá las dos ordenes, pero
 una vez cumplidas volverá a la posición del potenciometro.
 */

// Alumno: Mehdi Boumhara Farhane


#include <Servo.h> //Utilización de este elemento para el 
                  // desarrollo de nuestra práctica

//Pin de control para el servomotor
#define CTRL 3

//Pin de lectura del potenciometro
#define POT A5

//Declaramos de los obkjetos del servomotor

Servo motor;
int angulo = 0;
int veloc = 2000; // Esta es la velocidad a la que el servo vuelve
                // a la posicion anterior.

String orde = "";

void setup() {
  // Especificación al programa de lo que hay conectado.
  motor.attach(CTRL);
  Serial.begin(9600);
}

void loop(){
  // Lectura de todas las entradas y sus ordenes
 // En este apartado realizaremos la progración para las ordenes
// escritas.
if(Serial.available()){
  orde = Serial.readStringUntil('\n');                 
 
    if(orde.equals("esquerda")) angulo = 180;
    else if(orde.equals("dereita")) angulo = 0;
    else if(orde.equals("centro")) angulo = 90;
    else {
      int tmp = orde.toInt();
      if(tmp >= 0 && tmp <= 180) angulo = tmp;
      else angulo = 0;  
  }
    
 
}
  else{
    // Lectura do potenciometro
    // Aqui es donde añadimos la parte de la practica anterior
    angulo = analogRead(POT);
    angulo = map(angulo, 0, 1023, 0, 180);
  }
  
 motor.write(angulo);
  delay(veloc);
  Serial.println(angulo); // monitorización del angulo
  //delay(lectura);
  
  
}
  
