#include "BindingSocket.h"
MNT::BindingSocket::BindingSocket(int domain, int service, int protocol, int port, u_long interfac) :
	MNT::SimpleSocket(domain, service, protocol, port, interfac) 
{
	setConnection(connect_to_network(getSock(), getAddress()));
	test_connection(getConnection());
}
MNT::BindingSocket::~BindingSocket()
{
}
int MNT::BindingSocket::connect_to_network(int sock, struct sockaddr_in address)
{
	return bind(sock, (struct sockaddr*)&address, sizeof(address));
}
