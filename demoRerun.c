//ReRun program- Author: Anish Thite 2017
//records input data given by remote and prints it out- to be used in


//initialize data arrays
//record and run --> save joystick value to data array for
int joystickValue;


//initialize arrays, will record tenth of a second (not enough mem for hundreth)- compression?
/** Customize per robot **/
int rightDrive[150];
int leftDrive[150];
int motor3[150];
int motor4[150];
int motor5[150];
int motor6[150];
int motor7[150];
int motor8[150];
int motor9[150];
int motor10[150];
//initializes arrays to 0
void initializeArray(int* motor){
		for(int i=0;i<150;i++)
	{
		motor[i]=0;
	}

}
void recordAndRun(){
for (int i = 0; i < 150; i++){
	/** Customize per robot **/
	//set equal to input device (button or joystick)
	rightDrive[i] = vexRT[Ch2];
	leftDrive[i] = vexRT[Ch3];
	wait10Msec(1);
}

}
//initializes arrays and clears debug stream
void initialize(){
	clearDebugStream();
	/** Customize per robot **/
	initializeArray(rightDrive);
	initializeArray(leftDrive);

}
task main()
{
/** paste code to run robot here**/


//initialize
//record and run
//write to output stream

}
