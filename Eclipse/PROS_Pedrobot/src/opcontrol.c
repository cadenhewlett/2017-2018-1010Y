#include "main.h"

void driveControl() {
	int rJoy = joystickGetAnalog(1, 2);
	int lJoy = joystickGetAnalog(1, 3);
	motorSet(1, -lJoy);
	motorSet(2, -lJoy);
	motorSet(9, rJoy);
	motorSet(10,  rJoy);

}

void liftControl() {
	if (joystickGetDigital(1, 5, JOY_UP)){
		motorSet(3, -127);
		motorSet(4, 127);
		motorSet(7, -127);
		motorSet(8, 127);

	} else if (joystickGetDigital (1, 5, JOY_DOWN)) {
		motorSet(3, 127);
		motorSet(4, 127);
		motorSet(7, -127);
		motorSet(8, -127);

	} else {
		motorSet(3, 0);
		motorSet(4, 0);
		motorSet(7, 0);
		motorSet(8, 0);
	}
}


void operatorControl() {
	while (true) {
		driveControl();
		liftControl();
		delay(25);
	}
}
