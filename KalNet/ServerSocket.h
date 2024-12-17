#pragma once
#ifndef _SERVSOCK_
#define _SERVSOCK_
#include "Includes.h"
#include "SocketHandler.h"

#define BUFFER_SIZE 30000
namespace KNT {
	class ServerSocket: public SocketHandler
	{
	private:
		struct sockaddr_in* servaddr;
		std::map<SOCKET, std::string> clients;
	public:
		//Constructors
		ServerSocket() : 
		SocketHandler(), servaddr(new struct sockaddr_in()), clients() {}
		ServerSocket(ServerSocket& other) :
			SocketHandler(other), servaddr(other.servaddr), clients(other.clients) {
		}
		ServerSocket(ServerSocket&& other) noexcept :
			SocketHandler(std::move(other)), servaddr(std::move(other.servaddr)), clients(std::move(other.clients)) {
		}
		
		//Assignment operators
		void operator=(ServerSocket& other)
		{
			SocketHandler::operator=(other);
			servaddr = other.servaddr;
			clients = other.clients;
		}
		void operator=(ServerSocket&& other) noexcept
		{
			SocketHandler::operator=(std::move(other));
			servaddr = std::move(other.servaddr);
			clients = std::move(other.clients);
		}


		//Destructor
		~ServerSocket();
		void BindListen(std::string& ip, int port);
		//getters
		std::map<SOCKET, std::string> GetClients() { return clients; }
		struct sockaddr_in* GetAddr() { return servaddr; }
		
	};

}

#endif //_SERVSOCK_

