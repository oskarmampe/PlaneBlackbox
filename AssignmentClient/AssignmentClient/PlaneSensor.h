#pragma once

#include <vector>
#include <iostream> 
#include <algorithm> 
#include <functional> 
#include "stdafx.h"

#include "Sensor.h"

using namespace std;

class PlaneSensors: public Sensor {
public:
	//Override
	void updateData();
	void add(Sensor *aSensor);
	Sensor* getChild(int);

private:
	//Contain all sensors
	vector<Sensor*> gList;
};