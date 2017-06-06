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
	for(int i=0;i<1500;i++)
	{
		motor[i]=0;
	}

}
//initialize bool arrays to zero
void initializeBoolArray(bool* motor){
	for(int i=0;i<1500;i++)
	{
		motor[i] = false;
	}

}
//converts int values to bool values
bool convert(int i){
	bool temp = false;
if (i == 1){
 	temp = true;
 }
 	return temp;

}
//initializes arrays and clears debug stream
void initialize(){
	clearDebugStream();
	/** Customize per robot **/
	initializeShortArray(rDrive);
	initializeShortArray(lDrive);
	initializeBoolArray(button);

}
void recordAndRun(){
	for (int i = 0; i < 1500; i++){
		/** Customize per robot **/
		//set equal to input device (button or joystick)
		rDrive[i] = vexRT[Ch2];
		lDrive[i] = vexRT[Ch3];
		button[i] = convert(vexRT[Btn7U]);
		wait10Msec(1);
		//shuts off all motors
	}

}
void newLine ()
{
	writeDebugStreamLine("");
}
//outputs the short arrays for use in auton
void outputshort(short* name){
	writeDebugStreamLine("	Array = ");
	for(int i=0;i<1500;i++)
	{

			writeDebugStream("%d", name[i]);
		newLine();
	}
}
//outputs the bool arrays for use in auton
void outputbool(bool* name){
	writeDebugStreamLine("	Array = ");
	for(int i=0;i<1500;i++)
	{
			writeDebugStream("%d", name[i]);
	}
		newLine();
}
task reRun()
{
	/** paste code to run robot here**/

	//kill all motors
	stopAllMotors();
	initialize();
	startTask (driverControl);
	//record and run
	recordAndRun();
	stopAllMotors();
	//write to output stream
	outputshort(rDrive);
	outputshort(lDrive);
	outputbool(button);


}
