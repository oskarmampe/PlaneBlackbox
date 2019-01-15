#pragma once
#pragma once
#include "Sensor.h"

class IntegerSensor : public Sensor {
public:
	//Override
	void setData(string, string);
	void updateData();
	string getData();
};