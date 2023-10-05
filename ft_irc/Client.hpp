#ifndef CLIENT_HPP
# define CLIENT_HPP

#include "Irc.hpp"

class Client {
private:
	int _clientSocket;

	std::string _nickname;
	std::string _hostname;
	std::string _username;

	std::string _readBuf;

public:
	Client(int clientSocket);

	std::string getReadBuf() const;
	void setReadBuf(const std::string buf);
	void clearReadBuf();

};

#endif 