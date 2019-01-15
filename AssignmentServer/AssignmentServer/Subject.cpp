#include "stdafx.h"

#include "Subject.h"

//Put observer in the vector
void Subject::attach(Observer *observer)
{
	list.push_back(observer);
}

//Remove an observer from the vector
void Subject::detach(Observer *observer)
{
	list.erase(std::remove(list.begin(), list.end(), observer), list.end());
}

//Notify all observers that change has happened
void Subject::notify(PlaneInformation* plane)
{
	for (vector<Observer*>::const_iterator iter = list.begin(); iter != list.end(); ++iter)
	{
		if (*iter != 0)
		{
			(*iter)->update(plane);
		}
	}
}