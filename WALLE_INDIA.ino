#include <Servo.h>
Servo leftServo;
Servo rightServo;
Servo neckServo;
Servo eyeServo;

int ch1;
int ch2;
int ch3;
int ch4;
int ch5;
int ch6;


int x, y, m, n;

#define LR1 8   //Left Motor Drive
#define LR2 9

#define RR1 10  //Right Motor Drive
#define RR2 11

void setup() {

  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);

  digitalWrite(LR1, LOW);
  digitalWrite(LR2, LOW);
  digitalWrite(RR1, LOW);
  digitalWrite(RR2, LOW);

  pinMode(LR1, OUTPUT);
  pinMode(LR2, OUTPUT);
  pinMode(RR1, OUTPUT);
  pinMode(RR2, OUTPUT);

  leftServo.attach(A0);
  rightServo.attach(A1);
  neckServo.attach(A2);
  eyeServo.attach(A3);

  leftServo.write(180);
  rightServo.write(0);
  eyeServo.write(80);
  neckServo.write(60);


  delay(2000);

  Serial.begin(115200);

}

void loop() {

  ch1 = pulseIn(2, HIGH); // Read the pulse width of
  ch2 = pulseIn(3, HIGH); // each channel
  ch3 = pulseIn(4, HIGH);
  ch4 = pulseIn(5, HIGH);
  ch5 = pulseIn(6, HIGH);
  ch6 = pulseIn(7, HIGH);


  // WHEEL CONTROL

  if (ch1 > 1050 && ch1 < 1250) {
    turn_left();
  }

  else if (ch1 > 1650) {
    turn_right();
  }


  else if (ch2 > 1700) {
    go_forward();
  }

  else if (ch2 > 900 && ch2 < 1350) {
    go_backward();
  }

  else {
    motor_stop();
  }


  // eyeServo Control A3

  if (ch3 > 1100 && ch3 < 1350) {
    //eyeServo.attach(A3);
    x = eyeServo.read();
    for (int i = x; i <= 100; i++) {
      eyeServo.write(i);
      delay(20);
      //Serial.println(eyeServo.read());
    }
    //myAudio.play("1.wav");
    Serial.println("UP");
  }
  else if (ch3 > 1700) {
    //eyeServo.attach(A3);
    y = eyeServo.read();
    for (int j = y; j >= 50; j--) {
      eyeServo.write(j);
      delay(20);
      //Serial.println(eyeServo.read());
    }
    //myAudio.play("1.wav");
    Serial.println("DOWN");
  }
  
  else if (ch3 > 1400 && ch3  < 1500) {
    if(eyeServo.read() > 80){
      int w=eyeServo.read();
      for (int q = w; q >= 80; q--) {
        eyeServo.write(q);
        delay(10);
        //Serial.println(eyeServo.read());
      }

    }
    
    
    if(eyeServo.read() < 80){
      int p=eyeServo.read();
      for (int q = p; q <= 80; q++) {
        eyeServo.write(q);
        delay(20);
        //Serial.println(eyeServo.read());
      }

    }

    Serial.println("horizontal");
  }
  
  
  else {
    //eyeServo.detach();
  }


  //neckServo Control A2

  if (ch4 > 1700) {  //A2
    m = neckServo.read();
    for (int k = m; k <= 110; k++) {
      neckServo.write(k);
      delay(20);
      //Serial.println(eyeServo.read());
    }

    Serial.println("LEFT");
  }
  else if (ch4 > 1050 && ch4  < 1350) {
    n = neckServo.read();
    for (int l = n; l >= 10; l--) {
      neckServo.write(l);
      delay(20);
      //Serial.println(eyeServo.read());
    }  
    Serial.println("RIGHT");
  }

  else if (ch4 > 1400 && ch4  < 1550) {
    if(neckServo.read() > 60){
      int w=neckServo.read();
      for (int q = w; q >= 60; q--) {
        neckServo.write(q);
        delay(20);
        //Serial.println(eyeServo.read());
      }

    }
    
    
    if(neckServo.read() < 60){
      int p=neckServo.read();
      for (int q = p; q <= 60; q++) {
        neckServo.write(q);
        delay(20);
        //Serial.println(eyeServo.read());
      }

    }

    Serial.println("centre");
  }

  else {
    //neckServo.detach();
  }




  //RIGHT SERVO

  if (ch5 > 988 && ch5 < 1100) {
    //myAudio.play("3.wav");
    rightServo.write(0);
  }
  else if (ch5 > 1100 && ch5 < 1200) {
    //myAudio.play("3.wav");
    rightServo.write(10);
  }
  else if (ch5 > 1200 && ch5 < 1400) {
    //myAudio.play("3.wav");
    rightServo.write(20);

    //Serial.println(rightServo.read());
  }
  else if (ch5 > 1400 && ch5 < 1500) {
    //myAudio.play("3.wav");
    rightServo.write(30);
  }
  else if (ch5 > 1500 && ch5 < 1600) {
    //myAudio.play("3.wav");
    rightServo.write(40);
  }
  else if (ch5 > 1600 && ch5 < 1700) {
    //myAudio.play("3.wav");

    rightServo.write(60);
  }
  else if (ch5 > 1700) {
    //myAudio.play("3.wav");
    rightServo.write(80);
  }
  else {
  }



  //LEFT SERVO

  if (ch6 > 988 && ch6 < 1100) {
    //myAudio.play("3.wav");
    leftServo.write(180);
  }
  else if (ch6 > 1100 && ch6 < 1200) {
    //myAudio.play("3.wav");
    leftServo.write(170);
  }
  else if (ch6 > 1200 && ch6< 1400) {
    //myAudio.play("3.wav");
    leftServo.write(160);

    //Serial.println(leftServo.read());
  }
  else if (ch6 > 1400 && ch6 < 1500) {
    //myAudio.play("3.wav");
    leftServo.write(140);
  }
  else if (ch6 > 1500 && ch6 < 1600) {
    //myAudio.play("3.wav");
    leftServo.write(130);
  }
  else if (ch6 > 1600 && ch6 < 1700) {
    //myAudio.play("3.wav");

    leftServo.write(120);
  }
  else if (ch6 > 1700) {
    //myAudio.play("3.wav");
    leftServo.write(100);
  }
  else {
  }

}



void turn_left() {

  delay(50);
  digitalWrite(LR1, LOW);
  digitalWrite(LR2, LOW);

  digitalWrite(RR1, LOW);
  digitalWrite(RR2, HIGH);

  Serial.println("Turning Left");
}

void turn_right() {

  delay(50);
  digitalWrite(LR1, LOW);
  digitalWrite(LR2, HIGH);

  digitalWrite(RR1, LOW);
  digitalWrite(RR2, LOW);

  Serial.println("Turning Right");

}

void go_forward() {

  delay(50);
  digitalWrite(LR1, LOW);
  digitalWrite(LR2, HIGH);

  digitalWrite(RR1, LOW);
  digitalWrite(RR2, HIGH);

  Serial.println("Going Forward");
}


void go_backward() {

  delay(50);
  digitalWrite(LR1, HIGH);
  digitalWrite(LR2, LOW);

  digitalWrite(RR1, HIGH);
  digitalWrite(RR2, LOW);

  Serial.println("Going Backward");
}

void motor_stop() {
  digitalWrite(LR1, LOW);
  digitalWrite(LR2, LOW);
  digitalWrite(RR1, LOW);
  digitalWrite(RR2, LOW);

  Serial.println("Motor Stopped !");
}



