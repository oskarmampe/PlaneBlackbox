#pragma once
#include <winsock2.h>
#include <Ws2tcpip.h>
#include <stdio.h>
#include <string>
#include "PacketData.h"
#include "Sensor.h"
#include "BooleanSensor.h"
#include "FloatSensor.h"
#include "DoubleSensor.h"
#include "IntegerSensor.h"
#include "PlaneSensor.h"

class NetworkConnection {
public:
	void initialiseConnection();
	void sendPacket();
	void closeConnection();
private:
	int planeid;
	//Network Variables
	int iResult;
	WSADATA wsaData;
	SOCKET SendSocket = INVALID_SOCKET;
	sockaddr_in RecvAddr;
	unsigned short Port = 6881;
	char SendBuf[1024];
	int BufLen = 1024;
	//Initialise the sensors
	BooleanSensor autoPilot;
	DoubleSensor speed;
	FloatSensor temperature;
	IntegerSensor numberOfEnginesWorking;
	PlaneSensors allSensors;
};