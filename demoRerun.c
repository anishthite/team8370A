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
	//set equal to inout edvice (button or joystick)
	rightDrive[i] = vexRT[Ch2];
	leftDrive[i] = vexRT[Ch3];
}

}
//initializes arrays and clears debug stream
void initialize(){
	clearDebugStream();
	/** Customize per robot **/
	initializeArray(rightDrive);
	initializeArray(leftDrive);
	initializeArray(motor3);
	initializeArray(motor4);
	initializeArray(motor5);
	initializeArray(motor6);
	initializeArray(motor7);
	initializeArray(motor8);
	initializeArray(motor9);
	initializeArray(motor10);
}
task main()
{


}
