#pragma comment (lib, "ws2_32.lib")
#include "ClientSocket.h"



void displaysocket(KNT::KalServer kalserv)
{
	while (1)
	{
		std::map<SOCKET, std::string> clients = kalserv.GetSocket().GetClients();
		for (std::map<SOCKET, std::string>::iterator it = clients.begin(); it != clients.end(); it++)
		{
			kalserv.GetSocket().send_message(it->first, "Hello");
			std::cout << (int)kalserv.GetSocket().GetClients().begin()->first << '\n';
		}
	}
}

int main()
{
	KNT::WSAinitializer wsa;
	std::string ip = "127.0.0.1";
	int port = 8080;
	
	KNT::KalServer kalserv(ip, port);
	displaysocket(kalserv);
	std::thread t2 = std::thread(&displaysocket, kalserv);
	t2.detach();
	KNT::ClientSocket client;
	client.connect_to_server(kalserv);
	return 0;
}
