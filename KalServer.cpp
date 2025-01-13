#include "KalServer.h"
#include "StringHelp.h"
#include <fstream>
namespace KNT
{
    
	KNT::KalServer::KalServer(std::string& ip, int port) :
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

	void KNT::KalServer::HandleClient()
	{
		if (SOCKET client = ::accept(GetSocket().GetSocket(), NULL, NULL))
		{
			GetSocket().getlock().lock();
			std::string req = GetSocket().receive_message(client);
			std::cout << req << std::endl;
			std::vector<std::string> reqvec = split(req, ' ');
			if (reqvec[0] == "GET")
			{
				if (reqvec[26].find("text/html")!=std::string::npos)
					sendfile(client, "page.html", "text/html");
				if (reqvec[1] == "/script.js")
					sendfile(client, "script.js", "");
				if (reqvec[1] == "/test.xml")
					sendfile(client, "test.xml", "");
			}
			
			GetSocket().getlock().unlock();

		}
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
		response << "HTTP/ 1.1 200 OK\r\n"
			<< "Content-Type: " << contenttype << "; charset = UTF - 8\r\n"
			<< "Content-Length: " << filecontent.size() << "\r\n"
			<< "\r\n";
		std::string header = response.str();
		header += filecontent;
		GetSocket().send_message(client, header);
	}
	
}
