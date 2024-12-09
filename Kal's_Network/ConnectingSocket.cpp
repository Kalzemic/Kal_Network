#include "ConnectingSocket.h"
MNT::ConnectingSocket::ConnectingSocket(int domain, int service, int protocol, int port, u_long interfac) :
	MNT::SimpleSocket(domain, service, protocol, port, interfac)
{
	connect_to_network(getSock(), getAddress());
}
int MNT::ConnectingSocket::connect_to_network(SOCKET sock, struct sockaddr_in address)
{
	return connect(sock, (struct sockaddr*)&address, sizeof(address));
}
MNT::ConnectingSocket::~ConnectingSocket()
{
}