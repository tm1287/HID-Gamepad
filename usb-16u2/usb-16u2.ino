#include "HID-Project.h"

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

void setup() {
  Serial1.begin(115200);

  // Send the HID descriptor
  Gamepad.begin();
  
  Serial.begin(115200);
}

void loop() {
  // Get the button state from the I/O MCU.
  char buttonState = Serial1.read();

  if (buttonState >= 'A' && buttonState <= 'Z') {
    Serial.print(F("16u2: "));
    Serial.print(buttonState);
    Serial.print('\n');
}
  //Send the HID report to the OS.
  Gamepad.write();
}
