#pragma once
#ifndef _CLIENTSOCKET_
#define _CLIENTSOCKETS_
#include "KALServer.h"
namespace KNT {
	class ClientSocket: public SocketHandler
	{
		
	public:
		// Contructors
		ClientSocket() : SocketHandler() {}
		ClientSocket(ClientSocket& other):
			SocketHandler(other) {
		}
		ClientSocket(ClientSocket&& other) noexcept :
			SocketHandler(std::move(other)) {
		}
		//Assignment operators
		void operator=(ClientSocket& other)
		{
			SocketHandler::operator=(other);
		}
		void operator=(ClientSocket&& other) noexcept
		{
			SocketHandler::operator=(std::move(other));
		}
		
		//Destructors
		~ClientSocket();
		//connect func
		void connect_to_server(KNT::KalServer server);

	

	
	};
}

#endif //_CLIENTSOCKET_

