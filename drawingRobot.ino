#include <Servo.h>
#include <SoftwareSerial.h>

// Pinii motor 1
#define mpin00 5
#define mpin01 6
// Pinii motor 2
#define mpin10 3
#define mpin11 11

//unghiurile pentru servo motor atunci cand pixul este ridicat sau coborat
int PEN_DOWN = 0;
int PEN_UP = 90;
//numarul pinului digital unde va fi atasat semnalul pentru motorul servo
int servoPin = 8;
Servo srv;

SoftwareSerial BT_module(0, 1); // RX | TX

void setup() {
  // configurarea pinilor motor ca iesire, initial valoare 0
  digitalWrite(mpin00, 0);
  digitalWrite(mpin01, 0);
  digitalWrite(mpin10, 0);
  digitalWrite(mpin11, 0);
  pinMode (mpin00, OUTPUT);
  pinMode (mpin01, OUTPUT);
  pinMode (mpin10, OUTPUT);
  pinMode (mpin11, OUTPUT);

  srv.attach(servoPin);

  Serial.begin(9600);
  BT_module.begin(9600);
}
// Funcție pentru controlul unui motor
// Intrare: pinii m1 și m2, direcția și viteza
void StartMotor (int m1, int m2, int forward, int speed)
{

  if (speed == 0) // oprire
  {
    digitalWrite(m1, 0);
    digitalWrite(m2, 0);
  }
  else
  {
    if (forward)
    {
      digitalWrite(m2, 0);
      analogWrite(m1, speed); // folosire PWM
    }
    else
    {
      digitalWrite(m1, 0);
      analogWrite(m2, speed);
    }
  }
}
// Funcție de siguranță
// Execută oprire motoare, urmată de delay
void delayStopped(int ms)
{
  StartMotor (mpin00, mpin01, 0, 0);
  StartMotor (mpin10, mpin11, 0, 0);
  delay(ms);
}

void forward() {
  StartMotor (mpin00, mpin01, 0, 128);
  StartMotor (mpin10, mpin11, 1, 128);
  delay (500);
  delayStopped(500);
}
void backward() {
  StartMotor (mpin00, mpin01, 1, 128);
  StartMotor (mpin10, mpin11, 0, 128);
  delay (500);
  delayStopped(500);
}

//functii pentru ridicat sau coborat pixul
//servo motorul se va invarti un anumit unghi astfel incat va ridica/cobora pixul
void penup() {
  delay(250);
  srv.write(PEN_UP);
  delay(250);
}
void pendown() {
  delay(250);
  srv.write(PEN_DOWN);
  delay(250);
}
void loop() {
  //delay (10);

  if (BT_module.available() > 0)
  {
    delay(10);
    String value = BT_module.readStringUntil('#');
    //Serial.println("Valoarea citita: " + value);
    if (value == "N") {
      //Serial.println("Valoarea citita este N ");

    }
    else if (value == "S") {
      //Serial.println("Valoarea citita este S ");

    }
    else if (value == "W") {
      Serial.println("Valoarea citita W ");
      forward();
    }
    else if (value == "E") {
      Serial.println("Valoarea citita E ");
      backward();
    }
    else if (value == "1") {
      //Serial.println("Valoarea citita 1 ");
    }
    else if (value == "2") {  //pen up
      //Serial.println("Valoarea citita 2 ");
      penup();
    }
    else if (value == "3") {
      //Serial.println("Valoarea citita 3 ");
    }
    else if (value == "4") { //pen down
      //Serial.println("Valoarea citita 4 ");
      pendown();
    }
  }

}