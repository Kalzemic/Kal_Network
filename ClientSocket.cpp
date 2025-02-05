#include "ClientSocket.h"

KNT::ClientSocket::~ClientSocket()
{ }
void KNT::ClientSocket::connect_to_server(KNT::KalServer server)
{
	getlock().lock();
	if(::connect(GetSocket(), (struct sockaddr*)server.GetSocket().GetAddr(), sizeof(*server.GetSocket().GetAddr()))!=0)
	{
		std::cout << "Connection successful" <<std::endl;
	}
	getlock().unlock();
}

