#include "main.h"

void driveControl() {
	int rJoy = joystickGetAnalog(1, 2);
	int lJoy = joystickGetAnalog(1, 3);
	motorSet(DRIVE_LEFT, lJoy);
	motorSet(DRIVE_RIGHT, -rJoy);
}

void clawControl() {  //need to add encoder so it stays in one position.
	if (joystickGetDigital(1, 6, JOY_UP)) {  //change 1 to 2 for partner control
		motorSet(CLAW_LEFT, -127);
		motorSet(CLAW_RIGHT, 127);
	} else if (joystickGetDigital(1, 6, JOY_DOWN)) {
		motorSet(CLAW_LEFT, 127);
		motorSet(CLAW_RIGHT, -127);
	} else {
		motorSet(CLAW_LEFT, 0);
		motorSet(CLAW_RIGHT, 0);
	}
}


void liftControl() {
	if (joystickGetDigital(1, 5, JOY_UP)){
		motorSet(ARM_RIGHT_OUT, -127);
		motorSet(ARM_RIGHT_IN, -127);
		motorSet(ARM_LEFT_OUT, 127);
		motorSet(ARM_LEFT_IN, 127);

	} else if (joystickGetDigital (1, 5, JOY_DOWN)) {
		motorSet(ARM_RIGHT_OUT, 127);
		motorSet(ARM_RIGHT_IN, 127);
		motorSet(ARM_LEFT_OUT, -127);
		motorSet(ARM_LEFT_IN, -127);

	} else {
		motorSet(ARM_RIGHT_OUT, 0);
		motorSet(ARM_RIGHT_IN, 0);
		motorSet(ARM_LEFT_OUT, 0);
		motorSet(ARM_LEFT_IN, 0);
	}
}


void operatorControl() {
	while (true) {
		lcdClear(uart1);
		lcdPrint(uart1, 2, "1010 Y");
		lcdPrint(uart1, 1, "Batt: %1.3f V", (double)powerLevelMain() / 1000);

		driveControl();
		liftControl();
		clawControl();
		delay(25);
	}
}
