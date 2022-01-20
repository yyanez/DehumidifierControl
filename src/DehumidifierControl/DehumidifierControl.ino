// Hay que usar el Serial Monitor (Ctrl + Shift + M) para ver el resultado
// Posibles mejoras:
// Añadir tiempos de espera entre cambios de estado

// Include the libraries:
#include <Adafruit_Sensor.h>
#include <DHT.h>

// DEFINES
#define DHT_PIN         4
#define RELAY_PIN       8
#define DHT_TYPE         DHT11   // DHT 11 
#define HIGH_HUMIDITY   60.0
#define LOW_HUMIDITY    55.0

#define UPDATE_TIME     1000 // milliseconds

// Initialize DHT sensor for normal 16mhz Arduino:
DHT dht = DHT(DHT_PIN, DHT_TYPE);
void setup() {
  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);
  Serial.println("Me cagüen satanás");
  // Setup sensor:
  dht.begin();
  pinMode(RELAY_PIN, OUTPUT);
}
void loop() {
  // Wait a few seconds between measurements:
  delay(UPDATE_TIME);
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  // Read the humidity in %:
  float h = dht.readHumidity();
  // Read the temperature as Celsius:
  float t = dht.readTemperature();
  printf("Temperatura: %f\n", t);
  // Read the temperature as Fahrenheit:
  float f = dht.readTemperature(true);
  // Check if any reads failed and exit early (to try again):
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // Compute heat index in Fahrenheit (default):
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius:
  float hic = dht.computeHeatIndex(t, h, false);

  if (h > HIGH_HUMIDITY) {
    // Encedemos Deshumidificador
    digitalWrite(RELAY_PIN,1);
  } else if (h < LOW_HUMIDITY) {
    digitalWrite(RELAY_PIN,0);
  }

  Serial.print("Humedad relativa: ");
  Serial.print(h);
  Serial.print(" % ");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" \xC2\xB0");
  Serial.print("C. ");
  Serial.print("Índice de calor: ");
  Serial.print(hic);
  Serial.print(" \xC2\xB0");
  Serial.print("C. ");
  Serial.print("Estado del relé: ");
  if (digitalRead(RELAY_PIN)) {
    Serial.println("Relé encendido");
  } else {
    Serial.println("Relé apagado");
  }

  
}
