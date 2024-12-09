#include "ListeningSocket.h"



MNT::ListeningSocket::ListeningSocket(int domain, int service, int protocol, int port, u_long interfac, int bklg) :  
MNT::BindingSocket(domain, service,  protocol,  port,  interfac) 
{
	backlog = bklg;
	start_listening();
	test_connection(listening);
}

MNT::ListeningSocket::~ListeningSocket()
{
}
int MNT::ListeningSocket::getBacklog()
{
	return backlog;
}

void MNT::ListeningSocket::start_listening()
{
	listening = listen(getSock(), backlog);
}