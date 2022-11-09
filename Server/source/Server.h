#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

#define MESSAGE_LENGTH 1024
#define PORT 49154

class Server
{
private:
    struct sockaddr_in serveraddress, client;
    socklen_t length;
    int socket_file_descriptor, connection, bind_status, connection_status;

    Server()
    {
        socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
        
        if (socket_file_descriptor == -1)
        {
            std::cout << "Socket creation is failed" << std::endl;
            exit(1);
        }

        serveraddress.sin_addr.s_addr = htonl(INADDR_ANY);
        serveraddress.sin_port = htons(PORT);
        serveraddress.sin_family = AF_INET;
        bind_status = bind(socket_file_descriptor, (struct sockaddr*)& serveraddress, sizeof(serveraddress));
        
        if (bind_status == -1)
        {
            std::cout << "socket binding is failed!" << std::endl;
            exit (1);
        }
        
        connection_status = listen(socket_file_descriptor, 5);
        if (connection_status == -1)
        {
            std::cout << "server is unable to listen to new connections!" << std::endl;
            exit (1);
        } else{
            std::cout << "server is listening to new connections..." << std::endl;
        }

        length = sizeof(client);

        connection = accept(socket_file_descriptor, (struct sockaddr*)& client, &length);
        if (connection == -1)
        {
            std::cout << "server is unable to accept the data from client" << std::endl;
            exit (1);
        }
    }

    ~Server()
    {
        close(socket_file_descriptor);
    }

    Server(Server const&) = delete;
    Server& operator=(Server const&) = delete;


public:
    static Server& Instance()
    {
        static Server server;
        return server;
    }

    int getSocket_file_descriptor() const
    {
        return socket_file_descriptor;
    }

    int getConnection() const
    {
        return connection;
    }

};