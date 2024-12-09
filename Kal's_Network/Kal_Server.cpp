#include "Kal_Server.h"

MNT::Kal_Server::Kal_Server(int domain, int service, int protocol, int port, u_long interfac,int bklg)
{
	delete Socket;
	Socket = new ListeningSocket(domain, service, protocol, port, interfac, bklg);
}
MNT::Kal_Server::~Kal_Server()
{
	delete Socket;
}
MNT::ListeningSocket* MNT::Kal_Server::getSocket()
{
	return Socket;
}