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
	motorSet(ARM_RIGHT_OUT, 0);
	motorSet(ARM_RIGHT_IN, 0);
	motorSet(ARM_LEFT_OUT, 0);
	motorSet(ARM_LEFT_IN, 0);
}


void clearClaw() {
	motorSet(CLAW_LEFT, 0);
	motorSet(CLAW_RIGHT, 0);
}


void motorsDrive(int power) {
	motorSet(DRIVE_LEFT, power);
	motorSet(DRIVE_RIGHT, -power);
}


void motorsArm(int power) {
	motorSet(ARM_RIGHT_OUT, -power);
	motorSet(ARM_RIGHT_IN, -power);
	motorSet(ARM_LEFT_OUT, power);
	motorSet(ARM_LEFT_IN, power);
}


void motorsClaw(int power) {
	motorSet(CLAW_LEFT, -power);
	motorSet(CLAW_RIGHT, power);
}


// Main drive function to go forward/backward
void drive(int distance, int way) {
	encoderReset(encLeft);
	encoderReset(encRight);
	//while ( (abs(encoderGet(encRight)) + abs(encoderGet(encLeft)) / 2 ) < distance) {
	while ( (abs(encoderGet(encLeft) < distance)
		  && (abs(encoderGet(encRight))) < distance)) {
		if (way == 1) { motorsDrive(127); }
		if (way == 2) { motorsDrive(-127); }
		delay(25);
	}
	clearDrive();
}


void driveClosedClaw(int distance, int way) {
	encoderReset(encLeft);
	encoderReset(encRight);
	while ( (abs(encoderGet(encLeft) < distance)
		  && (abs(encoderGet(encRight))) < distance)) {
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


void rotate(int distance, int way){
	encoderReset(encLeft);
	encoderReset(encRight);
		if (way == 1) {  //left
			while (abs(encoderGet(encLeft)) < distance){
				motorSet(DRIVE_LEFT, 127);
				motorSet(DRIVE_RIGHT, -127);
			}
		}
		if (way == 2) {  //right
			while (abs(encoderGet(encRight)) < distance){
				motorSet(DRIVE_LEFT, -127);
				motorSet(DRIVE_RIGHT, 127);
		}
		delay(25);
	}
	clearDrive();
}

void arm(int time, int way) {
	//encoderReset(encArm);
	//while ( (abs(encoderGet(encArm))) < distance ) {
	if(way == 1) {
		motorsArm(127);
		delay(time);
	}
	if (way == 2) {
		motorsArm(-127);
		delay(time);
	}
	delay(25);
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
