#include "../Server.hpp"

void Server::pass(Client *client, Message *msg)
{
	if (msg->params.empty())
		client->sendMsg(ERR_NEEDMOREPARAMS(client->getNickname(), msg->command));

	std::string inputPwd = msg->params[0];

	if (client->isRegistered())
		client->sendMsg(ERR_ALREADYREGISTRED(client->getNickname()));
	
	if (inputPwd == _password)
		client->setHasValidPassword(true);
	else
	{
		client->sendMsg(ERR_PASSWDMISMATCH);
		client->setShouldBeDeleted(true);
	}
}

// void    pass(Client &client, Message *msg) {
// 	client.setConnectionPassword(true);
// 	if (client.getServer().getPassword() == pwd)
// 	{
// 		return ;
// 	}
// 	else
// 	{
// 		client.setCorrectPwd(false);
// 		client.sendMsg(client.getClientSocket(), ERR_PASSWDMISMATCH);
// 		close(client.getClientSocket()); //소켓 닫기 
// 		client.getServer().getClientsList().erase(client.getClientSocket()); //clientsList에서 해당 소켓 지우기
// 		client.getServer().getPollFDs()[client.getPollFDsIdx()].fd = -1; //pollFDs에서 fd 지우기
// 	}

// }