#include "stdafx.h"
#include "FloatSensor.h"
#include <string>
#include <iostream>

using namespace std;

string floatValue;
string begRange;
string finishRange;
float begVal;
float finishVal;

//return the value
string FloatSensor::getData() {
	return floatValue;
}

//Set the data of the sensor. It will take the two values and make that the range
// of the random fuction. So that random will generate a number between firstVal and secondVal
void FloatSensor::setData(string firstVal, string secondVal) {
	begRange = firstVal;
	finishRange = secondVal;
	begVal = stod(begRange);
	finishVal = stod(finishRange);
}

//Generate the data
void FloatSensor::updateData() {
	float f = (finishVal - begVal) * ((float)rand() / (float)RAND_MAX) + begVal;
	floatValue = to_string(f);
}
