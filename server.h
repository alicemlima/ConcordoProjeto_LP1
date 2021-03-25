#ifndef SERVER_H
#define SERVER_H

#include "channel.h"
// #include "user.h"
#include <vector>

class Server
{
private:
	// O ID do usuário que criou o servidor
	int usuarioDonoId; 
	string nameServer,
	descript,
	inviteCode; // Código necessário para se entrar no servidor
	// Vetor de canais que já estão no servidor
	std::vector<Channel> channels;
	// Vetor de IDs de usuários que já estão no servidor
	std::vector<int> participantIDs;

public:
	Server(string ns);
	~Server();
	
	int getUsuariodonoid();
	string getNameserver();
	void setNameserver(string ns);

	string getDescript();
	void setDescript(string dt);

	string getInvitecode();
	void setInvitecode(string in);

	void addUser(int id);
	void removeUser(int id);
	// int listParticipants();
};

#endif