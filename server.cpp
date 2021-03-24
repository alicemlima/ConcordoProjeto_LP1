#include "server.h"

Server::Server(string ns)
{
    this->nameServer = ns;
    this->descript = "Adione uma descrição";
    this->usuarioDonoId = User::userLog->getId();
}

string Server::getNameserver()
{
    return nameServer;
}
void Server::setNameserver(string ns)
{
    nameServer = ns; 
}

string Server::getDescript()
{
    return descript;
}
void Server::setDescript(string dt)
{
    descript = dt;
}

string Server::getInvitecode()
{
    return inviteCode;
}
void Server::setInvitecode(string in)
{
    inviteCode = in;
}

void Server::disconnect()
{
	cout << User::userLog->getNome();
    User::userLog = NULL;
	cout << "Saindo do Concordo!";    
}

Server* Server::createServer(string ns)
{
    Server* newServer = new Server(ns);
    return newServer;
}

void Server::enterServer(string ns)
{

}

// Server Server::returnServer(string ns)
// {

// }