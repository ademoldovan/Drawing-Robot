
#include <Servo.h>
//unghiurile pentru servo motor atunci cand pixul este ridicat sau coborat
int PEN_DOWN = 15;
int PEN_UP = 80;
//numarul pinului digital unde va fi atasat semnalul pentru motorul servo
int servoPin = 8;
Servo srv;


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

//functii pentru directiile in care sa mearga robotul
void forward(float distance){
  
}


void backward(float distance){
  
}


void right(float degrees){
     
}


void left(float degrees){
     
}

//functii pentru ridicat sau coborat pixul
//servo motorul se va invarti un anumit unghi astfel incat va ridica/cobora pixul
void penup(){
  delay(250);
  penServo.write(PEN_UP);
  delay(250);
}


void pendown(){
  delay(250);  
  penServo.write(PEN_DOWN);
  delay(250);
}
