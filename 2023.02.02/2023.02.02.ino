#include <NewPing.h> //샤랏투 경윤이 형

NewPing sensor(52,53,350);
#define k 0.7

float Sonar_distance=0;

void read_sonar_sensor(void)
{
   Sonar_distance = sensor.ping_cm()*10.0;
   if(Sonar_distance == 0){Sonar_distance = 350 * 10.0;}
}

float old_average=0;
float new_average=0;

void nomal_average (float a,float K)
{
   new_average=(old_average*K)+(a*(1-K));
   old_average=new_average;
}

void setup() 
{
Serial.begin(115200);
}

void loop() 
{
  read_sonar_sensor();
  nomal_average(Sonar_distance,k);
  Serial.print(Sonar_distance);
  Serial.print(" ");
  Serial.println(new_average);
  delay(100);
}
