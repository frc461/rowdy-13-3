#include <iostream>
#include "WPILib.h"
#include "Robot.h"

// Constructor
Robot::Robot():
	lw(NULL),
	front_left_drive(fld),
	back_left_drive(bld),
	front_right_drive(frd),
	back_right_drive(brd),

	myRobot(front_left_drive, back_left_drive, front_right_drive, back_right_drive),

	turret(trt),
	kickup_wheel(kw),
	fire_wheel(fw),
	conveyor(cnv),

	intake(i, Relay::kForwardOnly),
	kickup(kw, Relay::kForwardOnly),

	t(),

	joystick_0(js_0),
	joystick_1(js_1)
//	control_stick_a(cs_a),
//	control_stick_b(cs_b)
{
	timer_on = false;
}

double Robot::nullify(double n) {
	if(n < DEADZONE && n > -DEADZONE) {
		return 0.0;
	}

	return n;
}

// Initialize the robot
void Robot::RobotInit()
{
	lw = LiveWindow::GetInstance();
}

// Autonomous methods
void Robot::AutonomousInit()
{

}

void Robot::AutonomousPeriodic()
{

}

// Teleoperate methods
void Robot::TeleopInit()
{

}

void Robot::TeleopPeriodic()
{
	double l_x = joystick_0.GetRawAxis(0);
	double l_y = joystick_0.GetRawAxis(1);
	double r_x = joystick_0.GetRawAxis(4);
	double r_y = joystick_0.GetRawAxis(5);

	r_y = nullify(r_y) * -.5;
	l_y = nullify(l_y) * -.5;

	switch(joystick_0.GetPOV()) {
	case 90:
		turret.Set(0.5);
		break;
	case 270:
		turret.Set(-0.5);
		break;
	default:
		turret.Set(0.0);
	}

	//Fire is negative direction
	if (joystick_0.GetRawButton(fire)) {
		fire_wheel.Set(-0.75);
		kickup.Set(Relay::kOn);
	}
	else {
		fire_wheel.Set(0.0);
		kickup.Set(Relay::kOff);
	}

	if (joystick_0.GetRawButton(conveyorButton)) {
		conveyor.Set(0.5);
		intake.Set(Relay::kOn);
	}
	else {
		conveyor.Set(0.0);
		intake.Set(Relay::kOff);
	}

	myRobot.TankDrive(l_y, r_y, false);
}

// Test methods
void Robot::TestPeriodic()
{
	lw->Run();
}

START_ROBOT_CLASS(Robot);
