#include "WSAinitializer.h"
namespace KNT
{
	KNT::WSAinitializer::WSAinitializer()
	{
		WSADATA wsaData = {};
		if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
			std::cerr << "WSAStartup failed" << std::endl;
			return ;
		}
	}
	KNT::WSAinitializer::~WSAinitializer()
	{
		try {
			WSACleanup();
		}
		catch (std::exception e) {}
	}
}
