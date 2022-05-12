/*
接线方法:
HC-SR04 引脚 VCC 连接到 Arduino 引脚 +5VDC
HC-SR04 引脚 Trig 连接到  Arduino 引脚 11
HC-SR04 引脚 Echo 连接到  Arduino 引脚 12
HC-SR04 引脚 GND 连接到  Arduino 引脚 GND
 */
const int Trig = 11;    //Trig
const int Echo = 12;    //Echo
long duration, cm, inches;
void setup(){
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
}
void loop(){
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(Trig, LOW);
  delayMicroseconds(5);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  duration = pulseIn(Echo, HIGH);
  // convert the time into a distance
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74; 
  
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(1000);
}