
//Driver COntrol code
task driverControl(){
	while (true){
	motor[rightDrive] = vexRT[Ch2];
	motor[leftDrive] = vexRT[Ch3];
	motor[but] = vexRT[Btn7U];
}
}
