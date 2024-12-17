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
		std::mutex* mtx;

	public:
		// Constructors
		SocketHandler();
		SocketHandler(SocketHandler& other):
			sock(other.sock), mtx(other.mtx) {
		}
		SocketHandler(SocketHandler&& other) noexcept :
			sock(std::move(other.sock)), mtx(std::move(other.mtx)) {
		}
		//Assignment operators
		void operator=(SocketHandler& other)
		{
			sock = other.sock;
			mtx = other.mtx;
		}
		void operator=(SocketHandler&& other) noexcept
		{
			sock = std::move(other.sock);
			mtx = std::move(other.mtx);
		}


		//Destructor
		~SocketHandler();

		//getters
		SOCKET	GetSocket() { return sock; }
		std::mutex* GetLock() { return mtx; }

		//send messages to other sockets
		void send_message(SOCKET other, std::string message);
		std::string receive_message(SOCKET other);
	};
}

#endif //_CLIENTSOCKET_