#include "stdafx.h"

#include "FileReader.h"

//Inherit update
void FileReader::update(PlaneInformation* plane) {
	//Initialise output file stream
	ofstream myfile;
	//Make a temporary string stream
	ostringstream os;
	os << plane->getID() << ".txt";
	string fileName = os.str();
	myfile.open(fileName, ios_base::app);//open file and append new lines
	myfile << "PlaneID is: " << to_string(plane->getID()) << " Speed is: " << to_string(plane->getSpeed()) << " Temperature is: " << to_string(plane->getTemperature()) << " autoPilot is: " << plane->getAutoPilot() << " Time: " << time(NULL) << "\n";
	myfile.close();
}