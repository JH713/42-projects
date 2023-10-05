#include "Server.hpp"

// 생성자에서 서버 소켓을 생성하고 bind, listen 함, pollfd 초기화
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

// 클라이언트 이벤트를 기다리고 처리 
void Server::run()
{
	while (1)
	{
		int result = poll(_pollFd, POLLFD_SIZE, -1);
		
		if (result > 0)
		{
			for (int i = 0; i < POLLFD_SIZE; i++)
			{
				if (_pollFd[i].fd != -1 && _pollFd[i].revents == POLLIN)
				{
					if (i == 0)
						addClient();
					else
						handleReceivedData(i);
				}
			}
		}
	}
}

//클라이언트 소켓 추가 
void Server::addClient()
{
	struct sockaddr_in clientAddr;
	socklen_t addrLen;

	int clientSocket = accept(_serverSocket, (struct sockaddr *)&clientAddr, &addrLen);
	if (clientSocket == -1)
		throw ServerException("accept failed");
	fcntl(clientSocket, F_SETFL, O_NONBLOCK);
	std::cout << "클라이언트 SOCKET FD: " << clientSocket << "\n";
	
	Client client(clientSocket);
	_clientList.insert(std::pair<int, Client *>(clientSocket, &client));
	
	for (int i = 1; i < POLLFD_SIZE; i++)
	{
		if (_pollFd[i].fd == -1)
		{
			_pollFd[i].fd = clientSocket;
			_pollFd[i].events = POLLIN;
			_pollFd[i].revents = 0;
			std::cout << "connection successful\n";
			break;
		}
	}
}

// 클라이언트로부터 데이터 받아서 처리 
void Server::handleReceivedData(int pollIdx)
{
	std::cout << "클라이언트 이벤트 발생!!\n";
	
	char buf[1024];
	ssize_t bytesReceived = recv(_pollFd[pollIdx].fd, buf, sizeof(buf) - 1, 0);
	if (bytesReceived <= 0) // 연결 종료 혹은 오류 발생 
	{
		close(_pollFd[pollIdx].fd);
		_pollFd[pollIdx].fd = -1;
		_clientList.erase(_pollFd[pollIdx].fd);
	}
	else
	{
		buf[bytesReceived] = '\0';
		Client *currClient = _clientList[_pollFd[pollIdx].fd]; 
		currClient->setReadBuf(buf);

		if (currClient->getReadBuf().find(END_CHARACTERS) != std::string::npos)
		{
			processBuffer(currClient);
			currClient->clearReadBuf();
		}
	}

}

// 버퍼에 저장된 데이터 처리 
void Server::processBuffer(Client *client)
{
	std::string buf = client->getReadBuf();
	if (buf.find_first_of(VALID_CHARACTERS) == std::string::npos)
		return ;
	std::cout << "BUF = " << buf << "\n";

	char *token = strtok(const_cast<char *>(buf.c_str()), END_CHARACTERS);
	if (token == NULL)
		return ;
	std::cout << "token = " << token << "\n";
	while (token != NULL)
	{
		std::string command(token);
		Message msg = parseMessage(token);
		printMessage(msg);
		executeCmd(&msg);
		token = strtok(NULL, END_CHARACTERS);
	}
}

void Server::executeCmd(Message *msg)
{

}