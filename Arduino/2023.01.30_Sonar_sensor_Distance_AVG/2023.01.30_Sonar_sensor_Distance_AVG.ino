#include <NewPing.h>

#define MaxDistance 350
int trig = 9;
int echo = 8;

float avg, old_avg;



NewPing Sonar_sensor(trig,echo, MaxDistance);
float Sonar_distance = 0.0;

void setup()
{
  Serial.begin(115200);
}


void expression(float k, int n)
{
  avg = (((n-1) * old_avg)/n) + (k/n);
  old_avg = avg;
}



void read_sonar_sensor(void)
{
  Sonar_distance = Sonar_sensor.ping_cm()*10.0;
  if(Sonar_distance == 0){Sonar_distance = MaxDistance * 10.0;}
}

int b = 1;

void loop()
{
  read_sonar_sensor();
  if(Sonar_distance==0){Sonar_distance=MaxDistance*10;}
  //Serial.println(Sonar_distance);
  {
    expression(Sonar_distance, b);
    b++;
    Serial.println(avg);
  }
  
}
