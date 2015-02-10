// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef GRABBERS_H
#define GRABBERS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

#define WIDETOTE_WIDTH 			45	//This is an arbitrary number until the code is tested and i receive the gear ratios.
#define SLIMTOTE_WIDTH 			20	//This is an arbitrary number until the code is tested and i receive the gear ratios.
#define TRASHCAN_WIDTH 			30	//This is an arbitrary number until the code is tested and i receive the gear ratios.
#define MANUEVER_WIDTH 			25	//This is an arbitrary number until the code is tested and i receive the gear ratios.
#define TOOPEN_WIDTH 			60	//This is an arbitrary number until the code is tested and i receive the gear ratios.

#define INFINITE_ERROR	       -1000.0 //This is an absurdly large number to set the error term for the encoder setpoint so no matter how jacked up the encoder gets it will still go to the "outside position" (encoder value 0)
#define NEGATIVE_VALUE			-1.0
/**
 *
 *
 * @author ExampleAuthor
 */
class Grabbers: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	DigitalInput* grabberoutsidelimit;
	DigitalInput* grabberinsidelimit;
	DigitalInput* grabbertotelimit;
	Encoder* grabberencoder;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Grabbers();
	void InitDefaultCommand();
	void ResetEncoder();
};

#endif
