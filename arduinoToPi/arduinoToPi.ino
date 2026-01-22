#include <DHT11.h>
#include "Adafruit_MAX31855.h"
#include "MQ135_XCR.h"
MQ135_XCR airSensor(A0);
#define MAXDO 3
#define MAXCS 4
#define MAXCLK 5
#define lightPin A5
Adafruit_MAX31855 thermocouple(MAXCLK, MAXCS, MAXDO);
DHT11 dht11(2);
int tempOut, tempIn, humidity, light;
void setup() {
  thermocouple.begin();
  airSensor.calibrate();
  dht11.setDelay(1000);
  Serial.begin(9600);
}
void loop() {
  tempOut = thermocouple.readCelsius();
  //TEMP - HUMIDITY => BLUE CONECTOR
  tempIn = 0;
  humidity = 0;
  int result = dht11.readTemperatureHumidity(tempIn, humidity);
  //LIGHT SENSOR
  light = analogRead(lightPin);
  float ppm = airSensor.getPPM();
  Serial.print(tempOut);
  Serial.print(",");
  Serial.print(tempIn);
  Serial.print(",");
  Serial.print(humidity);
  Serial.print(",");
  Serial.print(light);
  Serial.print(",");
  Serial.println(int(ppm));
  Serial.flush();
}