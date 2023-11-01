int enA = 8;
int enB = 9;
int rightPin1 = 28;
int rightPin2 = 32;
int leftPin1 = 34;
int leftPin2 = 36;
int echoPin1 = 24;
int trigPin1 = 22;

int echoPinLeft = 23;
int trigPinLeft = 25;

int echoPinRight = 27;
int trigPinRight = 29;




long duration;
long distance;

void setup() {
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(rightPin1, OUTPUT);
  pinMode(rightPin2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(leftPin1, OUTPUT);
  pinMode(leftPin2, OUTPUT);
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  digitalWrite(rightPin1, HIGH);
  digitalWrite(rightPin2, LOW);
  digitalWrite(leftPin1, LOW);
  digitalWrite(leftPin2, HIGH);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // Wait for 1000 millisecond(s)
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);// Wait for 1000 millisecond(s)
  
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration/58.2;
  
  Serial.println(distance);

  if(distance < 15) {
    digitalWrite(rightPin1, LOW);
    digitalWrite(rightPin2, HIGH);
  }
  else {
    digitalWrite(rightPin1, HIGH);
    digitalWrite(rightPin2, LOW);
  }
  delay(50);
}