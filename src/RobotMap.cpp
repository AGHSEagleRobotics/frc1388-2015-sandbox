// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
SpeedController* RobotMap::driveTrainLeftfronttalon = NULL;
SpeedController* RobotMap::driveTrainRightfronttalon = NULL;
SpeedController* RobotMap::driveTrainLeftbacktalon = NULL;
SpeedController* RobotMap::driveTrainRightbacktalon = NULL;
RobotDrive* RobotMap::driveTrainRobotDrive41 = NULL;
Encoder* RobotMap::driveTrainDriveencoder = NULL;
Gyro* RobotMap::driveTrainDefaultGyro = NULL;
DigitalInput* RobotMap::grabbersGrabberoutsidelimit = NULL;
DigitalInput* RobotMap::grabbersGrabberinsidelimit = NULL;
DigitalInput* RobotMap::grabbersGrabbertotelimit = NULL;
Encoder* RobotMap::grabbersGrabberencoder = NULL;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

CANTalon * RobotMap::grabbersGrabberCANTalon = NULL;
CANTalon * RobotMap::elevatorElevatorTalon = NULL;
ITG3200  * RobotMap::driveTrainGyro = NULL;

void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();

	driveTrainLeftfronttalon = new Talon(3);
	lw->AddActuator("DriveTrain", "Leftfronttalon", (Talon*) driveTrainLeftfronttalon);
	
	driveTrainRightfronttalon = new Talon(2);
	lw->AddActuator("DriveTrain", "Rightfronttalon", (Talon*) driveTrainRightfronttalon);
	
	driveTrainLeftbacktalon = new Talon(1);
	lw->AddActuator("DriveTrain", "Leftbacktalon ", (Talon*) driveTrainLeftbacktalon);
	
	driveTrainRightbacktalon = new Talon(0);
	lw->AddActuator("DriveTrain", "Rightbacktalon ", (Talon*) driveTrainRightbacktalon);
	
	driveTrainRobotDrive41 = new RobotDrive(driveTrainLeftfronttalon, driveTrainLeftbacktalon,
              driveTrainRightfronttalon, driveTrainRightbacktalon);
	
	driveTrainRobotDrive41->SetSafetyEnabled(true);
        driveTrainRobotDrive41->SetExpiration(0.1);
        driveTrainRobotDrive41->SetSensitivity(0.5);
        driveTrainRobotDrive41->SetMaxOutput(1.0);
        driveTrainRobotDrive41->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
        driveTrainRobotDrive41->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	driveTrainDriveencoder = new Encoder(0, 1, false, Encoder::k1X);
	lw->AddSensor("DriveTrain", "Driveencoder ", driveTrainDriveencoder);
	driveTrainDriveencoder->SetDistancePerPulse(0.0274176);
        driveTrainDriveencoder->SetPIDSourceParameter(Encoder::kDistance);
	driveTrainDefaultGyro = new Gyro(0);
	lw->AddSensor("DriveTrain", "DefaultGyro", driveTrainDefaultGyro);
	driveTrainDefaultGyro->SetSensitivity(0.007);
	grabbersGrabberoutsidelimit = new DigitalInput(6);
	lw->AddSensor("Grabbers", "Grabberoutsidelimit", grabbersGrabberoutsidelimit);
	
	grabbersGrabberinsidelimit = new DigitalInput(4);
	lw->AddSensor("Grabbers", "Grabberinsidelimit", grabbersGrabberinsidelimit);
	
	grabbersGrabbertotelimit = new DigitalInput(9);
	lw->AddSensor("Grabbers", "Grabbertotelimit", grabbersGrabbertotelimit);
	
	grabbersGrabberencoder = new Encoder(10, 11, false, Encoder::k4X);
	lw->AddSensor("Grabbers", "Grabberencoder", grabbersGrabberencoder);
	grabbersGrabberencoder->SetDistancePerPulse(1.0);
        grabbersGrabberencoder->SetPIDSourceParameter(Encoder::kRate);


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    grabbersGrabberCANTalon = new CANTalon (11);
    grabbersGrabberCANTalon->SetControlMode(CANSpeedController::kPosition);
   // grabbersGrabberCANTalon->ConfigMaxOutputVoltage(6);
    grabbersGrabberCANTalon->SetPID(1,0,0);
    grabbersGrabberCANTalon->SetIzone(2000);
    grabbersGrabberCANTalon->EnableControl();
    grabbersGrabberCANTalon->ConfigNeutralMode(CANSpeedController::kNeutralMode_Brake);
    elevatorElevatorTalon = new CANTalon(12);
    driveTrainGyro = new ITG3200();
}
