#pragma once
#ifndef _WSAinitializer_
#define _WSAinitializer_
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>
#include <iostream>

namespace KNT {
	class WSAinitializer
	{
	public:
		WSAinitializer();
		~WSAinitializer();
	};
}
#endif //_WSAInitiializer_

