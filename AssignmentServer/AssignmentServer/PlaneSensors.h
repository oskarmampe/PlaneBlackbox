#pragma once

#include "Subject.h"

class PlaneSensors : public Subject{
public:
	//Override
	void UpdatePlane(PlaneInformation*);
};