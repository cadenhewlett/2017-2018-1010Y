/*
 * auto.c
 *
 *  Created on: Feb 10, 2017
 *      Author: James
 */


/**
* File for autonomous code.
*
* This file should contain the user autonomous() function and any functions related to it.
*
* Copyright (c) 2011-2014, Purdue University ACM SIG BOTS. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
*
* Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* Neither the name of Purdue University ACM SIG BOTS nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL PURDUE UNIVERSITY ACM SIG BOTS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
* Purdue Robotics OS contains FreeRTOS (http://www.freertos.org) whose source code may be obtained from http://sourceforge.net/projects/freertos/files/ or on request.
********************************************************************************/


#include "main.h"
#include "autoFunctions.h"


#define POS 1 //positive
#define NEG 2 //negative

void pgSkills() {
	drive(200, NEG);
	delay(50);
	claw(750, POS);
	drive(200, POS);
	delay(25);
	claw(750, POS);
	driveClosedClaw(1600, NEG);
	delay(25);
	arm(1600, POS);
	claw(250, NEG);

	arm(900, NEG);
	drive(100, NEG);
	drive(100, POS);
	drive(100, NEG);
	drive(1800, POS);
	claw(750, POS);
	driveClosedClaw(1600, NEG);
	delay(25);
	arm(1600, POS);
	claw(250, NEG);

	arm(900, NEG);
	drive(100, NEG);
	drive(100, POS);
	drive(100, NEG);

	drive(1800, POS);
	claw(750, POS);
	driveClosedClaw(1600, NEG);
	delay(25);
	arm(1600, POS);
	claw(250, NEG);

	arm(900, NEG);
	drive(100, NEG);
	drive(1800, POS);
	claw(750, POS);
	driveClosedClaw(1600, NEG);
	delay(25);
	arm(1600, POS);
	claw(250, NEG);

}

void compAuto() {
	//drive(200, NEG);
	//delay(50);
	//claw(1500, POS);
	drive(1600, NEG);
	delay(25);
	claw(450, NEG);
	arm(1600, POS);
	delay(50);
	arm(100, POS);
	drive(150, NEG);
	claw(300, POS);

	/*drive(200, NEG);
	delay(50);
	claw(1500, POS);
	driveClosedClaw(1600, NEG);
	delay(25);
	arm(1600, POS);
	claw(175, POS);
	claw(275, NEG);
	arm(100, NEG);
	claw(375, POS);
	drive(150, NEG);*/
}

void autonomous() {
	compAuto();
	//pgSkills();
}
