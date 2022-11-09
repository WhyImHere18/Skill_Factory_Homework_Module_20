#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>

#define MESSAGE_LENGTH 1024
#define PORT 49154

class Client
{
    int socket_file_descriptor, connection;
    struct sockaddr_in serveraddress, client;

    Client()
    {
        socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
        
        if (socket_file_descriptor == -1)
        {
            std::cout << "Socket creation is failed" << std::endl;
            exit(1);
        }

        serveraddress.sin_addr.s_addr = inet_addr("127.0.0.1");
        serveraddress.sin_port = htons(PORT);
        serveraddress.sin_family = AF_INET;
        
        connection = connect(socket_file_descriptor, (struct sockaddr*)&serveraddress, sizeof(serveraddress));

        if (connection == -1)
        {
            std::cout << "Connection with server is failed..." << std::endl;
            exit (1);
        }
    }

    ~Client()
    {
        close(socket_file_descriptor);
    }

    Client(Client const&) = delete;
    Client& operator=(Client const&) = delete;

public:

    static Client& Instance()
    {
        static Client client;
        return client;
    }

    int getSocket_file_descriptor() const
    {
        return socket_file_descriptor;
    }
};
