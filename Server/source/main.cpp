#include "Chat.h"
#include "Server.h"

#define MESSAGE_LENGTH 1024

int main()
{
	Chat chat;

	chat.createChat();

	Server& s = Server::Instance();
	char message[MESSAGE_LENGTH];
	
    while(chat.isChatWorking())
    {
        bzero(message, MESSAGE_LENGTH);
        read(s.getConnection(), message, sizeof(message));
        if (strncmp("end", message, 3) == 0)
        {
            std::cout << "client is gone..." << std::endl;
            std::cout << "server is exiting!" << std::endl;
            chat.closeChat();
            continue;
        }
        std::cout << std::endl;
        std::cout << "message received from client: " << std::endl << message << std::endl;
        bzero(message, MESSAGE_LENGTH);
        std::cout << std::endl;
        std::cout << "enter a message you want to send to the client: " << std::endl;
        std::cin >> message;
        ssize_t bytes = write(s.getConnection(), message, sizeof(message));
        if (bytes >= 0)
        {
            std::cout << std::endl;
            std::cout << "message is sent successfully to the client!" << std::endl;
		}
	}

    return 0;
    
}