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
	KalServer(std::string& ip, int port);
	~KalServer();
	void Respond(SOCKET client, std::string buffer, int buffersize);

	//gettersss
	ServerSocket* GetSocket() { return sock; }

};
}


#endif //_KALSERVER_

