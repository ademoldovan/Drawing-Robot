
#include <Servo.h>
//unghiurile pentru servo motor atunci cand pixul este ridicat sau coborat
int PEN_DOWN = 15;
int PEN_UP = 80;
//numarul pinului digital unde va fi atasat semnalul pentru motorul servo
int servoPin = 8;
Servo srv;


//Ne setam pinii pentru cele 2 motoare DC
// Pinii motor 1
#define mpin00 5
#define mpin01 6
// Pinii motor 2
#define mpin10 3
#define mpin11 11


void setup() {
  // configurarea pinilor pentru motoarele DC ca iesire, initial vor avea valoarea 0
   digitalWrite(mpin00, 0);
   digitalWrite(mpin01, 0);
   digitalWrite(mpin10, 0);
   digitalWrite(mpin11, 0);
   pinMode (mpin00, OUTPUT);
   pinMode (mpin01, OUTPUT);
   pinMode (mpin10, OUTPUT);
   pinMode (mpin11, OUTPUT);

   srv.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:

}

//functii pentru directiile in care sa mearga robotul
void forward(int speed){
    if (speed==0) // oprire
    {
        digitalWrite(m1, 0);
        digitalWrite(m2, 0);
    }
    else
    {  
        digitalWrite(m2, 0);
        analogWrite(m1, speed);
    }
}


void backward(int distance){
    if (speed==0) // oprire
    {
        digitalWrite(m1, 0);
        digitalWrite(m2, 0);
    }
    else
    {  
        digitalWrite(m1, 0);
        analogWrite(m2, speed);
    }
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


//functii care sa deseneze diferite forme

void star()
{
  pendown();
  forward(100);
  right(144);
  forward(100);
  right(144);
  forward(100);
  right(144);
  forward(100);
  right(144);
  forward(100);
  right(144);
  penup();
}


void square()
{
  pendown();
  forward(100);
  right(90);
  forward(100);
  right(90);
  forward(100);
  right(90);
  forward(100);
  right(90);
  penup();
}
