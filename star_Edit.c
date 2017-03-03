#pragma config(Sensor, dgtl1,  autostar,       sensorDigitalIn)
#pragma config(Sensor, dgtl2,  autoback,       sensorDigitalIn)
#pragma config(Sensor, dgtl3,  autostarcube,   sensorDigitalIn)
#pragma config(Sensor, dgtl6,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl8,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl10, armEncoder,     sensorQuadEncoder)
#pragma config(Sensor, dgtl12, armTouch,       sensorTouch)
#pragma config(Sensor, I2C_1,  rightClaw,      sensorNone)
#pragma config(Sensor, I2C_2,  leftClaw,       sensorNone)
#pragma config(Motor,  port1,           backRight,     tmotorVex393_HBridge, openLoop, driveRight)
#pragma config(Motor,  port2,           frontRight,    tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port3,           frontLeft,     tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port4,           rightClaw,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           leftClaw,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           armRight,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           armRight2,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           armLeft,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           armLeft2,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          backLeft,      tmotorVex393_HBridge, openLoop, driveLeft)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// This code is for the VEX cortex platform
#pragma platform(VEX2)
// Select Download method as "competition"
#pragma competitionControl(Competition)
//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
task clawupopen(){
	clearTimer(T1);
	while(time1[T1] < 1000){// prev 300
		motor[rightClaw] = -127;
		motor[leftClaw] = -127;
	}
	motor[rightClaw] = 0;
	motor[leftClaw] =  0;

}
task clawclose(){
	clearTimer(T1);
	while(time1[T1] < 500){
		motor[rightClaw] = 127;
		motor[leftClaw] = 127;
	}
	motor[rightClaw] = 0;
	motor[leftClaw] =  0;


}
void stop_all(int time){	// stops all
	motor[armLeft] = 0;
	motor[armLeft2] = 0;
	motor[armRight] = 0;
	motor[armRight2] = 0;
	motor[backRight]= 0;
	motor[backLeft]= 0;
	motor[frontRight]= 0;
	motor[frontLeft]= 0;

	wait1Msec(time);
}
void cube_shoot(){
	bool clawFlag = true;
	while(SensorValue[armTouch] != 1){

		// arm portion
		motor[armLeft] = 127;
		motor[armLeft2] = 127;
		motor[armRight] = -127;
		motor[armRight2] = -127;
		//claw portion
		if (SensorValue[armEncoder] > 20){//30
			if (clawFlag == true){
				startTask (clawupopen);
				clawFlag = false;}
		}
		if (SensorValue[armEncoder] < 20){//30
			clawFlag = true;
		}
		// drive portion
		motor[backRight]=-127;
		motor[backLeft]=-127;
		motor[frontRight]=-127;
		motor[frontLeft]=-127;
	}

}
void star_shoot(){
	bool clawFlag = true;
	while(SensorValue[armTouch] != 1){

		// arm portion
		motor[armLeft] = 127;
		motor[armLeft2] = 127;
		motor[armRight] = -127;
		motor[armRight2] = -127;
		//claw portion
		if (SensorValue[armEncoder] > 30){//30
			if (clawFlag == true){
				startTask (clawupopen);
				clawFlag = false;}
		}
		if (SensorValue[armEncoder] < 30){//30
			clawFlag = true;
		}
		// drive portion
		motor[backRight]=-127;
		motor[backLeft]=-127;
		motor[frontRight]=-127;
		motor[frontLeft]=-127;
	}

}
void back_shoot(){	// drives back and shoots
	//drive backward for
	motor[backRight]=-127;
	motor[backLeft]=-127;
	motor[frontRight]=-127;
	motor[frontLeft]=-127;
	wait1Msec(800);
	// start arm
	while(SensorValue[armTouch] != 1){
		// arm portion
		motor[armLeft] = 127;
		motor[armLeft2] = 127;
		motor[armRight] = -127;
		motor[armRight2] = -127;
		// drive portion
		motor[backRight]=-127;
		motor[backLeft]=-127;
		motor[frontRight]=-127;
		motor[frontLeft]=-127;
	}
}
void left_turn(float ticks){ // moves left laterally (red)
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	while(SensorValue[rightEncoder] < ticks || SensorValue[leftEncoder] > -ticks){
		if(SensorValue[rightEncoder] < ticks){ //forward shaft rotation
			if (SensorValue[rightEncoder]/ticks <.8){
				motor[backRight]=127;
				motor[frontRight]=127;
			}
			else{
				motor[backRight]=90;
				motor[frontRight]=90;
			}
		}
		else
		{
			motor[backRight]=0;
			motor[frontRight]=0;
		}
		if(SensorValue[leftEncoder] > -ticks){ //reversed shaft rotation
			if (SensorValue[leftEncoder]/ticks >-.8){
				motor[backLeft]=-127;
				motor[frontLeft]=-127;
			}
			else{
				motor[backLeft]=-90;
				motor[frontLeft]=-90;
			}
		}
		else{
			motor[backLeft]=0;
			motor[frontLeft]=0;
		}
	}

}
void right_turn(float ticks){ // moves right laterally (blue)
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	while(SensorValue[leftEncoder] < ticks || SensorValue[rightEncoder] > -ticks){
		if(SensorValue[leftEncoder] < ticks || SensorValue[rightEncoder] > -ticks){ //forward shaft rotation
			if (SensorValue[leftEncoder]/ticks < .8){
				motor[backLeft]=127;
				motor[frontLeft]=127;
			}
			else{
				motor[backLeft]=90;
				motor[frontLeft]=90;
			}
		}
		else
		{
			motor[backLeft]=0;
			motor[frontLeft]=0;
		}
		if(SensorValue[rightEncoder] > -ticks || SensorValue[leftEncoder] < ticks){ //reversed shaft rotation
			if (SensorValue[rightEncoder]/ticks > -.8){
				motor[backRight]=-127;
				motor[frontRight]=-127;
			}
			else{
				motor[backRight]=-90;
				motor[frontRight]=-90;}
		}
		else{
			motor[backRight]=0;
			motor[frontRight]=0;
		}
	}
}
void arm_down(int deg){	// moves arm down
	while (SensorValue[armEncoder] > deg){
		motor[armLeft] = -127;
		motor[armLeft2] = -127; //L -70, R 50 cube1
		motor[armRight] = 127;
		motor[armRight2] = 127;
	}
}

void drive_forward(float inches){ // drives forward
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	float ticks = inches * 28.6478898;
	while (SensorValue[rightEncoder]<ticks){

		if (SensorValue[rightEncoder]==SensorValue[leftEncoder]){
			if (SensorValue[rightEncoder]/ticks <.8)
			{motor[backRight]=127;
				motor[backLeft]=127;
				motor[frontRight]=127;
				motor[frontLeft]=127;
			}
			else{
				{motor[backRight]=60;
					motor[backLeft]=60;
					motor[frontRight]=60;
					motor[frontLeft]=60;
				}
			}
			if (SensorValue[rightEncoder] <SensorValue[leftEncoder]){
				motor[backRight]=127;
				motor[backLeft]=110;
				motor[frontRight]=127;
				motor[frontLeft]=110;
			}
			if (SensorValue[rightEncoder] >SensorValue[leftEncoder]){
				motor[backRight]=110;
				motor[backLeft]=127;
				motor[frontRight]=110;
				motor[frontLeft]=127;
			}
		}
		//motor[backRight]=-63;
		//motor[backLeft]=-63;
		//motor[frontRight]=-63;
		//motor[frontLeft]=-63;
		//wait1Msec(12);
	}
}
void drive_backward(float inches){ // drives forward
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	float ticks = inches * -28.6478898;
	while (SensorValue[rightEncoder]>ticks)
	{
		if (SensorValue[rightEncoder]==SensorValue[leftEncoder]){
			if (SensorValue[rightEncoder]/ticks <.3)
			{motor[frontRight]=-60;
				motor[backLeft]=-60;
				motor[frontLeft]=-60;
				motor[backRight]=-60;
			}
			else
			{	motor[frontRight]=-60;
				motor[backLeft]=-60;
				motor[frontLeft]=-60;
				motor[backRight]=-60;}
		}
		//	if (SensorValue[rightEncoder] >SensorValue[leftEncoder]){
		//				motor[backRight]=-127;
		//				motor[backLeft]=-110;
		//				motor[frontRight]=-127;
		//				motor[frontLeft]=-110;
		//	}
		//	if (SensorValue[rightEncoder] <SensorValue[leftEncoder]){
		//				motor[backRight]=-110;
		//				motor[backLeft]=-127;
		//				motor[frontRight]=-110;
		//				motor[frontLeft]=-127;
		//}
	}
}
void arm_up(int deg){	// moves arm down
	while (SensorValue[armEncoder] < deg){
		motor[armLeft] = 127;
		motor[armLeft2] = 127; //L -70, R 50 cube1
		motor[armRight] = -127;
		motor[armRight2] = -127;
	}
}
void pro_skills(){
	SensorValue[armEncoder] = 0;

}
void drive_backward_time(int time){
	motor[frontRight]=-60;
	motor[backLeft]=-60;
	motor[frontLeft]=-60;
	motor[backRight]=-60;
	wait1Msec(time);
}
void open_claw(int time){
	clearTimer(T1);
	while(time1[T1] < time){
		motor[rightClaw] = -127;
		motor[leftClaw] = -127;
	}
	motor[rightClaw] = 0;
	motor[leftClaw] =  0;}
void close_claw(int time){
	clearTimer(T1);
	while(time1[T1] < time){
		motor[rightClaw] = 127;
		motor[leftClaw] = 127;
	}
	motor[rightClaw] = 0;
	motor[leftClaw] =  0;

}
void star(){
	SensorValue[armEncoder] = 0;
	right_turn(250);
	stop_all(50);
	drive_forward(80);
	stop_all(50);
	drive_backward(12);
	stop_all(50);
	left_turn(240);
	stop_all(50);
	drive_forward(12);
	stop_all(50);
	right_turn(250);
	stop_all(50);
	drive_forward(12);
	stop_all(50);
	right_turn(240);
	stop_all(50);
	arm_up(80);
	stop_all(50);
	arm_down(5);
	stop_all(50);
	drive_forward(12);
	stop_all(50);
	cube_shoot();
}
void clawstar(){ // knocks stars off the fence, turns around to get the preload and throw it
	nMotorEncoder[rightEncoder] = 0;
	nMotorEncoder[leftEncoder] = 0;
	SensorValue[armEncoder] = 0;

	//close claw to widest position
	//close_claw(200);
	///stop_all(20);
	//raise arm
	//arm_up(90);
	//stop_all(20);
	//drive forward
	drive_forward(30);
	stop_all(20);
	////back up
	//stop_all(20);
	right_turn(450);
	stop_all(20);
	arm_up(90);
	close_claw(90);
	stop_all(50);
	arm_down(00);
	stop_all(50);
	drive_forward(25);
	stop_all(20);
	close_claw(1000);
	stop_all(20);
	drive_backward(5);
	stop_all(20);
	star_shoot();

	close_claw(300);//open???
	stop_all(20);
	arm_down(0);
	stop_all(20);
	drive_forward(35);
	stop_all(20);
	open_claw(1000);//prev close
	stop_all(20);
	drive_backward(5);
	stop_all(20);
	star_shoot();
}
void clawstarcube(){
	nMotorEncoder[rightEncoder] = 0;
	nMotorEncoder[leftEncoder] = 0;
	SensorValue[armEncoder] = 0;

	//close claw to widest position
	close_claw(300);
	stop_all(20);
	//raise arm
	arm_up(90);
	stop_all(20);
	//drive forward
	drive_forward(12);
	stop_all(20);
	//back up
	drive_backward(6);
	stop_all(20);
	// right turn
	right_turn(220);
	stop_all(20);
	arm_down(0);
	stop_all(20);
	drive_forward(11);
	stop_all(50);
	close_claw(1300);
	//arm_up(5);
	stop_all(50);
	startTask(clawclose);
	right_turn(320);
	//arm_down(1);
	drive_forward(4);//4
	close_claw(1200);//500
	stop_all(50);
	drive_backward(15);
	stop_all(50);
	cube_shoot();
	// drive foreward
	// pick up second star here


}
void clawcube(){
	nMotorEncoder[rightEncoder] = 0;
	nMotorEncoder[leftEncoder] = 0;
	SensorValue[armEncoder] = 0;
	arm_up(90);
	close_claw(90);
	stop_all(50);
	arm_down(00);
	stop_all(50);
	drive_forward(35);
	stop_all(50);
	close_claw(1300);
	//arm_up(5);
	stop_all(50);
	startTask(clawclose);
	right_turn(420);
	//arm_down(1);
	drive_forward(4);//4
	close_claw(1200);//500
	stop_all(50);
	drive_backward(15);
	stop_all(50);
	cube_shoot();
	//second star pickup time
	//drive_forward(10);
	//stop_all(50);
	//arm_down(0);
	//stop_all(50);
	//drive_forward(25);
	//stop_all(50);
	//close_claw(1300);
	//stop_all(50);
	//drive_backward(15);
	//stop_all(50);
	//cube_shoot();
}

task autonomous()
{
	if (SensorValue[autostarcube] == 0){
		clawstarcube();
	}
	else if (SensorValue[autostar] == 0){
		clawstar();
	}
	else{
		clawcube();
	}


	// positioning, side of arm aligned with first tab crossing, midsection of wheel aligned with second crossing of tabs
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

// Lower to defend position


task usercontrol()
{
	// User control code inside the loop
	//nMotorEncoder[rightClaw] = 0;
	//nMotorEncoder[leftClaw] = 0;
	//SensorValue[armEncoder] = 0;
	bool clawFlag = true;
	while (true)
	{

		float SpeedDivisor = 1;
		float backLimit = SensorValue[armTouch];
		float LeftDrive = vexRT[Ch3]/SpeedDivisor, RightDrive = vexRT[Ch2]/SpeedDivisor;
		//drive
		motor[frontLeft] = LeftDrive;
		motor[backLeft] = LeftDrive;
		motor[frontRight] = RightDrive;
		motor[backRight] = RightDrive;

		// claw code
		if(vexRT[Btn5D] == 1){	// claw opens

			motor[rightClaw] = -127;
			motor[leftClaw] = -127;
		}
		else if(vexRT[Btn5U] == 1){ //claw closes
			motor[rightClaw] = 127;
			motor[leftClaw] = 127;
		}
		else{
			if ((SensorValue[armEncoder] > 30) && (clawFlag == true)) { //20
				//startTask (clawupopen);
				clawFlag = false;
			}
			else{
				motor[rightClaw] = 0;
				motor[leftClaw] = 0;
			}
		}
		if (vexRT[Btn7D] == 1)
		{if (SensorValue[autostarcube] == 0){
		clawstarcube();
	}
	else if (SensorValue[autostar] == 0){
		clawstar();
	}
	else{
		clawcube();
	}
}

		// arm code

		if((SensorValue[armEncoder] <30)){ //  originally 20 stays at 0 if lift is not going up
			clawFlag = true;
		}
		if(vexRT[Btn6U] == 1 && backLimit == 0 )	// if button 6U is pressed, arm goes up
		{

			motor[armLeft] = 127;
			motor[armLeft2] = 127;
			motor[armRight] = -127;
			motor[armRight2] = -127;

		}
		else if(vexRT[Btn6D] == 1) // if button 6D is pressed, arm goes down
		{
			motor[armLeft] = -127;
			motor[armLeft2] = -127;
			motor[armRight] = 127;
			motor[armRight2] = 127;
		}
		else // stays at 0
		{
			motor[armLeft] = 0;
			motor[armLeft2] = 0;
			motor[armRight] = 0;
			motor[armRight2] = 0;
		}
		if(vexRT[Btn8U] == 1){

			nMotorEncoder[rightClaw] = 0;
			nMotorEncoder[leftClaw] = 0;
			SensorValue[armEncoder] = 0;
			//SensorValue[ArmEncoder] = 0;
		}
		// DO NOT REMOVE BELOW WITHOUT ASKING ANISH.
		UserControlCodePlaceholderForTesting();
	}
}
