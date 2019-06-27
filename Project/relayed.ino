#include <RelayModule.h>


#include <LiquidCrystal.h>
#include <EduIntro.h>
#define RELAY_PIN_pump   9
RelayModule* relay = NULL;
DHT11 dht11(D8);
float C;
int i;
int set_temp=28;
float humidity;
int Contrast=20;
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
void setup() 
{
relay = new RelayModule(RELAY_PIN_pump);
lcd.begin(16, 2);
Serial.begin(9600);
relay->off();
lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Welcome Aakash");
  lcd.setCursor(2,1);
  lcd.print("FATC loading");
  delay(8000);
}
void loop(){
  
  dht11.update();
  C = dht11.readCelsius(); 
  humidity = dht11.readHumidity();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(C);
  lcd.print("'C");
  lcd.setCursor(0,1);
  lcd.print("Humid: ");
  lcd.print(humidity);  
  lcd.print("%");
  delay(8000);
  if(C<=28 && relay->isOn()){
    relay->off();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Wait for ");
    lcd.setCursor(13,0);
    lcd.print("sec");
    lcd.setCursor(0,1);
    lcd.print("Pumpoff Temp<28C");
    
    for(i=180;i>99;i--){
    lcd.setCursor(9,0);
    lcd.print(i);
    delay(1000);    
    }
    for(i=99;i>9;i--){
      lcd.setCursor(9,0);
    lcd.print(" ");
    lcd.setCursor(10,0);
    lcd.print(i);
    delay(1000);  
      }
     for(i=9;i>-1;i--){
      lcd.setCursor(9,0);
    lcd.print(" ");
    lcd.setCursor(10,0);
    lcd.print(" ");
    lcd.setCursor(11,0);
    lcd.print(i);
    delay(1000);  
      }
    }
  else if(C>28 && relay->isOff()){
    relay->on();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Wait for ");
    lcd.setCursor(13,0);
    lcd.print("sec");
    lcd.setCursor(0,1);
    lcd.print("Pump on Temp>28C");
    
    for(i=180;i>99;i--){
    lcd.setCursor(9,0);
    lcd.print(i);
    delay(1000);    
    }
    for(i=99;i>9;i--){
      lcd.setCursor(9,0);
    lcd.print(" ");
    lcd.setCursor(10,0);
    lcd.print(i);
    delay(1000);  
      }
     for(i=9;i>-1;i--){
      lcd.setCursor(9,0);
    lcd.print(" ");
    lcd.setCursor(10,0);
    lcd.print(" ");
    lcd.setCursor(11,0);
    lcd.print(i);
    delay(1000);  
      }
    }
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("updating...");
   delay(1000);
   }
