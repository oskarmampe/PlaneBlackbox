#include "stdafx.h"


#ifndef UNICODE
#define UNICODE
#endif

#define WIN32_LEAN_AND_MEAN

#include "NetworkConnection.h"
#include <ctime>

// Link with ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")


void NetworkConnection::initialiseConnection()
{

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != NO_ERROR) {
		wprintf(L"WSAStartup failed with error %d\n", iResult);
	}

	// Create a socket to receive data
	RecvSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (RecvSocket == INVALID_SOCKET) {
		wprintf(L"socket failed with error %d\n", WSAGetLastError());
	}

	// Bind the socket to an address and a specific port.
	RecvAddr.sin_family = AF_INET;
	RecvAddr.sin_port = htons(Port);
	RecvAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	iResult = bind(RecvSocket, (SOCKADDR *)& RecvAddr, sizeof(RecvAddr));
	if (iResult != 0) {
		wprintf(L"bind failed with error %d\n", WSAGetLastError());
	}

	//Setting up the socket so that it is non-blocking, so the program can run whilst it's receiving data.
	u_long nMode = 1; // 1: NON-BLOCKING 0: BLOCKING
	iResult = ioctlsocket(RecvSocket, FIONBIO, &nMode);
	if (iResult == SOCKET_ERROR) {
		wprintf(L"ioctlsocket failed with error %d\n", WSAGetLastError());
	}

	//Attach to subject so that a call to update, updates all observers
	product.attach(&gui);
	product.attach(&fileReader);

}

void NetworkConnection::receivePacketData()
{
	//Create a packet
	Packet packet;

	//As it is UDP, recvfrom has to be used
	iResult = recvfrom(RecvSocket, RecvBuf, BufLen, 0, (SOCKADDR *)& SenderAddr, &SenderAddrSize);

	//If data is received, do this, otheriwse skip this
	//Get packed data and put it into plane object
	if (iResult > 0) {
	int i = 0;
	PlaneInformation plane;
	while (i < (unsigned int)iResult)
	{
		packet.deserialize(&(RecvBuf[i]));
		i += sizeof(Packet);

		plane.setAutoPilot(packet.autopilot);
		plane.setID(packet.planeid);
		plane.setSpeed(packet.speed);
		plane.setTemperature(packet.temperature);
		plane.setEngines(packet.numberOfEnginesWorking);
		double bytesSent = ((double)BufLen * 1800.0/1000000.0);
		cout << "Maximum amount of data sent per client is: " << to_string(bytesSent) << "MB\n";
	}
	product.UpdatePlane(&plane);
}

	

	//Check if any plane has not sent data for a while. This is done even if iResult is not > 0
	if (time(NULL) - lastTimeUsed > 4) {
		gui.checkTime();
		lastTimeUsed = time(NULL);
		
		
	}
}


void NetworkConnection::closeConnection() {

	// Closing the Socket
	wprintf(L"Finished receiving. Closing socket.\n");
	iResult = closesocket(RecvSocket);
	if (iResult == SOCKET_ERROR) {
		wprintf(L"closesocket failed with error %d\n", WSAGetLastError());
	}


	// Clean up and exit.
	wprintf(L"Exiting.\n");
	WSACleanup();
}