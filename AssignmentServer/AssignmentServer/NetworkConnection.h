#pragma once
#include <winsock2.h>
#include <Ws2tcpip.h>
#include <stdio.h>
#include "PacketData.h"
#include "PlaneInformation.h"
#include "PlaneSensors.h"
#include "Interface.h"
#include "FileReader.h"

class NetworkConnection {

public:
	void receivePacketData();
	void closeConnection();
	void initialiseConnection();
private:
	//Network Initialisation
	SOCKET RecvSocket;
	char network_data[MAX_PACKET_SIZE];
	int iResult = 0;
	WSADATA wsaData;
	sockaddr_in RecvAddr;
	unsigned short Port = 6881;
	char RecvBuf[512];
	int BufLen = 512;
	sockaddr_in SenderAddr;
	int SenderAddrSize = sizeof(SenderAddr);
	time_t lastTimeUsed;
	//Observer
	PlaneSensors product;
	Interface gui;
	FileReader fileReader;
};