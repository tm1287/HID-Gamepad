#ifndef IOSTATE_H_
#define IOSTATE_H_

#include <Arduino.h>

  
#define b_ONE_PORT 2
#define b_TWO_PORT 3
#define b_THREE_PORT 4
#define j_X_PORT A0
#define j_Y_PORT A1
#define b_JOYSTICK_PORT 5

#define b_ONE_MAP 1
#define b_TWO_MAP 2
#define b_THREE_MAP 3
#define b_JOYSTICK_MAP 4

typedef struct ioState{
    uint8_t buttonOneState;
    uint8_t buttonTwoState;
	uint8_t buttonThreeState;
	
	int16_t joystickXState;
	int16_t joystickYState;
	int16_t joystickButtonState;
} ioState;

#endif