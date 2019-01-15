#pragma once

#include <sstream>
#include <iostream>
#include <string>

using namespace std;


class PlaneInformation {
public:
	//Setters
	void setSpeed(double);
	void setTemperature(float);
	void setID(int);
	void setAutoPilot(bool);
	void setEngines(int);

	//Getters
	double getSpeed();
	float getTemperature();
	int getID();
	bool getAutoPilot();
	int getEngine();

	//Tostring
	std::string toString();

private:
	//Attributes
	double speed;
	float temperature;
	int planeid;
	bool autoPilot;
	int engine;
};