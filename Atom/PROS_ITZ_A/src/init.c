/**
 * File for initialization code.*
 *
 * This file should contain the user initialize() function and any functions related to it.
 *
 * Copyright(c) 2011 - 2014, Purdue University ACM SIG BOTS.All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met :
 *
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and / or other materials provided with the distribution.
 * Neither the name of Purdue University ACM SIG BOTS nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.IN NO EVENT SHALL PURDUE UNIVERSITY ACM SIG BOTS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Purdue Robotics OS contains FreeRTOS(http://www.freertos.org) whose source code may be obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */


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


 /**
  * Runs pre-initialization code.
  *
  * This function will be started in kernel mode one time while the VEX Cortex is starting up. As the scheduler is still paused, most API functions will fail.
  *
  * The purpose of this function is solely to set the default pin modes (pinMode()) and port states (digitalWrite()) of limit switches, push buttons, and solenoids. It can also safely configure a UART port (usartOpen()) but cannot set up an LCD (lcdInit()).
  */
void initializeIO() {
}

/**
 * Runs user initialization code.
 *
 * This function will be started in its own task with the default priority and stack size once when the robot is starting up. It is possible that the VEXnet communication link may not be fully established at this time, so reading from the VEX Joystick may fail.
 *
 * This function should initialize most sensors (gyro, encoders, ultrasonics), LCDs, global variables, and IMEs.
 *
 * This function must exit relatively promptly, or the operatorControl() and autonomous() tasks will not start. An autonomous mode selection menu like the pre_auton() in other environments can be implemented in this task if desired.
 */
void initialize() {

	encRight = encoderInit(1, 2, true);  //names the encoder in ports 1 and 2 encLeft  ...encoder currently not working
	encLeft = encoderInit(5, 6, true);  //names the encoder in ports 5 and 6 encRight  ...encoder currently not working

	lcdInit(uart1);  //Improve this code   |
	lcdClear(uart1);  //                   V
	//lcdBackLight(1);

	//int autoId[] = {1, 2, 3};
	//int counter = 0;
	//lcdSetText(uart1, 2, "<      OK      >");

	//while(1){
		//if (lcdReadButtons(uart1) == 4) {
		//			counter+;
		//} else if (lcdReadButtons(uart1) == 1) {
				//	counter-;
				//}
		//if (autoId[counter] == 1) {
		//	lcdPrint(uart1, 1, "LOAD: AUTO 1");
		//} else if (autoId[counter] == 2) {
		//	lcdPrint(uart1, 1, "LOAD: AUTO 2");
		//} else if (autoId[counter] == 3) {
		//	lcdPrint(uart1, 1, "LOAD: SKILL AUTO");
		//}

		//if (lcdReadButtons(uart1) == 2) {
		//	if (autoId[counter] == 1) {
		//		program = 1;
		//		break;
		//	} else if (autoId[counter] == 2) {
		//		program = 2;
			//	break;
		//	} else if (autoId[counter] == 3) {
		//		program = 3;
		//		break;
		//	} else {
		//		continue;
		//	}


		//}
	//	delay(250);
	//}


}
