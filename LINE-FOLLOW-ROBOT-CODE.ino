const int leftSensor = A0; // Left sensor pin
const int rightSensor = A1; // Right sensor pin
const int leftMotor = 2; // Left motor pin
const int rightMotor = 3; // Right motor pin

void setup() {
pinMode(leftSensor, INPUT);
pinMode(rightSensor, INPUT);
pinMode(leftMotor, OUTPUT);
pinMode(rightMotor, OUTPUT);
}

void loop() {
int leftValue = analogRead(leftSensor);
int rightValue = analogRead(rightSensor);
  
if (leftValue < 500 && rightValue < 500) {
// Both sensors detect line forward();
} else if (leftValue < 500) { // Left sensor
  
  if (leftValue < 500 && rightValue < 500) {
// Both sensors detect line forward();
} else if (leftValue < 500) { // Left sensor detects line turnLeft();
} else if (rightValue < 500) { // Right sensor detects line turnRight();
} else { // No line detected
stop();
}
}
  
void forward() {
digitalWrite(leftMotor, HIGH);
digitalWrite(rightMotor, HIGH);
}
  
void turnLeft() {
digitalWrite(leftMotor, LOW);
digitalWrite(rightMotor, HIGH);
}
void turnRight() {
  digitalWrite(leftMotor, HIGH);
digitalWrite(rightMotor, HIGH);
}
  
void turnLeft() {
digitalWrite(leftMotor, LOW);
digitalWrite(rightMotor, HIGH);
}
  
void turnRight() {
digitalWrite(leftMotor, HIGH);
digitalWrite(rightMotor, LOW);
}
  
void stop() {
digitalWrite(leftMotor, LOW);
digitalWrite(rightMotor, LOW);
}
