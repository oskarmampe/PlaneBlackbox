#include "stdafx.h"

#include "NetworkConnection.h"


int main() {
	NetworkConnection connection;
	connection.initialiseConnection();
	//reset the random seed
	srand(time(NULL));
	while (true) {
		connection.sendPacket();
	}
	connection.closeConnection();
}