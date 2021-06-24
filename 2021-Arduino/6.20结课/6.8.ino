//HC-SR04工作电压5V
#include<math.h>
const int Buzzer=6,freqEcho=8,freqTrig=9,volEcho=10,volTrig=11;
void setup(){
	//	Serial.begin(9600);
	pinMode(Buzzer,OUTPUT);
	pinMode(freqTrig,OUTPUT);
	pinMode(freqEcho,INPUT);
	pinMode(volTrig,OUTPUT);
	pinMode(volEcho,INPUT);
}
//period in microsecond, time in ms
void play(int pin,long period,double volume,long time){
	long highTime=period*(volume/2);
	for(long i=time*1000/period;i--;){
		digitalWrite(pin,HIGH);
		delayMicroseconds(highTime);
		digitalWrite(pin,LOW);
		delayMicroseconds(period-highTime);
	}
}
long ultraSonicRead(int echo,int trig){
	// The sensor is triggered by a HIGH pulse of 10 or more microseconds.
	// Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
	digitalWrite(trig,LOW);
	delayMicroseconds(2);
	digitalWrite(trig,HIGH);
	delayMicroseconds(6);
	digitalWrite(trig,LOW);
	// Read the signal from the sensor: a HIGH pulse whose
	// duration is the time (in microseconds) from the sending
	// of the ping to the reception of its echo off of an object.
	return pulseIn(echo,HIGH);
}
void loop(){
	long x=ultraSonicRead(freqEcho,freqTrig),y;
	long v=ultraSonicRead(volEcho,volTrig);
	double xp=(double)x/200-1;
	long xi=(long)xp;
	if(xp<xi+0.4)
		xp=xi;
	else if(xp>xi+0.6)
		xp=xi+1;
	else
		xp=xi+(xp-xi-0.4)*5;
	if(xp<0)xp=0;
	if(xp>100)return;
	//	Serial.println(xp);
	y=(long)(440*pow(1.05946309436,xp));
	v=v/300-1;
	if(v<1)return;
	if(v>6)v=0;
	//	Serial.println(v);
	//	Serial.println();
	play(Buzzer,1000000/y,v*0.05,200);
}