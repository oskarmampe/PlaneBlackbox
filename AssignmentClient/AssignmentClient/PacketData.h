#pragma once

#define MAX_PACKET_SIZE 1000000

using namespace std;

struct Packet {
	//What the packet will contain
	double speed;
	float temperature;
	bool autopilot;
	int planeid;
	int numberOfEnginesWorking;

	//prepare the packet to be sent
	void serialize(char * data) {
		memcpy(data, this, sizeof(Packet));
	}
};