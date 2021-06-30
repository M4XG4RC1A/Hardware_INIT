
int redLed = 7;
int yellowLed = 5;
int greenLed = 3;

int greenTime = 7;
int yellowTime = 1;
int yellowRepeat = 3;
int redTime = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLed,OUTPUT);
  pinMode(yellowLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  Serial.begin(9600);
  Serial.println("Starting");
  digitalWrite(redLed,LOW);
  digitalWrite(greenLed,LOW);
  digitalWrite(yellowLed,LOW);
  delay(3000);
}

void loop() { 
  digitalWrite(redLed,LOW);
  digitalWrite(greenLed,HIGH);
  Serial.println("Green");
  delay(greenTime*1000);
  digitalWrite(greenLed,LOW);
  Serial.println("Yellow");
  for(int i=0;i<yellowRepeat*2;i++){
    digitalWrite(yellowLed,!digitalRead(yellowLed));
    delay(yellowTime*1000/2);
  }
  Serial.println("Red");
  digitalWrite(yellowLed,LOW);
  digitalWrite(redLed,HIGH);
  delay(redTime*1000);
  digitalWrite(redLed,LOW);
  digitalWrite(yellowLed,!digitalRead(yellowLed));
  delay(yellowTime*1000/2);
  digitalWrite(yellowLed,!digitalRead(yellowLed));
  delay(yellowTime*1000/2);
}
