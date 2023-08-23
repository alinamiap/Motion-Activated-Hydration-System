//constants used to set pin numbers
const int SENSOR_PIN = 7;
const int LED_PIN = 13;
const int WATER_PUMP = 6;
const int echoPin = 10;
const int trigPin = 9;

//variables
long duration;
int distance;

void setup(){
//initialize serious communication at 9600 bits per second
Serial.begin(9600);
//initialize Arduino's pin as an input
pinMode(SENSOR_PIN, INPUT);
pinMode(echoPin, INPUT);
//initialize remaining digital pins as an output
pinMode(LED_PIN, OUTPUT);
pinMode(WATER_PUMP, OUTPUT);
pinMode(trigPin, OUTPUT);
}

void loop(){
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = duration*0.034/2;

if (distance < 20){
digitalWrite(LED_PIN, HIGH);
digitalWrite(WATER_PUMP, HIGH);
Serial.print("The distance is: ");
Serial.print(distance);
Serial.println(" cm. Watering...");
}
else {
digitalWrite(LED_PIN, LOW);
digitalWrite(WATER_PUMP, LOW);
Serial.print("Distance is: ");
Serial.print(distance);
Serial.println(" cm. Object out of range");
}
}
