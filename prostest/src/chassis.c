#include <main.h>



void setDrive(int rightspeed, int leftspeed){
    motorSet(rmotor, rightspeed);
    motorSet(lmotor, leftspeed);
}