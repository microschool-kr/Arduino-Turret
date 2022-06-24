#include <Servo.h>
#define ECHO 12
#define TRIG 13

Servo myservo1;
Servo myservo2;

long duration;
int distance;

int pos_1 = 15;
int pos_2 = 180;
int index = 0;

void setup()
{
    pinMode(ECHO, INPUT);
    pinMode(TRIG, OUTPUT);
    myservo1.attach(9);
    myservo2.attach(10);
    myservo2.write(180);
    Serial.begin(9600);
    
}

void loop()
{
    for (pos_1 = 15; pos_1 <= 165; pos_1++)
    {
        detection(pos_1);
    }

    for (pos_1 = 165; pos_1 >= 15; pos_1--)
    {
        detection(pos_1);
    }
}

void check()
{
    if (distance < 15)
    {
        index++;
        switch (index)
        {
        case 1:
            trig(index);
            Serial.println("1발 발사!");
            break;
        case 2:
            trig(index);
            Serial.println("2발 발사!");
            load();
            index = 0;
            break;
        default:
            index = 0;
            load();
            break;
        }
    }
}

void trig(int n)
{
    for (pos_2 = 180 - ((n - 1) * 60); pos_2 >= 180 - (n * 60); pos_2 -= 1)
    {
        myservo2.write(pos_2);
        delay(27);
    }
}

void load()
{
    for (pos_2 = 80; pos_2 <= 180; pos_2 += 1)
    {
        myservo2.write(pos_2);
        delay(5);
    }
}

void detection(int angle) {

  int correctAngle = 180-angle;
  myservo1.write(correctAngle);
  delay(30);
  distance = calculateDistance();
  Serial.print(angle);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  check();
}

int calculateDistance()
{
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance =  duration * 0.034 / 2;

  return distance;
}
