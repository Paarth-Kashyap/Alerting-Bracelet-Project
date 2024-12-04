//declare pin locations for microphone, motor, and LED

int mic_pin_analog= A0; // Set the analog pin for the microphone
const int mic_pin_digital=2; //mic digitsal in 

int redPin = 9;
int greenPin = 10;
int yellowPin = 8;

int motor_pin=12;
int curr_lvl; //varaible for current noise level

//int loud=550, quiet=534;  //more sensetive
int loud=555, quiet=540;  //less sensetive
 
void setup() {

  //declare the input and output loads
  pinMode(motor_pin, OUTPUT); //output for motor
  
  pinMode(redPin, OUTPUT);    // output for different lights
  pinMode(greenPin, OUTPUT);  
  pinMode(yellowPin, OUTPUT);

  pinMode(mic_pin_analog, INPUT); //input for mic

  Serial.begin(9600);  // Open serial communication at 9600 baud
}

void loop() {  
  curr_lvl = analogRead(mic_pin_analog); // Read sound sensor value
  Serial.println(curr_lvl);  // Print sound sensor value to serial monitor

  if(curr_lvl>loud){
    Serial.println("\n");
    digitalWrite(motor_pin, HIGH);      // Turn on vibrating motor
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, LOW);
    delay(1000);
  }

  if (curr_lvl<loud && curr_lvl>quiet) {
    digitalWrite(greenPin, LOW);   
    digitalWrite(yellowPin, HIGH);  // yellow light
    digitalWrite(motor_pin, HIGH);
    delay(250);
          
    digitalWrite(redPin, LOW);
  }
  if(digitalRead(yellowPin == HIGH)){
        digitalWrite(greenPin, LOW);
  }
  if(curr_lvl<quiet){
    digitalWrite(greenPin, HIGH);
    digitalWrite(motor_pin, LOW);       // Turn off vibrating motor
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
  }
}
