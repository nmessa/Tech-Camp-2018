/* This simple project describes how to make an ultrasonic alarm system using 
LED, Ultasonic Sensor(HC-SR04) and a buzzer.*/ 

//Firstly the connections of ultrasonic Sensor.Connect +5v and GND normally and trigger pin to 12
//& echo pin to 13. 

#define trigPin 12
#define echoPin 13
int Buzzer = 8; // Connect buzzer pin to 8
int ledPin= 6;  //Connect LEd pin to 6
int duration, distance; //to measure the distance and time taken 

void setup() {
    Serial.begin (9600); 
    //Define the output and input objects(devices)
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT);
    pinMode(Buzzer, OUTPUT);
    pinMode(ledPin, OUTPUT);
}

void loop() {

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    //when object is more than 30 cm,the buzzer and LED are off
    if (distance >= 30){
        Serial.println("no object detected");
        digitalWrite(Buzzer,LOW);
        digitalWrite(ledPin,LOW);
        noTone(Buzzer);
    }
    else {
        Serial.println("object detected \n");
        Serial.print("distance= ");              
        Serial.println(distance);        //prints the distance if it is between the range 0 to 200
        tone(Buzzer,400);              // play tone of 400Hz for 500 ms
        digitalWrite(ledPin,HIGH);
    }
}
