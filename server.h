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
	
	string getNameserver();
	void setNameserver(string ns);

	string getDescript();
	void setDescript(string dt);

	string getInvitecode();
	void setInvitecode(string in);

	// Comando desconectar/sair do servidor
	void disconnect();
	// Comando criar servidor
	// retorna um servidor para ser armazenado no sistema
	Server* createServer(string ns);
	// Mudar descrição do servidor
	void setServer_desc(string ns, string d);
	// Mudar o código de convite para o servidor
	void setServer_invite_code(string ns, string code);
	// Remover Servidor
	void removeServer(string ns);
	// Entrar em um servidor
	void enterServer(string ns);

	// Server returnServer(string ns);
};

#endif