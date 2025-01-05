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
		
	public:
		//Constructors
		ServerSocket() : 
		SocketHandler(), servaddr(new struct sockaddr_in()){}
		ServerSocket(ServerSocket& other) :
			SocketHandler(other), servaddr(other.servaddr) {
		}
		ServerSocket(ServerSocket&& other) noexcept :
			SocketHandler(std::move(other)), servaddr(std::move(other.servaddr)) {
		}
		
		//Assignment operators
		void operator=(ServerSocket& other)
		{
			SocketHandler::operator=(other);
			servaddr = other.servaddr;
			
		}
		void operator=(ServerSocket&& other) noexcept
		{
			SocketHandler::operator=(std::move(other));
			servaddr = std::move(other.servaddr);
			
		}


		//Destructor
		~ServerSocket();
		void BindListen(std::string& ip, int port);
		//getters
		struct sockaddr_in* GetAddr() { return servaddr; }
		
	};

}

#endif //_SERVSOCK_

