#include "KalServer.h"
namespace KNT
{
    KNT::KalServer::KalServer(std::string& ip, int port):
		sock(std::move(new ServerSocket())), ip(move(ip)), port(port)
    {
        std::thread t1 = std::thread(&KNT::ServerSocket::BindListen, sock, std::ref(ip), port);
        t1.detach();
    }

	KNT::KalServer::~KalServer()
	{
		try {
			closesocket(GetSocket().GetSocket());
			
		}
		catch (std::exception e) {}
	}
	
}
