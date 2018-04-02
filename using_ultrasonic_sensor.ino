#define trigPin 13
#define echoPin 12
#define led 11
#define led2 10
long distance;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  digitalWrite(7, HIGH);
}

void loop() {
  long duration;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 4) {  // This is where the LED On/Off happens
    digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
  digitalWrite(led2,LOW);
}
  else {
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);
  }
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
  buzzer();   
}
void buzzer(){
  if (distance>1){
    if(distance>=1 && distance<=10){ // continuous sound if the obstacle is too close
      digitalWrite(5,HIGH);
    }
    else if(distance>=11 && distance<=20){  // beeps faster when an obstacle approaches
      digitalWrite(5,HIGH);
      delay(50);  // adjust this value for your convenience
      digitalWrite(5,LOW);
      delay(50);  // adjust this value for your convenience
    }
    else if(distance>=21 && distance<=35){  // beeps faster when an obstacle approaches
      digitalWrite(5,HIGH);
      delay(100);  // adjust this value for your convenience
      digitalWrite(5,LOW);
      delay(100);  // adjust this value for your convenience
    }
    else if(distance>=36 && distance<=50){  // beeps faster when an obstacle approaches
      digitalWrite(5,HIGH);
      delay(150);  // adjust this value for your convenience
      digitalWrite(5,LOW);
      delay(150);  // adjust this value for your convenience
    }
     else if(distance>=51 && distance<=65){  // beeps faster when an obstacle approaches
      digitalWrite(5,HIGH);
      delay(220);  // adjust this value for your convenience
      digitalWrite(5,LOW);
      delay(220);  // adjust this value for your convenience
    }
    else{  // off if there is no obstacle
    digitalWrite(5,LOW);
  }
  
  }
}
