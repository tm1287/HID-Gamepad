#include <iostate.h>

ioState currState;

void setup() {
  // put your setup code here, to run once:
  currState.buttonOneState = 0x0;
  currState.buttonTwoState = 0x0;
  currState.buttonThreeState = 0x0;
  
  currState.joystickXState = 0x0;
  currState.joystickYState = 0x0;
  currState.joystickButtonState = 0x0;
  
  pinMode(b_ONE_PORT, INPUT);
 
  Serial.begin(115200);
}


void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(b_ONE_PORT) == HIGH) {
    currState.buttonOneState = 0xFF;
  } else {
    currState.buttonOneState = 0x0;
  }

  int16_t xState = map(analogRead(j_X_PORT), 0, 1023, -32768, 32767);
  int16_t yState = map(analogRead(j_Y_PORT), 0, 1023, -32768, 32767);

  currState.joystickXState = xState;  
  currState.joystickYState = yState;  

  Serial.write((byte*) &currState, sizeof(ioState));
  
  delay(100);
}
