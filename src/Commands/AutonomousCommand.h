// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#ifndef AUTONOMOUSCOMMAND_H
#define AUTONOMOUSCOMMAND_H

#include "Commands/CommandGroup.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class AutonomousCommand: public CommandGroup {
public:
	enum Command_t{
		RobotSet,
		ToteSet,
		ContainerSet,
		StackedToteSet, // Don't use manually
		StepAttack
	};
	AutonomousCommand(AutonomousCommand::Command_t commandInput=RobotSet);\
	AutonomousCommand(uint8_t, uint8_t);
private:
	Command_t command;

};


#endif
