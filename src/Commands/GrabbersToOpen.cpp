// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "GrabbersToOpen.h"

GrabbersToOpen::GrabbersToOpen() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::grabbers);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void GrabbersToOpen::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void GrabbersToOpen::Execute() {
	if(Robot::grabbers->grabberinsidelimit->Get() == 1)
	//when the inside limit is pressed
	{
		Robot::grabbers->grabbermotor->Set(1.0);
		//then turn the motor on so the grabbers will move outward
	}
	
	if(Robot::grabbers->grabberoutsidelimit->Get() == 1)
	// if the outside limit is pressed
	{
		Robot::grabbers->grabbermotor->Set(0.0);
		//then turn off the motor
	}
}

// Make this return true when this Command no longer needs to run execute()
bool GrabbersToOpen::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void GrabbersToOpen::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GrabbersToOpen::Interrupted() {

}