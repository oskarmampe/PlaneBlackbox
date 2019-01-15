#pragma once
#include "Sensor.h"

class DoubleSensor : public Sensor {
public:
	//Override
	void setData(string, string);
	void updateData();
	string getData();
};