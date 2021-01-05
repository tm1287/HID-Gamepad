#include "HID-Project.h"
#include <iostate.h>
int buttonState = 0;
/**
 * This sketch is meant to be flashed onto the 16u2 chip of the modified UNO.
 * 
 * It will recieve the IO state from the ATMega328P chip over serial communication
 * and construct the relevant gamepad HID report.
 * 
 * It will then send the HID report over USB to the OS.
 * 
 * - Tejas Maraliga 1/4/21
 */
ioState* currStatePtr;

void setup() {
  
  Serial1.begin(115200);
  
  // Send the HID descriptor
  Gamepad.begin();
  
  Serial.begin(115200);
}

void loop() {
  // Get the button state from the I/O MCU.
  byte recvArr[sizeof(ioState)];
  Serial1.readBytes(recvArr, sizeof(ioState));

  currStatePtr = (ioState*) recvArr;
  Serial.println(currStatePtr->buttonOneState, HEX);
  if(currStatePtr->buttonOneState == 0xFF){
    Gamepad.press(b_ONE_MAP);
  } else {
    Gamepad.release(b_ONE_MAP); 
  }

  Gamepad.xAxis(currStatePtr->joystickXState);
  Gamepad.yAxis(currStatePtr->joystickYState);

  //Send the HID report to the OS.
  Gamepad.write();
}
