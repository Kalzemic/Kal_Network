#ifndef _KALSERVER_
#define _KALSERVER_
#include <string>
#include "ServerSocket.h"
#include <thread>
namespace KNT
{
class KalServer
{
private:
	ServerSocket* sock;
	std::string ip;
	int port;
	

public:
	//constructors
	KalServer(std::string& ip, int port );

	//desturctor
	~KalServer();
	//gettersss
	ServerSocket& GetSocket() { return *sock; }

};
}


#endif //_KALSERVER_

