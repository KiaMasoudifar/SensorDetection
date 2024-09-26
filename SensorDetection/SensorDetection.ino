const int trigPin = 10; // Pin connected to Trig
const int echoPin = 11; // Pin connected to Echo
const int ledPin = 9;    // Pin connected to the LED
const int ledPin2 = 8;
const int buzzerPin = 7;

void setup() {
  pinMode(trigPin, OUTPUT); // Set Trig as an OUTPUT
  pinMode(echoPin, INPUT);  // Set Echo as an INPUT
  pinMode(ledPin, OUTPUT);   // Set LED pin as an OUTPUT
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);        // Start the serial communication 
}


void lightShow() {
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);

  digitalWrite(buzzerPin, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);

  delay(100);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(buzzerPin, LOW);

  delay(100);
}



void loop() {
  long duration, distance;

  // Send a 10 microsecond pulse to trigger the sensor
  digitalWrite(trigPin, LOW); // Ensure Trig is low
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // Trigger the sensor
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  // Stop the trigger

  // Read the echo time
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm (speed of sound = 340 m/s)
  distance = (duration / 2) * 0.0343; // divide by 2 for the round trip

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if the distance is less than or equal to 30.48 cm (1 foot)
  if (distance <= 60) {
    lightShow(); // Turn the LED on
  } else {
    digitalWrite(ledPin, LOW);  // Turn the LED off
    digitalWrite(ledPin2, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  delay(150); // Wait before the next measurement
}