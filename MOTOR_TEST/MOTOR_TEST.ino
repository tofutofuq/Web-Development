#include <Servo.h> 

// Create a Servo object
Servo myservo;

// Pin assignments
const int sensorPin = A0; // Analog pin where the sensor is connected

// Variables to control servo movement
int currentAngle = 0;   // Current angle of the servo
int targetAngle = 180;  // Target angle for the servo (180 degrees)
int stepSize = 5;       // Number of degrees to move the servo per update
bool movingForward = true; // Flag to determine the direction of movement

void setup() 
{
    // Attach the servo to pin 4
    myservo.attach(4);
    // Initialize serial communication
    Serial.begin(9600);
}

void loop() 
{
    // Move the servo based on the current direction
    if (movingForward) {
        if (currentAngle < targetAngle) {
            currentAngle += stepSize;
            if (currentAngle > targetAngle) {
                currentAngle = targetAngle;
            }
        } else {
            movingForward = false; // Change direction to reverse
        }
    } else {
        if (currentAngle > 0) {
            currentAngle -= stepSize;
            if (currentAngle < 0) {
                currentAngle = 0;
            }
        } else {
            movingForward = true; // Change direction to forward
        }
    }
    
    // Set the servo to the current angle
    myservo.write(currentAngle);
    
    // Print the current angle for debugging
    Serial.print("Current Angle: ");
    Serial.println(currentAngle);
    
    // Delay for stability (adjust delay to control speed of movement)
    delay(100); // Adjust delay to speed up or slow down the servo movement
}
