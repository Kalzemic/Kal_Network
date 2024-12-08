#ifndef _LISTENINGSOCKET_
#define _LISTENINGSOCKET_
#include "BindingSocket.h"

namespace MNT {
	class ListeningSocket : public MNT::BindingSocket
	{
	public:
		ListeningSocket(int domain, int service, int protocol, int port, u_long interfac);
		~ListeningSocket();
		
	};
}

#endif _LISTENINGSOCKET_

