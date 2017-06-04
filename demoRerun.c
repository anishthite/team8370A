//ReRun program- Author: Anish Thite 2017
//records input data given by remote and prints it out- to be used in



//initialize arrays, will record tenth of a second (not enough mem for hundreth)- compression?
/** Customize per robot **/
int rightDrive[150];
int leftDrive[150];

//initializes arrays to 0
void initializeArray(int* motor){
		for(int i=0;i<150;i++)
	{
		motor[i]=0;
	}

}
//initializes arrays and clears debug stream
void initialize(){
	clearDebugStream();
	/** Customize per robot **/
	initializeArray(rightDrive);
	initializeArray(leftDrive);

}
void recordAndRun(){
for (int i = 0; i < 150; i++){
	/** Customize per robot **/
	//set equal to input device (button or joystick)
	rightDrive[i] = vexRT[Ch2];
	leftDrive[i] = vexRT[Ch3];
	wait10Msec(1);
	//shuts off all motors
}

}

task main()
{
/** paste code to run robot here**/


//initialize
//record and run
//write to output stream

}
