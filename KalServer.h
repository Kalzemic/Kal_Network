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
	std::map<SOCKET, std::string> clients;

public:
	//constructors
	KalServer(std::string& ip, int port );

	//desturctor
	~KalServer();
	//gettersss
	ServerSocket& GetSocket() { return *sock; }
	std::map<SOCKET, std::string> GetClients() { return clients; }
	
	//Server Methods
	void HandleClient();
	void sendfile(SOCKET client, const std::string filepath, const std::string contenttype);
	
};
}


#endif //_KALSERVER_

