#ifndef _BINDINGSOCKET_
#define _BINDINGSOCKET_
#include "SimpleSocket.h"


namespace MNT {
	class BindingSocket : public MNT::SimpleSocket
	{
	public:
		BindingSocket(int domain, int service, int protocol, int port, u_long interfac);
		~BindingSocket();
		int connect_to_network(int sock, struct sockaddr_in address);

	};
}
#endif // !_BINDINGSOCKET_
