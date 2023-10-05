#include "Client.hpp"

Client::Client(int clientSocket) : _clientSocket(clientSocket) {}

std::string Client::getReadBuf() const {return _readBuf; }

void Client::setReadBuf(const std::string buf) { _readBuf += buf; }

void Client::clearReadBuf() { _readBuf.clear(); }