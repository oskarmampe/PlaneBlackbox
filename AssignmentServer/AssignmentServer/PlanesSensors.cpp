#include "stdafx.h"

#include "PlaneSensors.h"

//If plane is updated, notify all observers
void PlaneSensors::UpdatePlane(PlaneInformation* plane) {
	//Inherited method call
	notify(plane);
}