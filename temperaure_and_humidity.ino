#include <dht.h>        
#include <LiquidCrystal.h>  

#define DHTPIN 2        
#define GASPIN A0       
#define DHTTYPE DHT11 

dht DHT;                
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

void setup() {
  Serial.begin(9600);   
  lcd.begin(16, 2);     
}

void loop() {
  
  int chk = DHT.read(DHTPIN);
  float temperature = DHT.temperature;
  float humidity = DHT.humidity;

  int gasValue = analogRead(GASPIN);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print(" %");

  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  delay(2000);  
}

