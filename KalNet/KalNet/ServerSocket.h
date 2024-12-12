#pragma once
#ifndef _SERVSOCK_
#define _SERVSOCK_
#include "WSAinitializer.h"
#include <mutex>
#include <string>
#include <map>

#define BUFFER_SIZE 30000
namespace KNT {
	class ServerSocket
	{
	private:
		SOCKET sock;
		std::map<SOCKET, std::string> clients;
	public:
		ServerSocket();
		~ServerSocket();
		void BindListen(std::string& ip, int port);
		//getters
		std::map<SOCKET, std::string> GetClients() { return clients; }
		SOCKET GetSocket() { return sock; }
	};

}

#endif //_SERVSOCK_

