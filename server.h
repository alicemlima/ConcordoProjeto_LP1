#ifndef SERVER_H
#define SERVER_H

#include "channel.h"
#include <vector>

class Server
{
private:
	// O ID do usuário que criou o servidor
	int usuarioDonold = 0; 
	string nameServer,
	descript,
	invitCode; // Código necessário para se entrar no servidor
	// Lista de canais	que já estão no servidor
	std::vector<Channel> channels;
	// Lista de IDs de usuários que já estão no servidor
	std::vector<int> participantIDs;

public:
	Server();
	~Server();
	
	// Comando desconectar/sair do servidor
	void disconnect();
	// Comando criar servidor
	void createServer(string ns);
	// Mudar descrição do servidor
	void setServer_desc(string ns, string d);
	// Mudar o código de convite para o servidor
	void setServer_invite_code(string ns, string code);
	// Listar servidores
	void listServers();
	// Remover Servidor
	void removeServer(string ns);
	// Entrar em um servidor
	void enterServer(string ns);
};

#endif