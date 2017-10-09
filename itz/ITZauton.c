void left_turn(float ticks){
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
	}
}

void auton(int color, int side){
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;


}
