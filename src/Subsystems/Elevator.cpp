
// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Elevator.h"
#include "../RobotMap.h"
#include "../Commands/MoveElevator.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

Elevator::Elevator() : Subsystem("Elevator") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	elevatorTopLimit = RobotMap::elevatorElevatorTopLimit;
	elevatorBottomLimit = RobotMap::elevatorElevatorBottomLimit;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	elevatorTalon = RobotMap::elevatorElevatorTalon;

	elevatorTalon->SetControlMode(CANSpeedController::kPosition);
	elevatorTalon->SetPID(0.3, 0.0, 0.0);
	elevatorTalon->EnableControl();
}
    
void Elevator::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
void Elevator::MotorRestrictions() {
	if (RobotMap::elevatorElevatorTalon->IsFwdLimitSwitchClosed() == true && Robot::oi->getOpStickY() > 0)
	{
		RobotMap::elevatorElevatorTalon->Set(0.0);
	}

	if(RobotMap::elevatorElevatorTalon->IsRevLimitSwitchClosed() == true && Robot::oi->getOpStickY() < 0)
	{
		RobotMap::elevatorElevatorTalon->Set(0.0);
	}
}

