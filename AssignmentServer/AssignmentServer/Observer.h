#pragma once
#include "PlaneInformation.h"

class Observer {
public:
	//Make the observers update
	virtual void update(PlaneInformation*) {}
};