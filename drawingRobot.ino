//biblioteci
#include <Servo.h>
#include <SoftwareSerial.h>

// Pinii motor 1
#define mpin00 5
#define mpin01 6
// Pinii motor 2
#define mpin10 3
#define mpin11 11

//unghiurile pentru servo motor atunci cand pixul este ridicat sau coborat
int PEN_DOWN = 90;
int PEN_UP = 0;
//numarul pinului digital unde va fi atasat semnalul pentru motorul servo
int servoPin = 8;

//numarul pinilor de pe placa atasati ledurilr
int redLed = 12;
int greenLed = 13;

//declaram un obiect de tipul servo
Servo srv;
SoftwareSerial BT_module(0, 1); // RX | TX

void setup() {
  // configurarea pinilor pentru motoare ca iesire, initial valoare 0
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

  //setarea ledurilor ca output si initializarea acestora pe high
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  digitalWrite(greenLed, HIGH);
  digitalWrite(redLed, HIGH);

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
    //forward = 1 merge inainte, daca este = cu 0 merge inapoi
    //daca pinul 1 > 0 si al 2 lea = 0 => inainte
    //daca pinul 1 = 0 si al 2 lea > 0 => inapoi
    if (forward)
    {
      analogWrite(m1, speed);
      digitalWrite(m2, 0);
    }
    else
    {
      digitalWrite(m1, 0);
      analogWrite(m2, speed);
    }
  }
}

// Funcție de siguranță
// Execută oprirea motoare, urmată de delay
void delayStopped(int ms)
{
  StartMotor (mpin00, mpin01, 0, 0);
  StartMotor (mpin10, mpin11, 0, 0);
  delay(ms);
}

//functie de deplasare inainte pentru motore
void forward() {
  //scriem LOW pe ledul rosu pentru al stinge atunci cand mergem inainte
  digitalWrite(redLed, LOW);
  delay (10);
  StartMotor (mpin00, mpin01, 0, 128);
  StartMotor (mpin10, mpin11, 1, 128);
  delay (500);
  delayStopped(500);
}

//functie de deplasare inapoi
void backward() {
  //scriem HIGH pe ledul rosu pentru al aprinde atunci cand mergem inainte
  digitalWrite(redLed, HIGH);
  delay (10);
  StartMotor (mpin00, mpin01, 1, 128);
  StartMotor (mpin10, mpin11, 0, 128);
  delay (500);
  delayStopped(500);
}

//functie de deplasare catre stanga
void left() {
  StartMotor (mpin00, mpin01, 0, 90);
  StartMotor (mpin10, mpin11, 0, 90);
  delay (500);
  delayStopped(500);
}
//functie de deplasare catre stanga
void right() {
  StartMotor (mpin00, mpin01, 1, 90);
  StartMotor (mpin10, mpin11, 1, 90);
  delay (500);
  delayStopped(500);
}

//functii pentru ridicat sau coborat pixul
//servo motorul se va invarti un anumit unghi astfel incat va ridica/cobora pixul
void penup() {
  delay(250);
  //scriem LOW pe ledul verde pentru al stinge atunci cand ridicam pixul
  digitalWrite(greenLed, LOW);
  delay (10);
  srv.write(PEN_UP);
  delay(250);
}
void pendown() {
  delay(250);
  //scriem HIGH pe ledul verde pentru al aprinde atunci cand coboram pixul
  digitalWrite(greenLed, HIGH);
  delay (10);
  srv.write(PEN_DOWN);
  delay(250);
}

void circle(){
  right();
  delayStopped(500);
  right();
  delayStopped(500);
  right();
  delayStopped(500);
  right();
  delayStopped(500);
  right();
  delayStopped(500);
}

void rectangle(){
  pendown();
  delay(250);
  forward();
  delayStopped(500);
  penup();
  delay(250);
  forward();
  delayStopped(500);
  right();
  delayStopped(500);
  backward();
  delayStopped(500);
  
  pendown();
  delay(250);
  forward();
  delayStopped(500);
  penup();
  delay(250);
  forward();
  delayStopped(500);
  right();
  delayStopped(500);
  backward();
  delayStopped(500);
  
  pendown();
  delay(250);
  forward();
  delayStopped(500);
  penup();
  delay(250);
  forward();
  delayStopped(500);
  right();
  delayStopped(500);
  backward();
  delayStopped(500);
  
  pendown();
  delay(250);
  forward();
  delayStopped(500);
  penup();
  delay(250);
  forward();
  delayStopped(500);
  forward();
  delayStopped(500);
  forward();
  delayStopped(500);
}

void loop() {

  //daca modulul bluetooth este activ, citim datele transmise
  if (BT_module.available() > 0)
  {
    //citim datele transmise prin Bluetooth
    String value = BT_module.readStringUntil('#');
    //in functie de valoarea citita vom executa diferite actiuni

    if (value == "N")    // N = deplasare catre dreapta
    {
      right();
    }
    else if (value == "S") // S = deplasare catre stanga
    {
      left();
    }
    else if (value == "W") //W = mers inainte
    {
      forward();      
    }
    else if (value == "E") // E = deplasare inapoi
    {
      backward();
    }
    else if (value == "1") // 1 = ridicare creion
    {
      pendown();
    }
    else if (value == "2")
    {
      circle();
    }
    else if (value == "3")  //3 = coborare creion
    {
      penup();
    }
    else if (value == "4")
    {
      rectangle();
    }
  }

}
