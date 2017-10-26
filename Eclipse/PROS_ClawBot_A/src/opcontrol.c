#include "main.h"

void driveControl() {
	int rJoy = joystickGetAnalog(1, 2);
	int lJoy = joystickGetAnalog(1, 3);
	motorSet(DRIVE_LEFT, lJoy);
	motorSet(DRIVE_RIGHT, -rJoy);
}

void clawControl() {  //need to add encoder so it stays in one position.
	if (joystickGetDigital(1, 6, JOY_UP)) {  //change 1 to 2 for partner control
		motorSet(CLAW, -127);
	} else if (joystickGetDigital(1, 6, JOY_DOWN)) {
		motorSet(CLAW, 127);
	} else {
		motorSet(CLAW, 0);
	}
}


void liftControl() {
	if (joystickGetDigital(1, 5, JOY_UP)){
		motorSet(ARM, -127);

	} else if (joystickGetDigital (1, 5, JOY_DOWN)) {
		motorSet(ARM, 127);

	} else {
		motorSet(ARM, 0);
	}
}


void operatorControl() {
	while (true) {
		//lcdClear(uart1);
		//lcdPrint(uart1, 2, "1010 Y");
		//lcdPrint(uart1, 1, "Batt: %1.3f V", (double)powerLevelMain() / 1000);

		driveControl();
		liftControl();
		clawControl();
		delay(25);
	}
}
