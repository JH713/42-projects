#include "Server.hpp"

Server::Server(int port, std::string password) :_port(port), _password(password)
{
	time(&_startTime);

	_serverSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (_serverSocket == -1)
		throw ServerException("Server socket creation failed!");
	
	struct sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(_port);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

	if (bind(_serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) 
	{
        close(_serverSocket); 
		throw ServerException("Binding failed!");
    }

	if (listen(_serverSocket, 5) == -1) 
	{
        close(_serverSocket);
		throw ServerException("Listening failed!");
    }

	fcntl(_serverSocket, F_SETFL, O_NONBLOCK);

	std::cout << "Process ID: " << getpid() << std::endl;

	_pollFd[0].fd = _serverSocket;
	_pollFd[0].events = POLLIN;
	_pollFd[0].revents = 0;

	for (int i = 1; i < POLLFD_SIZE; i++)
		_pollFd[i].fd = -1;

}

Server::~Server() {}

void Server::run()
{
	
}