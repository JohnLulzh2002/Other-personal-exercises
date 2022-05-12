#include<DHT.h>
#include<U8x8lib.h>

DHT dht(3,DHT11);//生成DHT对象；
U8X8_SSD1306_128X64_ALT0_HW_I2C u8x8(U8X8_PIN_NONE);
void setup(void){
	dht.begin();
	u8x8.begin();
	u8x8.setPowerSave(0);
	u8x8.setFlipMode(1);
}

void loop(void){
	float temp,humi;
	temp=dht.readTemperature();
	humi=dht.readHumidity();
	u8x8.setFont(u8x8_font_chroma48medium8_r);
	u8x8.setCursor(0,0);
	u8x8.print("Temp:");
	u8x8.print(temp);
	u8x8.print("C");
	u8x8.setCursor(0,2);
	u8x8.print("Humidity:");
	u8x8.print(humi);
	u8x8.print("%");
	u8x8.refreshDisplay();
	delay(100);
}
