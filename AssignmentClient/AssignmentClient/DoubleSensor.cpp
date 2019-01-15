#include "stdafx.h"
#include "DoubleSensor.h"
#include <iostream>
#include <string>

using namespace std;


string doubleValue;
string startRange;
string endRange;
double startVal;
double endVal;

//return the value
void DoubleSensor::setData(string firstVal, string secondVal) {
	startRange = firstVal;
	endRange = secondVal;
	startVal = stod(startRange);
	endVal = stod(endRange);
}

//Set the data of the sensor. It will take the two values and make that the range
// of the random fuction. So that random will generate a number between firstVal and secondVal
string DoubleSensor::getData() {
	return doubleValue;
}

//Generate the data
void DoubleSensor::updateData() {
	double d = (endVal - startVal) * ((double)rand() / (double)RAND_MAX) + startVal;
	doubleValue = to_string(d);
}
