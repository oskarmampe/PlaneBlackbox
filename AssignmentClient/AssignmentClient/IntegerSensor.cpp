#include "stdafx.h"
#include "IntegerSensor.h"
#include <iostream>
#include <string>

using namespace std;


string intValue;
string intStartRange;
string intEndRange;
int startValue;
int endValue;

//return the value
void IntegerSensor::setData(string firstVal, string secondVal) {
	intStartRange = firstVal;
	intEndRange = secondVal;
	startValue = stoi(intStartRange);
	endValue = stoi(intEndRange);
}

//Set the data of the sensor. It will take the two values and make that the range
// of the random fuction. So that random will generate a number between firstVal and secondVal
string IntegerSensor::getData() {
	return intValue;
}

//Generate the data
void IntegerSensor::updateData() {
	int i = rand() % (endValue - 1) + startValue;
	intValue = to_string(i);
}
