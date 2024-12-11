#include "KalServer.h"
namespace KNT 
{
	KNT::KalServer::KalServer(std::string& ip, int port): ip(ip), port(port)
	{
		sock =  KNT::ServerSocket();
		std::thread t1 = std::thread(&KNT::ServerSocket::BindListen, &sock, std::ref(ip), port);
		t1.detach();
	}
}
KNT::KalServer::~KalServer()
{
}
void ::KNT::KalServer::Respond(SOCKET client, std::string buffer, int buffersize)
{
	send(client, buffer.data(), buffersize, MSG_PEEK);
}
