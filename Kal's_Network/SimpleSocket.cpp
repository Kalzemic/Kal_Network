#include "SimpleSocket.h"
MNT::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interfac)
{
	address.sin_family = domain;
	address.sin_port = htons(port);
	address.sin_addr.s_addr = htonl(interfac);
	//creat socket
	sock = socket(domain, service, protocol);
	test_connection(sock);
	//establish connection
	
}
MNT::SimpleSocket::~SimpleSocket()
{
	closesocket(sock);
}
 SOCKET MNT::SimpleSocket::getSock()
{
	return sock;
}

struct sockaddr_in MNT::SimpleSocket::getAddress()
{
	return address;
}
void MNT::SimpleSocket::test_connection(int tested)
{
	if (tested < 0)
	{
		perror("Falied to connect");
		exit(EXIT_FAILURE);
	}
}

