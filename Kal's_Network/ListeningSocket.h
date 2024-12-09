#ifndef _LISTENINGSOCKET_
#define _LISTENINGSOCKET_
#include "BindingSocket.h"

namespace MNT {
	class ListeningSocket : public MNT::BindingSocket
	{
	private: 
		int backlog;
		int listening;


	public:
		
		//constructor/destructor
		ListeningSocket(int domain, int service, int protocol, int port, u_long interfac, int bklg);
		~ListeningSocket();
		
		//getters
		int getBacklog();

		//listening methods
		 void start_listening();
	};
}

#endif _LISTENINGSOCKET_

