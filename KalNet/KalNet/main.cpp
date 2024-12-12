#pragma comment (lib, "ws2_32.lib")
#include "KalServer.h"



void displaysocket(KNT::KalServer kalserv)
{
	while (1)
	{
		std::map<SOCKET, std::string> clients = kalserv.GetSocket()->GetClients();
		for (std::map<SOCKET, std::string>::iterator it = clients.begin(); it != clients.end(); it++)
		{
			kalserv.Respond(it->first, "Hello", 5);
			std::cout << (int)kalserv.GetSocket()->GetClients().begin()->first << '\n';
		}
	}
}

int main()
{
	KNT::WSAinitializer wsa;
	std::string ip = "localhost";
	int port = 8080;
	
	KNT::KalServer kalserv(ip, port);
	displaysocket(kalserv);

	return 0;
}
