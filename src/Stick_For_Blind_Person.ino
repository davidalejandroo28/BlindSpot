// pins numbers for the Shikamu No Me
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 13;

// variables 
long duration; //
int distance;
int safetyDistance;


void setup() {
pinMode(trigPin, OUTPUT); // trigPin as an Output
pinMode(echoPin, INPUT); //echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); //communication
}


void loop() {
// Clears data
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// trigPin on HIGH state
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// 
duration = pulseIn(echoPin, HIGH);

// Distance
distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance <= 25){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
}

// Prints the distance 
Serial.print("Distance: ");
Serial.println(distance);
}
