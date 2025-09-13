#include <DHT.h>              // DHT sensor library
#include <Wire.h>             // Wire library for I2C communication
#include <LiquidCrystal_I2C.h> // LCD library

// Pin Definitions
#define DHTPIN 2      // Pin where the DHT sensor is connected
#define DHTTYPE DHT11 // DHT 11 or DHT22
#define SOIL_PIN A0   // Pin where the soil moisture sensor is connected
#define LDR_PIN A1    // Pin where the LDR sensor is connected
#define PH_PIN A2     // Pin where the pH sensor is connected

DHT dht(DHTPIN, DHTTYPE);          // Initialize DHT sensor
LiquidCrystal_I2C lcd(0x27, 16, 2); // Initialize LCD (I2C address 0x27)

void setup() {
  Serial.begin(9600);   // Start Serial monitor for debugging
  dht.begin();          // Initialize DHT sensor
  lcd.begin(16, 2);     // Initialize LCD
  lcd.backlight();      // Turn on the backlight of the LCD

  // Display startup message
  lcd.setCursor(0, 0);
  lcd.print("Soil Monitoring");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000); // Delay for 2 seconds
}

void loop() {
  // Read DHT sensor values (Temperature and Humidity)
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Read Soil Moisture level (Analog value between 0 and 1023)
  int soilMoistureValue = analogRead(SOIL_PIN);

  // Read Light Intensity from LDR (Analog value between 0 and 1023)
  int lightIntensity = analogRead(LDR_PIN);

  // Read pH level (Analog value from pH sensor)
  int pHValue = analogRead(PH_PIN);
  
  // Convert pH value to a readable scale (calibration required)
  float voltage = pHValue * (5.0 / 1023.0);  // Convert to voltage (5V scale)
  float pH = 3.5 * voltage; // Approximate formula for pH calculation

  // Check if readings are valid
  if (isnan(humidity) || isnan(temperature) || isnan(pH)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Error in DHT/PHS");
    delay(2000);
    return;
  }

  // Display environmental data on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("pH: ");
  lcd.print(pH);

  // Send the data to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C\t");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Soil Moisture: ");
  Serial.print(soilMoistureValue);
  Serial.print("\t");
  Serial.print("Light Intensity: ");
  Serial.print(lightIntensity);
  Serial.print("\t");
  Serial.print("pH: ");
  Serial.println(pH);

  // Determine soil condition
  if (pH < 6.0) {
    Serial.println("Soil is acidic");
  } else if (pH > 7.0) {
    Serial.println("Soil is alkaline");
  } else {
    Serial.println("Soil pH is neutral");
  }

  // Decision: Plant suitability
  if (pH >= 6.0 && pH <= 6.8 && soilMoistureValue > 400) {
    lcd.setCursor(0, 1);
    lcd.print("Tomato can grow ");
  }
  else if (pH >= 7.0 && soilMoistureValue < 400) {
    lcd.setCursor(0, 1);
    lcd.print("Cactus can grow ");
  }
  else if (pH >= 5.5 && pH <= 6.5 && soilMoistureValue > 400 && soilMoistureValue < 800) {
    lcd.setCursor(0, 1);
    lcd.print("Tulip can grow  ");
  } else {
    lcd.setCursor(0, 1);
    lcd.print("No suitable plant");
  }

  delay(2000); // Wait 2 seconds before next readings
}
