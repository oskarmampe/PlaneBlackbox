#pragma once

#include "PlaneInformation.h"
#include "Observer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class FileReader : public Observer{
public:
	//Override
	void update(PlaneInformation *);
};