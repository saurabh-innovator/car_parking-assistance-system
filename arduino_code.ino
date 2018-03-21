//car parking assistance sensor.
int IRpin = A0;               // IR photodiode on analog pin A0
int IRemitter = 2;            // IR emitter LED on digital pin 2
int ambientIR;                // variable to store the IR coming from the ambient
int obstacleIR;               // variable to store the IR coming from the object
int value[10];                // variable to store the IR values
int distance;                 // variable that will tell if there is an obstacle or not

void setup(){
  Serial.begin(9600);         // initializing Serial monitor
  pinMode(IRemitter,OUTPUT);  // IR emitter LED on digital pin 2
  digitalWrite(IRemitter,LOW);// setup IR LED as off
  pinMode(11,OUTPUT);         // buzzer in digital pin 11
}

void loop(){
  distance = readIR(5);       // calling the function that will read the distance and passing the "accuracy" to it
  Serial.println(distance);   // writing the read value on Serial monitor
   buzzer();                // uncomment to activate the buzzer function
}

int readIR(int times){
  for(int x=0;x<times;x++){     
    digitalWrite(IRemitter,LOW);           // turning the IR LEDs off to read the IR coming from the ambient
    delay(1);                                             // minimum delay necessary to read values
    ambientIR = analogRead(IRpin);  // storing IR coming from the ambient
    digitalWrite(IRemitter,HIGH);          // turning the IR LEDs on to read the IR coming from the obstacle
    delay(1);                                             // minimum delay necessary to read values
    obstacleIR = analogRead(IRpin);  // storing IR coming from the obstacle
    value[x] = ambientIR-obstacleIR;   // calculating changes in IR values and storing it for future average
  }
 
  for(int x=0;x<times;x++){        // calculating the average based on the "accuracy"
    distance+=value[x];
  }
  return(distance/times);            // return the final value
}


//-- Function to sound a buzzer for audible measurements --//
void buzzer(){
  if (distance>1){
    if(distance>100){ // continuous sound if the obstacle is too close
      digitalWrite(11,HIGH);
    }
    else{  // beeps faster when an obstacle approaches
      digitalWrite(11,HIGH);
      delay(150-distance);  // adjust this value for your convenience
      digitalWrite(11,LOW);
      delay(150-distance);  // adjust this value for your convenience
    }
  }
  else{  // off if there is no obstacle
    digitalWrite(11,LOW);
  }
}
