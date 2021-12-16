#include <Servo.h> 
#include <ESP8266WiFi.h>
const char* ssid="Lu-Redmi";
const char* password="10203040";
const char* host="192.168.87.110";
const int tcpPort=7777;
WiFiClient client;
int Echo=D6,Trig=D7;  //  超声波发送D6 接受D7
Servo Shead,Sback,Sfront;//舵机
int pos=0;

/*超声波测距*/
unsigned long Distance_test(){
  digitalWrite(Trig,LOW);           // 给触发脚低电平2μs
  delayMicroseconds(2);
  digitalWrite(Trig,HIGH);          // 给触发脚高电平10μs
  delayMicroseconds(10);
  digitalWrite(Trig,LOW);           // 持续给触发脚低电
  return pulseIn(Echo,HIGH)/58;     // 读取高电平时间(单位：微秒)
}
void go(int p,int mid=90){
  Sback.write(p+mid-90);
  Shead.write((p-90)/2+90);
  delay(5);
  Sfront.write(180-p-mid+90);
  delay(5);
}
/* 直线行驶  */
void forward(){
  digitalWrite(D13,LOW);
  for(pos=90; pos<150; pos+=15)
    go(pos);
  for(pos=150; pos>30; pos-=15)
    go(pos);
  for(pos=30; pos<90; pos+=15)
    go(pos);
}
/*判断转向*/
void rotate(){
  digitalWrite(D13,HIGH);
  for(pos=90; pos<150; pos+=15)
    go(pos,120);
  for(pos=150; pos>30; pos-=15)
    go(pos,120);
  for(pos=30; pos<90; pos+=15)
    go(pos,120);

}
void setup(){
  pinMode(Echo,INPUT);pinMode(Trig,OUTPUT);
  pinMode(D13,OUTPUT);
  Serial.begin(9600);
  Shead.attach(D8);Sback.attach(D9);Sfront.attach(D10);
  Shead.write(90);Sback.write(90);Sfront.write(90);
  WiFi.begin(ssid,password);
}
int t=0;
char status='0';
void loop(){
  // if(client.available())
  //   status=client.read();
  // if(status=='0')
  //   return;
  long d=Distance_test();
  Serial.println(d);
  // digitalWrite(D13,(t++)%2);
  if(d>20)
    forward();
  else
    rotate();
  delay(50);
}