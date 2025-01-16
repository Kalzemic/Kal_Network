#include "KalServer.h"
#include "StringHelp.h"
#include <fstream>
namespace KNT
{
	 
	KNT::KalServer::KalServer(const std::string& ip, int port) :
		sock(std::move(new ServerSocket())), ip(move(ip)), port(port)
	{
		GetSocket().BindListen(ip, port);
		//std::thread t1 = std::thread(&KalServer::HandleAccepts, this);
		//t1.detach();
		
	}
	KNT::KalServer::~KalServer()
	{
		try {
			closesocket(GetSocket().GetSocket());
			
		}
		catch (std::exception e) {}
	}

	void KNT::KalServer::HandleClient(SOCKET client)
	{
		
			GetSocket().getlock().lock();
			std::string req = GetSocket().receive_message(client);
			std::cout << req << std::endl;
			std::vector<std::string> reqvec = split(req, ' ');
			if (reqvec[0] == "GET")
			{
				if (reqvec[1]=="/")
					sendfile(client, "KalNet/index.html", "text/html");
				if (reqvec[1] == "/script.js")
					sendfile(client, "KalNet/script.js", "application/javascript");
				if (reqvec[1] == "/script.js")
					sendfile(client, "KalNet/style.css", "text/css");
			}
			
			GetSocket().getlock().unlock();

		
	}

	void KalServer::sendfile(SOCKET client, const std::string filepath, const std::string contenttype)
	{
		std::ifstream ifile(filepath, std::ios::binary);
		if (!ifile)
		{
			std::string notFound = "HTTP / 1.1 404 Not Found\r\n"
				"Content-Type: text/plain\r\n"
				"Content-Length: 13\r\n"
				"\r\n"
				"404 Not Found";
			GetSocket().send_message(client, notFound);
			return;
		}
		std::ostringstream buffer;
		buffer << ifile.rdbuf();
		std::string filecontent = buffer.str();
		std::ostringstream response;
		response << "HTTPS/1.1 200 OK\r\n" <<
			"Content-Type: \r\n" <<
			"Content-Length: " << filecontent.size() << 
			"Connection: keep-alive\r\n\r\n";
		std::string header = response.str();
		header.append(filecontent);
		GetSocket().send_message(client, header);
		
	}
	
}
