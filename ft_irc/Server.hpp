#ifndef SERVER_HPP
# define SERVER_HPP

#include "Irc.hpp"

class Server
{
private:
	int _port; // 포트 번호
	std::string _password; // 비밀번호 
	time_t _startTime; //서버 시작 시간 

	int _serverSocket; //서버 소켓 
	struct pollfd _pollFd[POLLFD_SIZE];


public:
	Server(int port, std::string password);
	~Server();

	void run();

	class ServerException : public std::exception 
	{
	private:
		char *msg;
	public:
		ServerException(char *msg) : msg(msg) {}
		const char *what() const throw() { return msg; }
	};
};

#endif