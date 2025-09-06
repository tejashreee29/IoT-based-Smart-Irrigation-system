// Define pin numbers
const int moistureSensorPin = A0; // Soil Moisture Sensor connected to A0
const int motorPin = 8; // Relay or Motor Driver control pin connected to digital pin 8
const int moistureThreshold = 400; // Set the moisture threshold

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 baud rate
  pinMode(moistureSensorPin, INPUT); // Set the soil moisture sensor pin as input
  pinMode(motorPin, OUTPUT); // Set the motor control pin as output
  digitalWrite(motorPin, LOW); // Ensure motor/relay is off initially
}

void loop() {
  int sensorValue = analogRead(moistureSensorPin); // Read the value from the moisture sensor
  Serial.print("Soil Moisture = ");
  Serial.println(sensorValue); // Print the moisture value to the Serial Monitor

  // Check the moisture level
  if(sensorValue < moistureThreshold) {
    // Soil is dry - activate the motor/relay
    digitalWrite(motorPin, HIGH);
    Serial.println("Motor ON");
  } else {
    // Soil is wet - deactivate the motor/relay
    digitalWrite(motorPin, LOW);
    Serial.println("Motor OFF");
  }
  
  delay(1000); // Wait for 1 second before the next reading
}