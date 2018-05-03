# AirConditioningControlSystem
An air-conditioning control system (simulated by a RGB led) using Cayenne and Arduino Uno. ​

A digital temperature and humidity sensor sends the data to the microcontroller that writes them on an LCD screen and sends them to Cayenne. Using the Cayenne Dashboard we can manage the information and we can decide to switch on either the heating system (Red led), the dehumidifier (Green led) or the cooling system (Blue led).​

youtube: https://www.youtube.com/watch?v=_cIvle3mz5M&t=2s

hackster: https://www.hackster.io/salvatore-licitra/air-conditioning-control-system-emulator-fe469d

linkedin: https://www.linkedin.com/in/salvatorelicitra/

slideshare: https://www.slideshare.net/SalvatoreLicitra2/mydevices-cayenne-95815390

# Components
(1)   x Arduino Uno​

(1)   x Breadboard​

(20)  x Connectors M-M ​

(3)   x Connectors M-F ​

(3)   x 220 ohm Resistor ​

(1)   x Led RGB​

(1)   x DHT11 Temperature-Humidity Sensor​

(1)   x Module LCD1602​

(1)   x Potentiometer (10k)​

# Libraries
- CayenneMQTT (to comunicate with Cayenne)
- LiquidCrystal (to the LCD screen)
- SimpleDHT (to use the sensor)

# How to start the server (Windows)
I use the serial port, so I need to run the server on my laptop; to do this I run the script "cayenne-ser.bat" followed by "-c" and the Comunication Port (the script is available on folder "\Arduino\libraries\CayenneMQTT\extras\scripts")
