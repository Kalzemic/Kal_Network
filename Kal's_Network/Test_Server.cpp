#include "Test_Server.h"

void MNT::Test_Server::accept_request()
{
	struct sockaddr_in address = getSocket()->getAddress();
	int addrlen = sizeof(getSocket()->getAddress());
	new_socket = accept(getSocket()->getSock(), (struct sockaddr*)&address, (int*) & addrlen);
	if (new_socket < 0)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}

	_read(new_socket, buffer, 30000);
}
void MNT::Test_Server::handle_request()
{
	std::cout << buffer << std::endl;
}
void MNT::Test_Server::respond()
{
	std::string response = "Hor_tahat";
	_write(new_socket, &response, std::strlen((char*)&response));
	_close(new_socket);
}
MNT::Test_Server::~Test_Server()
{
	_close(new_socket);
}
void MNT::Test_Server::launch()
{
	while (true)
	{
		std::cout << "Waiting for connection" << std::endl;
		accept_request();
		handle_request();
		respond();
		std::cout << "Connection closed" << std::endl;
	}
}MNT::Test_Server::Test_Server() : 
	Kal_Server(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10)
{
	launch();
}
