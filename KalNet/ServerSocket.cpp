#include "ServerSocket.h"

KNT::ServerSocket::~ServerSocket()
{
	KNT::SocketHandler::~SocketHandler();
	delete servaddr;
}
void KNT::ServerSocket::BindListen(std::string& ip, int port)
{
	
	servaddr->sin_port = ::htons(port); // port that server will listen for
	servaddr->sin_family = PF_INET;   // must be AF_INET
	::inet_pton(PF_INET, ip.c_str(), &servaddr->sin_addr.s_addr); //ip addres from user
	
	//now we BIND
	if (::bind(GetSocket(), (struct sockaddr*)servaddr, sizeof(*servaddr)) == SOCKET_ERROR)
	{
		int errorcode = WSAGetLastError();
		std::cerr << "Error binding socket" << errorcode << std::endl;
		return;
	}

	//now we start listerning
	if (listen(GetSocket(), SOMAXCONN) == SOCKET_ERROR)
	{
		std::cerr << "Error listening on socket" << std::endl;
		return;
	}
	
}


