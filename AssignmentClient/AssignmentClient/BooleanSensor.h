#pragma once
#include "Sensor.h"

class BooleanSensor : public Sensor {
public:
	//Override
	string getData();
	void setData(string);
	void updateData();
};