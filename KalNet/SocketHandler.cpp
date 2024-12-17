#include "SocketHandler.h"
KNT::SocketHandler::SocketHandler():
sock(socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)), mtx(new std::mutex())
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
	delete mtx;
}
void KNT::SocketHandler::send_message(SOCKET other, std::string message)
{
	mtx->lock();
	int res = ::send(other, message.data(), sizeof(message), MSG_PEEK);
	mtx->unlock();

}
std::string KNT::SocketHandler::receive_message(SOCKET other)
{
	mtx->lock();
	char* buffer = new char[BUFFER_SIZE];
	int result = ::recv(other, buffer, BUFFER_SIZE, MSG_PEEK);
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
	std::string response(buffer);
	mtx->unlock();
	return response;
}