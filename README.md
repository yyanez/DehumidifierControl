# DehumidifierControl
Arduino code to switch ON and OFF a cheap dehumidifier depending on the value of the relative humidify measured with a DHT11 temperature and relative humidity sensor.



## Requisites

1. Arduino software installed
2. Install the two ZIP libraries stored in the lib folder (_Adafruit_Sensor-master.zip_ and _DHT-sensor-library-master.zip_)
   1. You can install the library by going to **Sketch > Include Library > Add .ZIP Library** in the Arduino IDE



## PINOUT

* Pin 4: Readings from the DHT11
* Pin 8: Activation of the Relay



## Sources

Initial DHT11 example: https://www.makerguides.com/dht11-dht22-arduino-tutorial/

