#include<NewPing.h>

int max_distance=700;
unsigned long curTime=millis();
unsigned long lastTime=millis();
bool timerON=false;
 NewPing sonic(12,13,max_distance);

void setup() {
  pinMode(12, INPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  digitalWrite(14,LOW);
 Serial.begin(9600);

}

void loop() {
   digitalWrite(14,HIGH);
   delay(1000);
   digitalWrite(14,LOW);
   int a=sonic.ping();
   int dis=a/US_ROUNDTRIP_CM;
   Serial.println(dis);
   if(dis<25){
    lastTime=millis();
   if(!timerON){
    digitalWrite(14,HIGH);
    timerON=true;
  }

}
if(timerON){

  curTime=millis();
  if(curTime-lastTime>200){
    timerON=false;
    digitalWrite(14,LOW);

  }
}


}
