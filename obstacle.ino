#include <NewPing.h>

#define TRIGGER_PIN 12
#define ECHO_PIN 11
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
#define enA 9
#define in1 3
#define in2 4

#define enB 10
#define in3 5
#define in4 6
void setup() {
    // Initialize motor pins and other setup if needed
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  Serial.begin(9600);
  
  // Set enable pins to HIGH to keep motors always enabled
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
}

void loop() {
    long duration;
    unsigned int distance = sonar.ping_cm();
      
    // Clear the trigPin
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    
    // Set the trigPin on HIGH state for 10 microseconds
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);
    
    // Read the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(ECHO_PIN, HIGH);
    
    // Calculate the distance
    distance = (duration * 0.034) / 2; // Speed of sound wave divided by 2 (go and back)
    
    // Print the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);
    if (distance > 5) {
        // Move forward
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        // Implement motor control logic here

    } 
    else {
        // Avoid obstacle
        // Change direction or stop motors
        // Stop the robot
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        delay(500);
        
        // Move robot backward
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        delay(500);
        
        // Turn the robot right
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        delay(500);
    }
}
