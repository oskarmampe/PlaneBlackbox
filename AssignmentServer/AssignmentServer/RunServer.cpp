//Entry Point for Sever

#include "stdafx.h"

#include "NetworkConnection.h"

#include <iostream>

//Run the application
int main() {
	NetworkConnection connection;
	connection.initialiseConnection();
	while (true) {
		connection.receivePacketData();
	}

	
}