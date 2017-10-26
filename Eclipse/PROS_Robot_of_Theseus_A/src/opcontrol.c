#include "main.h"

void driveControl() {
	int rJoy = joystickGetAnalog(1, 2);
	int lJoy = joystickGetAnalog(1, 3);
	motorSet(DRIVE_LEFT, lJoy);
	motorSet(DRIVE_RIGHT, -rJoy);
}

void clawControl() {
	if (joystickGetDigital(1, 6, JOY_UP)) {  //change 1 to 2 for partner control
		motorSet(CLAW_LEFT, 127);
		motorSet(CLAW_RIGHT, 127);
	} else if (joystickGetDigital(1, 6, JOY_DOWN)) {  //change 1 to 2 for partner control
		motorSet(CLAW_LEFT, -127);
		motorSet(CLAW_RIGHT, -127);
	} else {
		motorSet(CLAW_LEFT, 0);
		motorSet(CLAW_RIGHT, 0);
	}
}

void liftControl() {
	if (joystickGetDigital(1, 5, JOY_UP)){
		motorSet(ARM_RIGHT_TOP, -127);
		motorSet(ARM_RIGHT_BOT, -127);

		motorSet(ARM_LEFT_TOP, 127);
		motorSet(ARM_LEFT_BOT, 127);
	}
	else if (joystickGetDigital (1, 5, JOY_DOWN)) {
		motorSet(ARM_RIGHT_TOP, 127);
		motorSet(ARM_RIGHT_BOT, 127);

		motorSet(ARM_LEFT_TOP, -127);
		motorSet(ARM_LEFT_BOT, -127);
	} else {
		motorSet(ARM_RIGHT_TOP, 0);
		motorSet(ARM_RIGHT_BOT, 0);

		motorSet(ARM_LEFT_TOP, 0);
		motorSet(ARM_LEFT_BOT, 0);
	}

}

void operatorControl() {
	while (true) {

		driveControl();
		liftControl();
		clawControl();
		delay(25);
	}
}
