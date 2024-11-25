const int ch2Pin = 4;  // Pin to read the channel for forward/backward control
const int ch1Pin = 5;  // Pin to read the channel for left/right control

unsigned long ch2Value = 0; // Value for forward/backward channel pulse width
unsigned long ch1Value = 0; // Value for left/right channel pulse width

// Motor A pins
int d1 = 7;   // IN1 on L298N for Motor A direction
int d2 = 6;   // IN2 on L298N for Motor A direction
int p1 = 9;   // ENA on L298N for Motor A speed (PWM)

// Motor B pins
int d3 = 11;  // IN3 on L298N for Motor B direction
int d4 = 12;  // IN4 on L298N for Motor B direction
int p2 = 10;  // ENB on L298N for Motor B speed (PWM)

void setup() {
  Serial.begin(9600);

  // Set up Motor A pins
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(p1, OUTPUT);

  // Set up Motor B pins
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(p2, OUTPUT);
}

void loop() {
  // Measure the pulse width of the signals on channels 1 and 2
  ch2Value = pulseIn(ch2Pin, HIGH);
  ch1Value = pulseIn(ch1Pin, HIGH);

  // Print debug values to monitor pulse width input
  Serial.print("ch1Value: ");
  Serial.print(ch1Value);
  Serial.print("\tch2Value: ");
  Serial.println(ch2Value);

  // Determine movement direction based on pulse width readings
  if (ch2Value >= 1660) {
    Backward();
  } else if (ch2Value <= 1100) {
    Forward();
  } else if (ch1Value >= 1600) {
    Right();
  } else if (ch1Value <= 1100) {
    Left();
  } else if (ch1Value >= 1200 && ch1Value <= 1550 && ch2Value >= 1200 && ch2Value <= 1550) {
    Stop();
  }
}

// Motor control functions
void Forward() {
  digitalWrite(d1, HIGH);  // Motor A forward
  digitalWrite(d2, LOW);
  analogWrite(p1, 255);    // Full speed for Motor A

  digitalWrite(d3, HIGH);  // Motor B forward
  digitalWrite(d4, LOW);
  analogWrite(p2, 255);    // Full speed for Motor B

  Serial.println("Moving Forward");
}

void Backward() {
  digitalWrite(d1, LOW);   // Motor A backward
  digitalWrite(d2, HIGH);  // Reverse direction for Motor A
  analogWrite(p1, 255);    // Full speed for Motor A
  Serial.println("Motor A Moving Backward");

  digitalWrite(d3, LOW);   // Motor B backward
  digitalWrite(d4, HIGH);  // Reverse direction for Motor B
  analogWrite(p2, 255);    // Full speed for Motor B
  Serial.println("Motor B Moving Backward");

  Serial.println("Moving Backward");
}

void Left() {
  digitalWrite(d1, HIGH);  // Motor A forward
  digitalWrite(d2, LOW);
  analogWrite(p1, 255);    // Full speed for Motor A

  digitalWrite(d3, LOW);   // Motor B backward
  digitalWrite(d4, HIGH);
  analogWrite(p2, 255);    // Full speed for Motor B

  Serial.println("Turning Left");
}

void Right() {
  digitalWrite(d1, LOW);   // Motor A backward
  digitalWrite(d2, HIGH);
  analogWrite(p1, 255);    // Full speed for Motor A

  digitalWrite(d3, HIGH);  // Motor B forward
  digitalWrite(d4, LOW);
  analogWrite(p2, 255);    // Full speed for Motor B

  Serial.println("Turning Right");
}

void Stop() {
  digitalWrite(d1, LOW);   // Stop Motor A
  digitalWrite(d2, LOW);
  analogWrite(p1, 0);

  digitalWrite(d3, LOW);   // Stop Motor B
  digitalWrite(d4, LOW);
  analogWrite(p2, 0);

  Serial.println("Stop");
}