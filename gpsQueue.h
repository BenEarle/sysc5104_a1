/*******************************************************************
*
*  DESCRIPTION: Atomic Model Pwm
*
*  AUTHOR:
*
*  EMAIL:
*
*  DATE:
*
*******************************************************************/

#ifndef __GPSQUEUE_H
#define __GPSQUEUE_H

#include "atomic.h"     // class Atomic
#include <queue>        // queue

#define MPS_FROM_KMPH 1/3.6

enum Direction {LEFT, RIGHT};
struct GpsInstruction {
	Direction direction;
	int distance
};

class GpsQueue : public Atomic
{
public:
	GpsQueue( const string &name = "GpsQueue" );					//Default constructor
	virtual string className() const ;

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &gpsInstructionIn;
	const Port &speedIn;
	Port &turnRequest;
	float speed;
	float distance;
	queue<GpsInstruction> instructionQueue;
};	// class GpsQueue

// ** inline ** // 
inline
string GpsQueue::className() const
{
	return "GpsQueue" ;
}

#endif   //__GPSQUEUE_H
