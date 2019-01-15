#pragma once

//Max data size
#define MAX_PACKET_SIZE 1000000

using namespace std;

//Packet contents
struct Packet {
	//What the packet will have
	double speed;
	float temperature;
	bool autopilot;
	int planeid;
	int numberOfEnginesWorking;

	//prepare to receive
	void deserialize(char * data) {
		memcpy(this, data, sizeof(Packet));
	}
};	