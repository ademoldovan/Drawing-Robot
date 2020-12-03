
#include <Servo.h>

//unghiurile pentru servo motor atunci cand pixul este ridicat sau coborat
int PEN_DOWN = 15;
int PEN_UP = 80;
Servo srv;


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}


void forward(float distance){
  
}


void backward(float distance){
  
}


void right(float degrees){
     
}


void left(float degrees){
     
}


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
