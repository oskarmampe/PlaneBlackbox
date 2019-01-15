#include "stdafx.h"
#include "BooleanSensor.h"
#include <iostream>
#include <string>

using namespace std;

string boolValue;

//set the data of the sensor
void BooleanSensor::setData(string value) {
		boolValue = value;
}

//get the data of the sensor
string BooleanSensor::getData() {
	return boolValue;
}

void BooleanSensor::updateData() {
	int value = rand() % 2;
	if (value == 1) {
		boolValue = "true";
	}
	else {
		boolValue = "false";
	}
}
