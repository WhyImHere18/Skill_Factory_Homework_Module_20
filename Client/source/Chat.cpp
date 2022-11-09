#include "Chat.h"
#include "Client.h"

void Chat::createChat()
{
	Client& client = Client::Instance();
	isChatWorking_ = true;
}

bool Chat::isChatWorking()
{
	return isChatWorking_;
}

void Chat::closeChat()
{
	isChatWorking_ = false;
	close(Client::Instance().getSocket_file_descriptor());
}