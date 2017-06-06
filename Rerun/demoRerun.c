//ReRun program- Author: Anish Thite 2017
//records input data given by remote and prints it out
//initialize arrays, will record tenth of a second (not enough mem for hundreth)-
/**
skills in hundreths (6000)
skills in tenths 	(600)
auto in hundreths (1500)
auto in tenths		(150)
** /
/** Customize per robot **/
#include "DemoDriverControl.c";
//use short for joystick values, convert to bool from int for button values
short rDrive[1500];
short lDrive[1500];
bool button[1500];
//initializes short arrays to 0
void initializeShortArray(short* motor){
	for(int i=0;i<150;i++)
	{
		motor[i]=0;
	}

}
//initialize bool arrays to zero
void initializeBoolArray(bool* motor){
	for(int i=0;i<150;i++)
	{
		motor[i] = 0;
	}

}
//converts int values to bool values
void convert(){}
//initializes arrays and clears debug stream
void initialize(){
	clearDebugStream();
	/** Customize per robot **/
	initializeShortArray(rDrive);
	initializeShortArray(lDrive);
	initializeBoolArray(button);

}
void recordAndRun(){
	for (int i = 0; i < 150; i++){
		/** Customize per robot **/
		//set equal to input device (button or joystick)
		rDrive[i] = vexRT[Ch2];
		lDrive[i] = vexRT[Ch3];
		wait10Msec(1);
		//shuts off all motors
	}

}

task reRun()
{
	/** paste code to run robot here**/

	//kill all motors
	stopAllMotors();
	initialize();
	startTask(driverControl);
	//record and run
	recordAndRun();
	stopAllMotors();
	//write to output stream
	output();


}
