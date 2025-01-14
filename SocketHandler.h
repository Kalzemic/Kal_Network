#pragma once
#ifndef _SOCKET_
#define _SOCKETS_
#include "Includes.h"
#define BUFFER_SIZE 30000
namespace KNT {
	class SocketHandler
	{
	private:
		SOCKET sock;
		std::mutex mtx;

	public:
		// Constructors
		SocketHandler();
		SocketHandler(SocketHandler& other):
			sock(other.sock),mtx() {
		}
		SocketHandler(SocketHandler&& other) noexcept :
			sock(std::move(other.sock)), mtx()
		{
			other.sock = 0;
		}
		//Assignment operators
		void operator=(SocketHandler& other)
		{
			sock = other.sock;
			
		}
		void operator=(SocketHandler&& other) noexcept
		{
			sock = std::	move(other.sock);
			
		}


		//Destructor
		~SocketHandler();

		//getters
		SOCKET	GetSocket() { return sock; }
		std::mutex& getlock() { return mtx; }

		//send messages to other sockets
		void send_message(SOCKET other, std::string message);
		std::string receive_message(SOCKET other);
	};
}

#endif //_CLIENTSOCKET_
