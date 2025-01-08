#include "KalServer.h"
namespace KNT
{
    
	KNT::KalServer::KalServer(std::string& ip, int port) :
		sock(std::move(new ServerSocket())), ip(move(ip)), port(port)
	{
		GetSocket().BindListen(ip, port);
		std::thread t1 = std::thread(&KalServer::HandleAccepts, this);
		t1.detach();
	}
	KNT::KalServer::~KalServer()
	{
		try {
			closesocket(GetSocket().GetSocket());
			
		}
		catch (std::exception e) {}
	}

		void KNT::KalServer::HandleAccepts()
		{
			while (SOCKET client = ::accept(GetSocket().GetSocket(), NULL, NULL))
			{
				GetSocket().GetLock()->lock();
				std::string buffer;
				std::cout << socket << " client connected" << std::endl;
				GetClients()[client] = std::move(GetSocket().receive_message(client));
				GetSocket().GetLock()->unlock();

			}
		}
	
	
	
}
