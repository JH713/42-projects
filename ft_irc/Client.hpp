#ifndef CLIENT_HPP
# define CLIENT_HPP

#include "Irc.hpp"

class Client {
private:
	int _clientSocket;

	std::string _nickname;
	std::string _hostname;
	std::string _username;
	std::string _realname;

	std::string _readBuf;

	bool _hasValidPassword; // 유효한 비밀번호를 가지고 있는지 
	bool _isNicknameRegistered; // 닉네임 등록됐는지  
	bool _isUserinfoRegistered; // 유저정보 등록됐는지  
	bool _isRegistered; // 최종 등록됐는지 
	bool _shouldBeDeleted; // 삭제되어야 하는지 

public:
	Client(int clientSocket);

	std::string getReadBuf() const;
	void setReadBuf(const std::string buf);
	void clearReadBuf();

	std::string getNickname() const;
	std::string getHostname() const;
	std::string getUsername() const;
	std::string getRealname() const;

	bool hasValidPassword() const;
	bool isNicknameRegistered() const;
	bool isUserinfoRegistered() const;
	bool isRegistered() const;
	bool shouldBeDeleted() const;

	void setNickname(const std::string nickname);
	void setHostname(const std::string hostname);
	void setUsername(const std::string username);
	void setRealname(const std::string realname);
	void setHasValidPassword(bool hasValidPassword);
	void setIsNicknameRegistered(bool isRegistered);
	void setIsUserinfoRegistered(bool isRegistered);
	void setIsRegistered(bool isRegistered);
	void setShouldBeDeleted(bool shouldBeDeleted);

	void sendMsg(std::string msg);
	bool isRegistrationRequired();
	void registration();

};

#endif 