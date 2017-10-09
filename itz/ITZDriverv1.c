//tank drive code
void drive(){
  	int leftdrive = vexRT[Ch3Xmtr2];
   	int rightdrive = vexRT[Ch4Xmtr2];
   	motor(backLeft) = leftdrive;
   	motor(frontLeft) = leftdrive;
   	motor(backRight) = rightdrive;
   	motor(frontRight) = rightdrive;
}
//mogo lift code
void mogo(int mogovalue){
	int mogo;
	if (vexRT[Btn5UXmtr2] == 1){ //5U josh's remote
		if (mogovalue > 0){
			mogo = -127;										//fix value
		}
	}
	else if (vexRT[Btn5DXmtr2] == 1){//5D josh's remote
		if (mogovalue < 120){							//fix value
			mogo = 127;
		}
	}
	else{
		mogo = 0;
	}
	motor(mogoRight) = mogo;
	motor(mogoLeft) = -mogo;
}
//claw open/close code --> both remotes
void intake(){
	if ((vexRT[Btn6UXmtr2] == 1) || (vexRT[Btn6U] == 1)){
		motor(claw) = 127;
	}
	if ((vexRT[Btn6DXmtr2] == 1) || (vexRT[Btn6D] == 1)){
		motor(claw) = -127;
	}
	else{
		motor(claw) = 0;
	}
}
