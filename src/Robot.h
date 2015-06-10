#ifndef ROBOT_H
#define ROBOT_H

#define DEADZONE 0.3

class Robot: public IterativeRobot
{
public:
	// Drive train Jaguar definitions
	Jaguar front_left_drive;
	Jaguar back_left_drive;
	Jaguar front_right_drive;
	Jaguar back_right_drive;

	// Other Jaguar definitions
	Jaguar turret;
	Jaguar kickup_wheel;
	Jaguar fire_wheel;
	Jaguar conveyor;

	//Spikes
	Relay intake;
	Relay kickup;

	// Drive train definitions
	RobotDrive myRobot;

	// Joystick definitions
	Joystick joystick_0;
	Joystick joystick_1;
	//Joystick control_stick_a;
	//Joystick control_stick_b;

	Timer t;

	bool timer_on;

	Robot();

private:

	enum sticks {
		js_0 = 0,
		js_1 = 1
	};

	enum p_w_m {
		fld=0, //Front left drive
		bld=1, //Back left drive
		frd=2, //Front right drive
		brd=3, //Back right drive

		fw=4, //Fire wheel
		trt=6, //Turret

		cnv=7 //Conveyor
	};

	enum relay {
		kw = 0, //Kickup wheel
		i = 1 //Intake
	};

	//buttons start at 1, NOT 0
	enum button {
		conveyorButton=1, //A
		fire=6 //Right bumper
	};

	LiveWindow *lw;

	double nullify (double n);

	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();
};

#endif
