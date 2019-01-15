// NetworkConnection.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#ifndef UNICODE
#define UNICODE
#endif

#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "NetworkConnection.h"




// Link with ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

void NetworkConnection::initialiseConnection()
{
	//Get plane id
	cout << "Please enter a planeid\n";
	cin >> planeid;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != NO_ERROR) {
		wprintf(L"WSAStartup failed with error: %d\n", iResult);
	}

	// Create a socket for sending data
	SendSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (SendSocket == INVALID_SOCKET) {
		wprintf(L"socket failed with error: %ld\n", WSAGetLastError());
		WSACleanup();
	}


	// Set up the RecvAddr structure with the IP address of
	// the receiver (in this example case "127.0.0.1")
	// and the specified port number which is 6881.
	RecvAddr.sin_family = AF_INET;
	RecvAddr.sin_port = htons(Port);
	RecvAddr.sin_addr.s_addr = inet_addr("127.0.0.1");


	//set the value of sensors
	speed.setData("0", "288.0");
	temperature.setData("0", "20");
	numberOfEnginesWorking.setData("2","4");
	autoPilot.setData("false");

	//Add the sensors to a vector class that will update all sensors 

	allSensors.add(&speed);
	allSensors.add(&temperature);
	allSensors.add(&autoPilot);
	allSensors.add(&numberOfEnginesWorking);
}


void NetworkConnection::sendPacket() {
	//initialise the buffer that is going to be sent
	const unsigned int packet_size = sizeof(Packet);
	char packet_data[packet_size];


	//Update all sensors
	allSensors.updateData();

	//get the values of the sensors
	string speedVal = allSensors.getChild(0)->getData();
	string temperatureVal = allSensors.getChild(1)->getData();
	string autopilotVal = allSensors.getChild(2)->getData();
	string engineVal = allSensors.getChild(3)->getData();
	bool autoVal;

	if (autopilotVal == "true") {
		autoVal = true;
	} else {
		autoVal = false;
	}

	//Make a packet
	Packet packet;

	//Set the values of the plane object to corresponding packet data
	packet.speed = stod(speedVal);//convert string to double
	packet.temperature = stof(temperatureVal);//convert string to float
	packet.autopilot = autoVal;
	packet.planeid = planeid;
	packet.numberOfEnginesWorking = stoi(engineVal);
	packet.serialize(packet_data);


	// Send a datagram to the receiver
	wprintf(L"Sending a datagram to the receiver...\n");
	iResult = sendto(SendSocket, packet_data, packet_size, 0, (SOCKADDR *)& RecvAddr, sizeof(RecvAddr));
	if (iResult == SOCKET_ERROR) {
		wprintf(L"sendto failed with error: %d\n", WSAGetLastError());
		closesocket(SendSocket);
		WSACleanup();
	}
	Sleep(2000);

}


void NetworkConnection::closeConnection() {

	// When the application is finished sending, close the socket.
	wprintf(L"Finished sending. Closing socket.\n");
	iResult = closesocket(SendSocket);
	if (iResult == SOCKET_ERROR) {
		wprintf(L"closesocket failed with error: %d\n", WSAGetLastError());
		WSACleanup();
	}

	// Clean up and quit.
	wprintf(L"Exiting.\n");
	WSACleanup();
}