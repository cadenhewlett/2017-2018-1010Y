/*
 * autoFunctions.h
 *
 *  Created on: Feb 8, 2017
 *      Author: James
 */


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


#ifndef INCLUDE_AUTOFUNCTIONS_H_
#define INCLUDE_AUTOFUNCTIONS_H_


#include "math.h"
#include "main.h"


void clearDrive() {  //function to be used to stop all driving motors
	motorSet(DRIVE_LEFT, 0);  //stops the left drive motors
	motorSet(DRIVE_RIGHT, 0);  //stops the right drive motors
}

void clearIntake() {  //function to be used to stop all Intake motors
	motorSet(INTAKE_LEFT, 0);  //stops the left intake motor
	motorSet(INTAKE_RIGHT, 0);  //stops the right intake motor
}

void clearClaw() {  //function to be used to stop all claw motors
	motorSet(CLAW, 0);  //stops the left claw motor
}

void clearArm() {  //function to be used to stop all arm motors
	motorSet(ARM_RIGHT_TOP, 0);  //stops the out most right arm motor
	motorSet(ARM_RIGHT_BOT, 0);  //stops the inner most right arm motor
	motorSet(ARM_LEFT_TOP, 0);  //stops the out most left arm motor
	motorSet(ARM_LEFT_BOT, 0);  //stops the inner most left arm motor
}

void clearAll() {  //function to stop all motors
	motorSet(DRIVE_LEFT, 0);  //stops the left drive motors
	motorSet(DRIVE_RIGHT, 0);  //stops the right drive motors
	motorSet(ARM_RIGHT_TOP, 0);  //stops the out most right arm motor
	motorSet(ARM_RIGHT_BOT, 0);  //stops the inner most right arm motor
	motorSet(ARM_LEFT_TOP, 0);  //stops the out most left arm motor
	motorSet(ARM_LEFT_BOT, 0);  //stops the inner most left arm motor
	motorSet(CLAW, 0);  //stops the left claw motor
}


void motorsDrive(int power) {  //a function  that takes a variable as an input to drive the base
	motorSet(DRIVE_LEFT, power);  //takes the previous variable to run the motor at the specified speed
	motorSet(DRIVE_RIGHT, -power);  //takes the previous variable to run the motor at the specified speed
}

void motorsIntake(int power) {  //a function  that takes a variable as an input to drive the intake
	motorSet(INTAKE_LEFT, -power);  //takes the previous variable to run the motor at the specified speed
	motorSet(INTAKE_RIGHT, power);  //takes the previous variable to run the motor at the specified speed
}

void motorsClaw(int power) {  //a function  that takes a variable as an input to drive the claw
	motorSet(CLAW, -power);  //takes the previous variable to run the motor at the specified speed
}

void motorsArm(int power) {  //a function  that takes a variable as an input to drive the arm
	motorSet(ARM_RIGHT_TOP, -power);  //takes the previous variable to run the motor at the specified speed
	motorSet(ARM_RIGHT_BOT, -power);  //takes the previous variable to run the motor at the specified speed
	motorSet(ARM_LEFT_TOP, power);  //takes the previous variable to run the motor at the specified speed
	motorSet(ARM_LEFT_BOT, power);  //takes the previous variable to run the motor at the specified speed
}


void drive(int distance, int way) {  //drive function to go forward/backward  ...takes the distance it has to travel and the direction as integers when the code is run
	encoderReset(encLeft);  //resets encoder to 0
	encoderReset(encRight);  //resets encoder to 0
	while ( (abs(encoderGet(encLeft) < distance)  //while the encoder is below the distance integer-
		  && (abs(encoderGet(encRight))) < distance)) {  //and while the other encoder is below the distance integer-
		if (way == 1) { motorsDrive(127); }  //drive the motors (forward) because of the way as far as the previous code allows
		if (way == 0) { motorsDrive(-127); }  //drive the motors (forward) because of the way as far as the previous code allows
		delay(25);  //a delay for 25 milliseconds
	}
	clearDrive();  //clears all movement from the motors
}

void driveTime(int time, int way) {  //drive function to go forward/backward  ...takes the distance it has to travel and the direction as integers when the code is run
		if (way == 1) { motorsDrive(127);
		delay(time); }  //drive the motors (forward) because of the way as far as the previous code allows
		if (way == 0) { motorsDrive(-127);
		delay(time); }  //drive the motors (forward) because of the way as far as the previous code allows
		delay(25);  //a delay for 25 milliseconds
	clearDrive();  //clears all movement from the motors
}

void rotate(int distance, int way){  //drive function to turn the robot  ...make distance degrees?
	encoderReset(encLeft);  //resets encoder to 0
	encoderReset(encRight);  //resets encoder to 0
		if (way == 1) {  //drives the motors depending on way- !!!left!!!
			while (abs(encoderGet(encLeft)) < distance){  //as long as the encoders have read less than the given distance
				motorSet(DRIVE_LEFT, 127);  //drives the motors according to the directions
				motorSet(DRIVE_RIGHT, -127);  //drives the motors according to the directions
			}
		}
		if (way == 0) {  //drives the motors depending on way- !!!right!!!
			while (abs(encoderGet(encRight)) < distance){  //as long as the encoders have read less than the given distance
				motorSet(DRIVE_LEFT, -127);  //drives the motors according to the directions
				motorSet(DRIVE_RIGHT, 127);  //drives the motors according to the directions
		}
		delay(25);  //a delay for 25 milliseconds
	}
	clearDrive();  //clears all movement from the motors
}

void driveClosedClaw(int distance, int way) {  //Incorporate drive function instead of re-written
	encoderReset(encLeft);  //resets encoder to 0
	encoderReset(encRight);  //resets encoder to 0
	while ( (abs(encoderGet(encLeft) < distance)  //while the encoder is below the distance integer-
		  && (abs(encoderGet(encRight))) < distance)) {  //and while the other encoder is below the distance integer-
		if (way == 1) {  //drive the motors (__) as far as the previous code allows
			motorsClaw(100);  //drives claw motors at a certain speed
			motorsDrive(127);  //drives drive  motors at a certain speed
		}
		if (way == 0) {  //drive the motors (__) as far as the previous code allows
			motorsClaw(100);  //drives claw motors at a certain speed
			motorsDrive(-127);  //drives drive motors at a certain speed
		}
		delay(25);  //a delay for 25 milliseconds
	}
	clearClaw();  //clears all movement from the motors
	clearDrive();  //clears all movement from the motors
}


//Main function for intake movement
void intake(int time, int way) {  //Binary closing continued action degree to stay at instead of time
	if(way == 1) {  //drive the motors
		motorsIntake(127);  //drives intake  motors at a certain speed
		delay(time);  //has a specifically chosen delay speed
	}
	if (way == 0) {  //drive the motors
		motorsIntake(-127);  //drives intake  motors at a certain speed
		delay(time);  //has a specifically chosen delay speed
	}
	clearIntake();  //clears all movement from the motors
}


 //Main function for claw movement
 void claw(int time, int way) {  //Binary closing continued action degree to stay at instead of time
 	if(way == 1) {  //drive the motors (in)
 		motorsClaw(127);  //drives claw  motors at a certain speed
 		delay(time);  //has a specifically chosen delay speed
 	}
 	if (way == 0) {  //drive the motors (out)
 		motorsClaw(-127);  //drives claw  motors at a certain speed
 		delay(time);  //has a specifically chosen delay speed
 	}
 	clearClaw();  //clears all movement from the motors
 }


//Main function for arm movement
void arm(int time, int way) {  //Replace time with distance / degrees (precise degree to stay at) (add encoders)
	//encoderReset(encArm);
	//while ( (abs(encoderGet(encArm))) < distance ) {
	if(way == 1) {  //drive the motors (up)
		motorsArm(127);  //drives arm  motors at a certain speed
		delay(time);   //a delay for 25 milliseconds
	}
	if (way == 0) {  //drive the motors (down)
		motorsArm(-127);  //drives arm  motors at a certain speed
		delay(time);  //a delay for 25 milliseconds
	}
	delay(25);  //a delay for 25 milliseconds  ...is this needed
	clearArm();  //clears all movement from the motors
}


#endif /* INCLUDE_AUTOFUNCTIONS_H_ */
