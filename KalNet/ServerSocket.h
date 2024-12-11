#pragma once
#ifndef _SERVSOCK_
#define _SERVSOCK_
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>
#include <iostream>
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
	};

}

#endif //_SERVSOCK_

