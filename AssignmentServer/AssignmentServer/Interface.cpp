#include "stdafx.h"

#include "Interface.h"


//Inherit from Observer
void Interface::update(PlaneInformation* plane) {
	timeMap[plane->getID()] = time(NULL); //map the plane with the recent time data has been sent
	cout << plane->toString(); //print out the information
}

//Check if the plane has sent any data recently
void Interface::checkTime() {
	for (it = timeMap.begin(); it != timeMap.end(); it++) { //for each value in map
		if (time(0) - it->second >= 5 && time(0) - it->second < 14){
			cout << "Alert! Plane: " << it->first << " has not sent for a significant period of time.\n";
		}
		else if (time(0) - it->second >= 15 && time(0) - it->second < 30) {
			cout << "Warning! Plane: " << it->first << " has not sent for a significant period of time.\n";
		}
		else if (time(0) - it->second >= 30) {
			cout << "DANGER! Plane: " << it->first << " has not sent for a significant period of time.\n";
		}
	
	}
}