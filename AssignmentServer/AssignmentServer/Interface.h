#pragma once

#include "Observer.h"
#include "PlaneInformation.h"
#include "PlaneSensors.h"
#include <iostream>
#include <ctime>
#include <map>
#include <Ws2tcpip.h>

using namespace std;

class Interface : public Observer{
public:
	//Override
	void update(PlaneInformation*);
	void checkTime();
private:
	map<int, time_t> timeMap;//A map that contains an id and a corresponding time unit that represents last time data was sent
	map<int, time_t>::iterator it;
};