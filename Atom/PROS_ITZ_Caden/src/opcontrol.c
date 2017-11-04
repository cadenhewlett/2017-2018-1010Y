#include "main.h"


/*  comment dictionary:
 *  1. before a comment have a double space
 *  2. if something is unknown or needs to be expanded on put it in (BRACKETS) to be fixed later
 *  3. to talk about something a function does in a small profile define it in [SQUARE BRACKETS]
 *  4. if a comment ends with a "-" that means it very closely trails into the description of the next code or it simply means "(onwards)" for numbers  ...not always needed
 *  5. notes in comments have a double space then "..." at the start
 *  6. important information is like a note but uses "!!!" at the start and back
 *
 *  organization dictionary:
 *  1. old comments have capital letters, new notes do not  ...fix old comments
 *  2-. (WIP)
 */


void driveControl() {  //control function for driving  ...tank control
	int rJoy = joystickGetAnalog(1, 2);  //get an integer from the right joy stick  ...after joystickGetAnalog there are brackets with numbers, these number correspond firstly which controller uses this code and secondly the joy stick port
	int lJoy = joystickGetAnalog(1, 3);  //get an integer from the left joy stick  ...after joystickGetAnalog there are brackets with numbers, these number correspond firstly which controller uses this code and secondly the joy stick port
	motorSet(DRIVE_LEFT, lJoy);  //right tank control of wheels moving based on integers above this line
	motorSet(DRIVE_RIGHT, -rJoy);  //right tank control of wheels moving based on integers above this line
}


void intakeControl() {  //control function for intake
	if (joystickGetDigital(1, 6, JOY_UP)) {  //get an integer from the joy stick (right up) trigger  !!!CHANGE 1 TO 2 TO CHANGE TO PARTNER CONTROL!!!  ...after joystickGetAnalog there are brackets with numbers, these number correspond firstly which controller uses this code and secondly the joy stick port
		motorSet(INTAKE_LEFT, -127);  //intake control movement based on true/false command above this line (whether or not the trigger is pushed)
		motorSet(INTAKE_RIGHT, 127);  //intake control movement based on true/false command above this line (whether or not the trigger is pushed)
	} else if (joystickGetDigital(1, 6, JOY_DOWN)) {  //get an integer from the joy stick (right up) trigger  !!!CHANGE 1 TO 2 TO CHANGE TO PARTNER CONTROL!!!  ...after joystickGetAnalog there are brackets with numbers, these number correspond firstly which controller uses this code and secondly the joy stick port
		motorSet(INTAKE_LEFT, 127);  //intake control movement based on true/false command above this line (whether or not the trigger is pushed)
		motorSet(INTAKE_RIGHT, -127);  //intake control movement based on true/false command above this line (whether or not the trigger is pushed)
	} else { //if nothing else is happening then...
		motorSet(INTAKE_LEFT, 0);  //if the trigger is not pushed the intake does not move
		motorSet(INTAKE_RIGHT, 0);  //if the trigger is not pushed the intake does not move
	}
}


void clawControl() {  //control function for claw  ...need to add encoder so it stays in one position
	if (joystickGetDigital(2, 6, JOY_UP)) {  //get an integer from the joy stick (right up) trigger  !!!CHANGE 1 TO 2 TO CHANGE TO PARTNER CONTROL!!!  ...after joystickGetAnalog there are brackets with numbers, these number correspond firstly which controller uses this code and secondly the joy stick port
		motorSet(CLAW, -127);  //claw control movement based on true/false command above this line (whether or not the trigger is pushed)
	} else if (joystickGetDigital(2, 6, JOY_DOWN)) {  //get an integer from the joy stick (right up) trigger  !!!CHANGE 1 TO 2 TO CHANGE TO PARTNER CONTROL!!!  ...after joystickGetAnalog there are brackets with numbers, these number correspond firstly which controller uses this code and secondly the joy stick port
		motorSet(CLAW, 127);  //claw control movement based on true/false command above this line (whether or not the trigger is pushed)
	} else { //if nothing else is happening then...
		motorSet(CLAW, 0);  //if the trigger is not pushed the claw does not move
	}
}


void liftControl() {  //control function for lift
	if (joystickGetDigital(2, 5, JOY_UP)){  //get an integer from the joy stick (left up) trigger  !!!CHANGE 1 TO 2 TO CHANGE TO PARTNER CONTROL!!!  ...after joystickGetAnalog there are brackets with numbers, these number correspond firstly which controller uses this code, secondly the joy stick port, thirdly the specific placement of say a trigger
		motorSet(ARM_RIGHT_TOP, 127);  //lift control movement based on true/false command above this line (whether or not the trigger is pushed)
		motorSet(ARM_RIGHT_BOT, 127);  //lift control movement based on true/false command above this line (whether or not the trigger is pushed)
		motorSet(ARM_LEFT_TOP, -127);  //lift control movement based on true/false command above this line (whether or not the trigger is pushed)
		motorSet(ARM_LEFT_BOT, -127);  //lift control movement based on true/false command above this line (whether or not the trigger is pushed)

	} else if (joystickGetDigital (2, 5, JOY_DOWN)) {  //get an integer from the joy stick (left up) trigger  !!!CHANGE 1 TO 2 TO CHANGE TO PARTNER CONTROL!!!  ...after joystickGetAnalog there are brackets with numbers, these number correspond firstly which controller uses this code, secondly the joy stick port, thirdly the specific placement of say a trigger
		motorSet(ARM_RIGHT_TOP, -127);  //lift control movement based on true/false command above this line (whether or not the trigger is pushed)
		motorSet(ARM_RIGHT_BOT, -127);  //lift control movement based on true/false command above this line (whether or not the trigger is pushed)
		motorSet(ARM_LEFT_TOP, 127);  //lift control movement based on true/false command above this line (whether or not the trigger is pushed)
		motorSet(ARM_LEFT_BOT, 127);  //lift control movement based on true/false command above this line (whether or not the trigger is pushed)

	} else {  //if nothing else is happening then-  ...Change to a constant power based on location to stay still where the claw is left
		motorSet(ARM_RIGHT_TOP, 0);  //if the trigger is not pushed the claw does not move
		motorSet(ARM_RIGHT_BOT, 0);  //if the trigger is not pushed the claw does not move
		motorSet(ARM_LEFT_TOP, 0);  //if the trigger is not pushed the claw does not move
		motorSet(ARM_LEFT_BOT, 0);  //if the trigger is not pushed the claw does not move
	}
}


void operatorControl() {  //operator control function that dictates which function run  !!!DO NOT DELETE!!!
	while (true) {  //while the operator has control-
		driveControl();  //driving function plays
		intakeControl();  //intake function plays
		liftControl();  //lift function plays
		clawControl();  //claw function plays
		delay(25);  //delay timer to not spam the cortex with commands  ...does not interfere with control  ...based on milliseconds

		lcdClear(uart1);  //clears the lcd screen fully
		lcdPrint(uart1, 1, "1010 A");  //writes "1010Y" on the first lcd line
		lcdPrint(uart1, 2, "Batt: %1.3f V", (double)powerLevelMain() / 1000);  //writes [battery power] on the second lcd line
	}
}
