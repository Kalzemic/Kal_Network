#include "SocketHandler.h"
KNT::SocketHandler::SocketHandler():
sock(socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)), mtx()
{
	if (sock == INVALID_SOCKET) 
	{
		int errorcode = WSAGetLastError();
		std::cerr << "Error creating socket" << errorcode << std::endl;
		return;
	}
}

KNT::SocketHandler::~SocketHandler()
{
	try {
		closesocket(sock);
	}
	catch (std::exception e) {}
	
}
void KNT::SocketHandler::send_message(SOCKET other, std::string message)
{
	getlock().lock();
	int res = ::send(other, message.data(), sizeof(message), MSG_PEEK);
	getlock().unlock();

}
std::string KNT::SocketHandler::receive_message(SOCKET other)
{
	char* buffer = new char[BUFFER_SIZE];
	int result = ::recv(other, buffer, BUFFER_SIZE, MSG_PEEK);
	if (result == SOCKET_ERROR)
	{
		std::cerr << "SOCKET DATA ERROR";
		return "@";
	}

	std::string response(buffer);
	return response;
}