#pragma config(Motor,  port2,           largeLeft,     tmotorVex393_MC29, openLoop, reversed, driveLeft)
#pragma config(Motor,  port3,           largeRight,    tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port4,           Forklift,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           launchServo,   tmotorServoStandard, openLoop)


task main()
{

	while (true) {


		if((vexRT[Btn8L] == 1)) {
			motor[launchServo] = 127;
			//motor[launchServo] = 127;
			} else {
			motor[launchServo] = -127;
			//motor[launchServo] = -127;
		}

		if (abs(vexRT[Ch2]) > 0.5) {
			motor[Forklift] = (vexRT[Ch2]);
		}


		// Handle Driving on Left Joystick
		if (abs(vexRT[Ch3]) > abs(vexRT[Ch4])) {
			//Forward Drive
			motor[largeLeft] = vexRT[Ch3];
			motor[largeRight] = vexRT[Ch3];
			} else {

			if ((vexRT[Ch4]) > 25) {
				// Wide Turn Right
				motor[largeLeft] = vexRT[Ch4];
				motor[largeRight] = vexRT[Ch4] * 0.2;
			}

			if ((vexRT[Ch4]) < -25) {
				// Wide Turn Left
				motor[largeRight] = vexRT[Ch4] * -1;
				motor[largeLeft] = vexRT[Ch4] * -0.2;
			}
		}

	}
}
