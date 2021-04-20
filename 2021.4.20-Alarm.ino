void setup(){
	pinMode(4,OUTPUT);
	pinMode(5,OUTPUT);
	pinMode(6,INPUT);
}
void loop(){
	int sound=analogRead(A2),light=analogRead(A6);
	if(sound>777&&light<222){
		digitalWrite(4,HIGH);
		int i=0;
		while(digitalRead(6)==LOW){
			i++;
			digitalWrite(5,i%3==0);
			delay(1);
		}
		digitalWrite(4,LOW);
	}
}