#pragma once
#include "Sensor.h"

class FloatSensor : public Sensor {
public:
	//Override
	void setData(string, string);
	void updateData();
	string getData();
};