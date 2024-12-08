#include "ListeningSocket.h"
MNT::ListeningSocket::ListeningSocket(int domain, int service, int protocol, int port, u_long interfac) :  
MNT::BindingSocket(domain, service,  protocol,  port,  interfac) 
{

}