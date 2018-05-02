/*
  This code was written by Salvatore Licitra as part of the individual Pervasive System project concerning the monitoring and regulation of
  a virtual air conditioning.
  The project uses Cayenne, the platform offered by mydevices.com
*/

/*
 *LCD circuit:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 11
 * LCD D7 pin to digital pin 12
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/

/*
 * DHT11 info:
 *  -VCC: 5V or 3V
 *  -GND: GND
 *  -DATA: 2
*/

/**************************UTILITIES*****************************/
    #include <CayenneMQTTSerial.h>  //MQTT comunication
    #include <SimpleDHT.h>          //DHT11
    #include <LiquidCrystal.h>      //LCD
/****************************************************************/
    #define CAYENNE_PRINT Serial   
/***********************PIN***DECLARATION************************/ 
    #define VIRTUAL_PIN_OUT 2       
    #define RED 6                  
    #define GREEN 5
    #define BLUE 3 
    #define DHT_PIN 2
    #define TempVirtual 2
    #define HumidityVirtual 1
/****************VARIABLES'****INITIALIZATION********************/
    LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
    SimpleDHT11 dht11;
    char username[] = ""; //insert here your username to use mqtt protocol with Cayenne
    char password[] = ""; //insert here your password to use mqtt protocol with Cayenne
    char clientID[] = ""; //insert here your clientID to use mqtt protocol with Cayenne
/****************************************************************/


CAYENNE_OUT(VIRTUAL_PIN_OUT){

  byte temperature = 0;
  byte humidity = 0;
  byte data[40] = {0};
  
  dht11.read(DHT_PIN, &temperature, &humidity, data); // Read from the DHT11 module

  // Writing data on the screen
  
  // Set the cursor to print the temperature
  lcd.setCursor(0, 0);
  lcd.print("Temperature: ");
  lcd.print((int)temperature);
  lcd.print("C");
  
  // Set the cursor to print the humidity
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print((int)humidity);
  lcd.print("%");
  
  Cayenne.celsiusWrite(TempVirtual, (int)temperature);            //I write the temperature in the virtual device connected to pin 2 (for mydevices)
  Cayenne.virtualWrite(HumidityVirtual, (int)humidity);               //I write the humidity in the virtual device connected to pin 1 (for mydevices)
  
}

// Led of the heating system
CAYENNE_IN(RED){
  int value = getValue.asInt();
  analogWrite(RED,value*255);
  CAYENNE_LOG("Channel %d, pin %d, value %d", 6, RED, value);
}

// Led of the dehumidifir
CAYENNE_IN(GREEN){
  int value = getValue.asInt();
  analogWrite(GREEN,value*255);
  CAYENNE_LOG("Channel %d, pin %d, value %d", 5, GREEN, value);
}

// Led of the cooling system
CAYENNE_IN(BLUE){
  int value = getValue.asInt();
  analogWrite(BLUE,value*255);
  CAYENNE_LOG("Channel %d, pin %d, value %d", 3, BLUE, value);
}

CAYENNE_IN_DEFAULT(){
  //Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
}

void setup(){
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  Cayenne.begin(username, password, clientID);
}

void loop() {
  Cayenne.loop();
}

