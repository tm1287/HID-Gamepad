const int buttonPin = 2;
int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  Serial.begin(115200);
}


void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH) {
    Serial.write('H');
  } else {
    Serial.write('L');
  }
  delay(10);
}
