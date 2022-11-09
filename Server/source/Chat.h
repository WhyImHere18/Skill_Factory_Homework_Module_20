#pragma once

class Chat
{
	bool isChatWorking_ = false;

public:
	void createChat();
	void closeChat();
	bool isChatWorking();
};

