// Pin definitions
#define IR_LEFTMOST A0
#define IR_LEFT A1
#define IR_RIGHT A2
#define IR_RIGHTMOST A3

#define MOTOR_LEFT_1 5
#define MOTOR_LEFT_2 6
#define MOTOR_RIGHT_1 9
#define MOTOR_RIGHT_2 10

void setup() {
    pinMode(IR_LEFTMOST, INPUT);
    pinMode(IR_LEFT, INPUT);
    pinMode(IR_RIGHT, INPUT);
    pinMode(IR_RIGHTMOST, INPUT);

    pinMode(MOTOR_LEFT_1, OUTPUT);
    pinMode(MOTOR_LEFT_2, OUTPUT);
    pinMode(MOTOR_RIGHT_1, OUTPUT);
    pinMode(MOTOR_RIGHT_2, OUTPUT);

    Serial.begin(9600); // For debugging
}

void loop() {
    // Read sensor values
    int leftmost = digitalRead(IR_LEFTMOST);
    int left = digitalRead(IR_LEFT);
    int right = digitalRead(IR_RIGHT);
    int rightmost = digitalRead(IR_RIGHTMOST);

    // Print sensor values (for debugging)
    Serial.print("Sensors: ");
    Serial.print(leftmost);
    Serial.print(left);
    Serial.print(right);
    Serial.println(rightmost);

    // Robot movement logic
    if (left == LOW && right == LOW) {
        moveForward(); // Move straight
    } 
    else if (left == LOW) {
        turnLeft(); // Slight left
    } 
    else if (right == LOW) {
        turnRight(); // Slight right
    } 
    else if (leftmost == LOW) {
        sharpLeft(); // Hard left
    } 
    else if (rightmost == LOW) {
        sharpRight(); // Hard right
    } 
    else {
        stopMotors(); // Stop if no line detected
    }

    delay(100); // Small delay for stability
}

// Motor Control Functions
void moveForward() {
    digitalWrite(MOTOR_LEFT_1, HIGH);
    digitalWrite(MOTOR_LEFT_2, LOW);
    digitalWrite(MOTOR_RIGHT_1, HIGH);
    digitalWrite(MOTOR_RIGHT_2, LOW);
}

void turnLeft() {
    digitalWrite(MOTOR_LEFT_1, LOW);
    digitalWrite(MOTOR_LEFT_2, LOW);
    digitalWrite(MOTOR_RIGHT_1, HIGH);
    digitalWrite(MOTOR_RIGHT_2, LOW);
}

void turnRight() {
    digitalWrite(MOTOR_LEFT_1, HIGH);
    digitalWrite(MOTOR_LEFT_2, LOW);
    digitalWrite(MOTOR_RIGHT_1, LOW);
    digitalWrite(MOTOR_RIGHT_2, LOW);
}

void sharpLeft() {
    digitalWrite(MOTOR_LEFT_1, LOW);
    digitalWrite(MOTOR_LEFT_2, HIGH);
    digitalWrite(MOTOR_RIGHT_1, HIGH);
    digitalWrite(MOTOR_RIGHT_2, LOW);
}

void sharpRight() {
    digitalWrite(MOTOR_LEFT_1, HIGH);
    digitalWrite(MOTOR_LEFT_2, LOW);
    digitalWrite(MOTOR_RIGHT_1, LOW);
    digitalWrite(MOTOR_RIGHT_2, HIGH);
}

void stopMotors() {
    digitalWrite(MOTOR_LEFT_1, LOW);
    digitalWrite(MOTOR_LEFT_2, LOW);
    digitalWrite(MOTOR_RIGHT_1, LOW);
    digitalWrite(MOTOR_RIGHT_2, LOW);
}
