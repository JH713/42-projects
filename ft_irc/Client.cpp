#include "Client.hpp"

Client::Client(int clientSocket) : _clientSocket(clientSocket) 
{
	_nickname = "*";
	_hasValidPassword = false; 
	_isRegistered = false;
}

// readBuf 관련 함수 
std::string Client::getReadBuf() const {return _readBuf; }
void Client::setReadBuf(const std::string buf) { _readBuf += buf; }
void Client::clearReadBuf() { _readBuf.clear(); }

// getter
std::string Client::getNickname() const { return _nickname; }
std::string Client::getHostname() const { return _hostname; }
std::string Client::getUsername() const { return _username; }
std::string Client::getRealname() const { return _realname; }

bool Client::hasValidPassword() const { return _hasValidPassword; }
bool Client::isNicknameRegistered() const { return _isNicknameRegistered; }
bool Client::isUserinfoRegistered() const { return _isUserinfoRegistered; }
bool Client::isRegistered() const { return _isRegistered; }
bool Client::shouldBeDeleted() const { return _shouldBeDeleted; }

// setter
void Client::setNickname(const std::string nickname) { _nickname = nickname; }
void Client::setHostname(const std::string hostname) { _hostname = hostname; }
void Client::setUsername(const std::string username) { _username = username; }
void Client::setRealname(const std::string realname) { _username = realname; }
void Client::setHasValidPassword(bool hasValidPassword) { _hasValidPassword = hasValidPassword; }
void Client::setIsNicknameRegistered(bool isRegistered) { _isNicknameRegistered = isRegistered; }
void Client::setIsUserinfoRegistered(bool isRegistered) { _isUserinfoRegistered = isRegistered; }
void Client::setIsRegistered(bool isRegistered) { _isRegistered = isRegistered; }
void Client::setShouldBeDeleted(bool shouldBeDeleted) { _shouldBeDeleted = shouldBeDeleted; }

// 클라이언트한테 메시지 보내기 
void Client::sendMsg(std::string msg)
{
	if (send(_clientSocket, msg.c_str(), msg.length(), 0) < 0)
		perror("send failed");
	std::cout << "========== send client " << _clientSocket << " ==========\n";
	std::cout << msg << "\n\n";
}

// 등록 과정 필요한지 알려줌 
bool Client::isRegistrationRequired()
{
	if (!_isRegistered && _isNicknameRegistered && _isUserinfoRegistered)
		return (true);
	return (false);
}