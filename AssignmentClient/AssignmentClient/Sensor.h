#pragma once
#include <vector>
#include <iostream> 
#include <algorithm> 
#include <functional> 
#include <ctime>
#include <cstdlib>

using namespace std;

class Sensor {
public:
	virtual void updateData() {}//used for all Sensors
	virtual void setData(string) {}//used for BooleanSensors
	virtual void setData(string, string) {}//used for Float and DoubleSensors
	virtual string getData() { return ""; } //used for Sensors
	virtual void remove(Sensor *g) {} //used for PlaneSensor
	virtual void add(Sensor *g) {} //used for PlaneSensor
	virtual Sensor* getChild(int) { return NULL; } //used for PlaneSensor
	virtual ~Sensor() {}
};