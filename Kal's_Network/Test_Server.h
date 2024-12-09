#pragma once
#ifndef _Test_Server_
#define _Test_Server_

#include "Kal_Server.h"
#include <io.h>

namespace MNT {
class Test_Server : public Kal_Server
{
private:
	char buffer[30000] = {0};
	int new_socket;
	void accept_request() override;
	void handle_request() override;
	void respond() override;
public:
	void launch() override;
	Test_Server();
	~Test_Server();
};
}
#endif // !_Test_Server_

