/*
 * autoFunctions.h
 *
 *  Created on: Feb 8, 2017
 *      Author: James
 */


#ifndef INCLUDE_AUTOFUNCTIONS_H_
#define INCLUDE_AUTOFUNCTIONS_H_


#include "math.h"
#include "main.h"


void clearDrive() {
	motorSet(DRIVE_LEFT, 0);
	motorSet(DRIVE_RIGHT, 0);
}


void clearArm() {
	motorSet(ARM_RIGHT_TOP, 0);
	motorSet(ARM_RIGHT_BOT, 0);
	motorSet(ARM_LEFT_TOP, 0);
	motorSet(ARM_LEFT_BOT, 0);
}


void clearClaw() {
	motorSet(CLAW_LEFT, 0);
	motorSet(CLAW_RIGHT, 0);
}


void motorsDrive(int power) {
	motorSet(DRIVE_LEFT, power);
	motorSet(DRIVE_RIGHT, -(power));  //can I make minus 5?
}


void motorsArm(int power) {
	motorSet(ARM_RIGHT_TOP, -power);
	motorSet(ARM_RIGHT_BOT, -power);
	motorSet(ARM_LEFT_TOP, power);
	motorSet(ARM_LEFT_BOT, power);
}


void motorsClaw(int power) {
	motorSet(CLAW_LEFT, power);
	motorSet(CLAW_RIGHT, power);
}


// Main drive function to go forward/backward
void drive(int distance, int way) {
	encoderReset(encLeft);
	encoderReset(encRight);
	while ( (abs(encoderGet(encRight)) + abs(encoderGet(encLeft)) / 2 ) < distance) {
		if (way == 1) { motorsDrive(127); }
		if (way == 2) { motorsDrive(-127); }
		delay(25);
	}
	clearDrive();
}

void driveClosedClaw(int distance, int way) {
	encoderReset(encLeft);
	encoderReset(encRight);
	while ( (abs(encoderGet(encRight)) + abs(encoderGet(encLeft)) / 2 ) < distance) {
		if (way == 1) {
			motorsClaw(100);
			motorsDrive(127);
		}
		if (way == 2) {
			motorsClaw(100);
			motorsDrive(-127);
		}
		delay(25);
	}
	clearClaw();
	clearDrive();
}

void rotate(int power, int way){
		if (way == 1) { motorSet(DRIVE_LEFT, power);
		motorSet(DRIVE_RIGHT, (power));	}
		if (way == 2) { motorSet(DRIVE_LEFT, -power);
				motorSet(DRIVE_RIGHT, (-power));	}
}


void arm(int time, int way) {
	if(way == 1) {
		motorsArm(127);
		delay(time);
	}
	if (way == 2) {
		motorsArm(-127);
		delay(time);
	}
	clearArm();
}


void claw(int time, int way) {
	if(way == 1) {
		motorsClaw(127);
		delay(time);
	}
	if (way == 2) {
		motorsClaw(-127);
		delay(time);
	}
	clearClaw();
}


#endif /* INCLUDE_AUTOFUNCTIONS_H_ */
