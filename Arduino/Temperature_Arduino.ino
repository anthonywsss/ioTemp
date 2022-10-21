Arduino Code

// Library needed
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#include <DHT.h>
#include <Wire.h>   //  library for I2C protocol
#include <LiquidCrystal_I2C.h>  // library for I2C LCD

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

// pin dan sensor tpe DHT
#define DHTPIN 0
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

//
#define FIREBASE_HOST "https://iotemp-6553a-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "H4oTwlnq4ShkdinV1SS2xwpQwkop8Fv0Ua8RuTCA"
#define WIFI_SSID "arduinogang"
#define WIFI_PASSWORD "mesopotamia"  

// Object declaration from firebase
FirebaseData firebaseData;

void setup() {
  
  Serial.begin(9600);
  
  dht.begin();
  
  // Wifi connection
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

    lcd.init();                      // initialize the lcd 
 
  lcd.backlight();  // backlight ON
}

void loop(){

  lcd.clear();
  
  // Sensor DHT11 membaca suhu dan kelembaban
  float tem = dht.readTemperature();
  float hum = dht.readHumidity();

  // Memeriksa apakah sensor berhasil mambaca suhu dan kelembaban
  if(isnan(hum) || isnan(tem)) {
    Serial.println("Error reading censor DHT11");
    return;
  }

 
  // Memberikan status suhu dan kelembaban kepada firebase
  if(Firebase.setFloat(firebaseData, "/Result/Temperature", tem)){
      Serial.println("Temperature sent.");
    } 
  else{
      Serial.println("Temperature not sent.");
      Serial.println("Error Details: " + firebaseData.errorReason());
    } 
    
  if(Firebase.setFloat(firebaseData, "/Result/Humidity", hum)){
      Serial.println("Humidity sent.");
      Serial.println();
    } 
  else{
      Serial.println("Humidity not sent.");
      Serial.println("Error Details: " + firebaseData.errorReason());
    }

  lcd.print("Humidity: ");
  lcd.print(hum);
  lcd.setCursor(2,1);
  lcd.print("Temp: ");
  lcd.print(tem);

  delay(3000);
}
