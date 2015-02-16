// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "AutonomousMove.h"
#include "ITG3200.h"
#define DIST_VELOCITY 0.5


AutonomousMove::AutonomousMove(float velocity, float time) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	m_velocity = velocity;
	m_time = time;
	m_distance = 0;
	SetTimeout(time);
	isDistanceMove = false;
}
AutonomousMove::AutonomousMove(float distance) {

	Requires(Robot::driveTrain);
	m_distance = distance;
	m_time = 0;
	m_velocity = 0;
	isDistanceMove = true;

}

// Called just before this Command runs the first time
void AutonomousMove::Initialize() {
	if (isDistanceMove)
		m_distance += RobotMap::driveTrainDriveencoder->Get();
}

// Called repeatedly when this Command is scheduled to run
void AutonomousMove::Execute() {
	int Gyro = RobotMap::driveTrainGyro->GetNormalizedAngleZ();


	if (isDistanceMove && m_distance > 0){
		Robot::driveTrain->robotDrive41->MecanumDrive_Cartesian(0.0, DIST_VELOCITY, 0.0, Gyro);
	}
	else if (isDistanceMove && m_distance < 0){
		Robot::driveTrain->robotDrive41->MecanumDrive_Cartesian(0.0, -DIST_VELOCITY, 0.0, Gyro);
	}
	else if (!isDistanceMove){
		Robot::driveTrain->robotDrive41->MecanumDrive_Cartesian(0.0, m_velocity, 0.0, Gyro);
	}


}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousMove::IsFinished() {
	if (isDistanceMove)
		return RobotMap::driveTrainDriveencoder->Get() > m_distance;
	else
		return IsTimedOut();
}

// Called once after isFinished returns true
void AutonomousMove::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousMove::Interrupted() {

}
