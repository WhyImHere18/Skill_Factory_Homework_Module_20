#include "Chat.h"
#include "Server.h"

void Chat::createChat()
{
	Server& server = Server::Instance();
	isChatWorking_ = true;
}

bool Chat::isChatWorking()
{
	return isChatWorking_;
}

void Chat::closeChat()
{
	isChatWorking_ = false;
	close(Server::Instance().getSocket_file_descriptor());
}