#pragma once
#ifndef _SIMPLESOCKET_
#define _SIMPLESOCKET_
#include <stdio.h>
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib, "Ws2_32.lib")

namespace MNT{
class SimpleSocket
{
public:
	//Constructor and Destructor
	SimpleSocket(int domain, int service, int protocol, int port, u_long interfac);
	~SimpleSocket();
	
	//gettersss
	SOCKET getSock();
	struct sockaddr_in getAddress();



	//network/testing functions
	virtual int connect_to_network(SOCKET sock, struct sockaddr_in address)=0;
	void test_connection(int);
private:
	SOCKET sock;
	struct sockaddr_in address;

};
}

#endif // !_SIMPLESOCKET_

