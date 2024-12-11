#include "ServerSocket.h"
KNT::ServerSocket::ServerSocket()
{
	std::map <SOCKET, std::string> clients;
	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == INVALID_SOCKET) {
		std::cerr << "Error creating socket" << std::endl;
		return;
	}
}
KNT::ServerSocket::~ServerSocket()
{
	try {
		closesocket(sock);
	}
	catch (std::exception e) {}
}
void KNT::ServerSocket::BindListen(std::string& ip, int port)
{
	struct sockaddr_in servaddr;
	servaddr.sin_port = htons(port); // port that server will listen for
	servaddr.sin_family = AF_INET;   // must be AF_INET
	inet_pton(AF_INET, ip.c_str(), &servaddr.sin_addr.s_addr); //ip addres from user

	//now we BIND
	if (bind(sock, (struct sockaddr*)&servaddr, sizeof(servaddr)) == SOCKET_ERROR)
	{
		std::cerr << "Error binding socket" << std::endl;
		return;
	}

	//now we start listerning
	if (listen(sock, SOMAXCONN) == SOCKET_ERROR)
	{
		std::cerr << "Error listening on socket" << std::endl;
		return;
	}
	while (1)
	{
		SOCKET client = ::accept(this->sock, NULL, NULL);
		char* buffer=new char[BUFFER_SIZE];
		int result = recv(client, buffer, BUFFER_SIZE, MSG_PEEK);
		if (result == SOCKET_ERROR)
		{
			std::cerr << "SOCKET DATA ERROR";
		}
		else if (result == 0)
		{
			std::cerr << "SOCKET DATA ERROR";
		}
		else if (result == -1)
		{
			std::cerr << "SOCKET DATA ERROR";
		}
		std::string message(buffer);
		this->clients.insert(std::pair<SOCKET, std::string>(client, message));
		delete buffer;
	}
}
