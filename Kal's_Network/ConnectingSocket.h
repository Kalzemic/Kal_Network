#ifndef _ConnectingSocket_
#define _ConnectingSocket_
#include "SimpleSocket.h"

namespace MNT {
	class ConnectingSocket : public SimpleSocket
	{
	public:
		ConnectingSocket(int domain, int service, int protocol, int port, u_long interfac);
		~ConnectingSocket();
		int connect_to_network(SOCKET sock, struct sockaddr_in address) override;
	};
}

#endif // !_ConnectingSocket_

