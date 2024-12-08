#pragma once
#ifndef _SIMPLESOCKET_
#define _SIMPLESOCKET_
#include <stdio.h>
#include <iostream>
#include <WinSock2.h>

namespace MNT{
class SimpleSocket
{
public:
	//Constructor and Destructor
	SimpleSocket(int domain, int service, int protocol, int port, u_long interfac);
	~SimpleSocket();
	
	//gettersss
	int getSock();
	int getConnection();
	struct sockaddr_in getAddress();

	//setterssss
	void setConnection(int con);

	//network/testing functions
	int virtual connect_to_network(int);
	void test_connection(int);
private:
	int sock;
	int connection;
	struct sockaddr_in address;

};
}

#endif // !_SIMPLESOCKET_

