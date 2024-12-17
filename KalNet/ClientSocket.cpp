#include "ClientSocket.h"

KNT::ClientSocket::~ClientSocket()
{
	try {
		closesocket(GetSocket());
	}
	catch (std::exception e) {}
	delete GetLock();
}
void KNT::ClientSocket::connect_to_server(KNT::KalServer server)
{
	GetLock()->lock();
	::connect(GetSocket(), (struct sockaddr*)server.GetSocket().GetAddr(), sizeof(*server.GetSocket().GetAddr()));
	GetLock()->unlock();
}

