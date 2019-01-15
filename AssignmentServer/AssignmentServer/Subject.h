#pragma once
#include <vector>
#include <list>
#include <algorithm>
#include "PlaneInformation.h"
#include "Observer.h"

using namespace std;

class Subject {
public:
	//Add or remove from vector
	void attach(Observer *product);
	void detach(Observer *product);
	//update all observers
	void notify(PlaneInformation*);
private:
	//Hold all observers
	std::vector<Observer*> list;
};
