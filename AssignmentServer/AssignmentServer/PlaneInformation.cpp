#include "stdafx.h"

#include "PlaneInformation.h"

//Set speed
void PlaneInformation::setSpeed(double speed) {
	this->speed = speed;
}

//Set Temperature
void PlaneInformation::setTemperature(float temperature) {
	this->temperature = temperature;
}

//Set Number of Engines Working
void PlaneInformation::setEngines(int engine) {
	this->engine = engine;
}

//Set id
void PlaneInformation::setID(int planeid) {
	this->planeid = planeid;
}

//Set Auto Pilot
void PlaneInformation::setAutoPilot(bool autoPilot) {
	this->autoPilot = autoPilot;
}

//Get speed
double PlaneInformation::getSpeed() {
	return speed;
}

//Get Temperature
float PlaneInformation::getTemperature() {
	return temperature;
}

//Get id
int PlaneInformation::getID() {
	return planeid;
}

int PlaneInformation::getEngine() {
	return engine;
}

//Get Auto Pilot
bool PlaneInformation::getAutoPilot() {
	return autoPilot;
}

//Return all values of plane in string form
string PlaneInformation::toString() {
	ostringstream os;
	os << "PlaneID is: " << to_string(this->planeid) << " Speed is: " << to_string(this->speed) << " Temperature is: " << to_string(this->temperature)  << " autoPilot is: " << boolalpha << this->autoPilot << " Number of Engines working are: " << this->engine << "\n";
	string temp = os.str();
	return temp;
}