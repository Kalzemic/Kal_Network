#pragma once
#ifndef _KAL_SERVER_
#define _KAL_SERVER_
#include <stdio.h>
#include "ListeningSocket.h"




namespace MNT {
class Kal_Server
{
private: 
	ListeningSocket* Socket;
public:
	//constructor/destructor
	Kal_Server(int domain, int service, int protocol, int port, u_long interfac,int bklg);
	~Kal_Server();

	//request handling
	virtual void accept_request() = 0;
	virtual void handle_request() = 0;
	
	//response handling
	virtual void respond() = 0;
	

	/// launch function 
	virtual void launch() = 0;

	//Getterssss
	ListeningSocket* getSocket();
};
}



#endif//!_KAL_SERVER_

