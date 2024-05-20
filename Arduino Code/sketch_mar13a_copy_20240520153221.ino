
//HTTP protocols for communication between blynk and nodemcu


#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""



// required libraries

#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>




// WiFi credentials
char ssid[] = "realme";
char pass[] = "tejasviaryaa";



// Blynk auth token
char auth[] =BLYNK_AUTH_TOKEN;



int sensorPin = A0; // Analog pin where the gas sesnor is connected with node mcu board

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 baud rate
  Blynk.begin(auth, ssid, pass); // Connect to Blynk
}

void loop() {
  int sensorValue =4*analogRead(sensorPin); // apply the formula obtained from graph here
  //5 ppm is max limit for no2

  // Print the sensor value to the Serial Monitor
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  if (sensorValue > 1000) {
    Blynk.logEvent("Emergency!!!!!!");
  }
  // Send the sensor value to Blynk app on virtual pin V0
  Blynk.virtualWrite(V0, sensorValue);

  Blynk.run(); // Initiates Blynk
  delay(1000); // Wait for a second before reading again
}
