const int starWars[]={ 1,0,5,0,4,3,2,8,0,5,0,4,3,2,8,0,5,0,4,3,4,2,-1 };
const int twoTigers[]={ 1,2,3,1,1,2,3,1,3,4,5,0,3,4,5,0,5,6,5,4,3,0,1,0,5,6,5,4,3,0,1,0,2,1,1,0,2,1,1,-1 };
//microsecond
const int toneToPeriod[]={ 0,2272,2024,1803,1702,1516,1351,1203,1136 };
void setup(){
	pinMode(5,OUTPUT);
	pinMode(4,OUTPUT);
	// Serial.begin(9600);
}
/*
void show(int n){
	for(int i=0;i<200;i++){
		if(i%n==0)	digitalWrite(5,HIGH);
		else		digitalWrite(5,LOW);
		delay(1);
	}
}
*/
void play(long time,int period){
	if(period==0){
		delay(time);
		return;
	}
	digitalWrite(4,HIGH);
	// Serial.println(period);
	for(long i=0;i<time*20;i++){
		if(i%(period/35))
			digitalWrite(5,LOW);
		else
			digitalWrite(5,HIGH);
	}
	digitalWrite(4,LOW);
}
void loop(){
	for(int i=0;starWars[i]!=-1,analogRead(A0)<500;i++){
		play(300,toneToPeriod[starWars[i]]);
		delay(50);
	}
	delay(100);
}
