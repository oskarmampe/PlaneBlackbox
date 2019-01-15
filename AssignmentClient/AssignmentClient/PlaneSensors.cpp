// Composite
#include "stdafx.h"

#include "Sensor.h"
#include "PlaneSensor.h"

void PlaneSensors::updateData() {
	std::for_each(gList.begin(), gList.end(), mem_fun(&Sensor::updateData));
}

void PlaneSensors::add(Sensor *aSensor) {

		gList.push_back(aSensor);
}

Sensor* PlaneSensors::getChild(int index) {
	return gList.at(index);
}
	