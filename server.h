#ifndef SERVER_H
#define SERVER_H

#include "channel.h"

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
	std::vector<Channel*> channels;
	// Vetor de IDs de usuários que já estão no servidor
	std::vector<int> participantIDs;

public:
	Server(string ns);
	~Server();
	
	// Retorna o ID do usuário dono do servidor
	// O usuário dono só é alteradorado na sua criação, não necessitando de uma função set
	int getUsuariodonoid();

	//Métodos getter e setter dos atributos da classe Server
	string getNameserver();
	void setNameserver(string ns);

	string getDescript();
	void setDescript(string dt);

	string getInvitecode();
	void setInvitecode(string in);

	void addUser(int id);
	void removeUser(int id);

	// Retorna o vector participantIDs para serem chamadados e listados no arquivo system.cpp
	std::vector <int> listParticipants();

	// Comando dos Canais
	// Pocurar canais - se existir = true e se não existir = false
	bool searchChannel(string nc);

	// Criar canais - parâmetros: nome e tipo
	void createChannel(string nc, string tp);

	//Listar Canais do servidor
	void listChannel();

	// Entra em um canal do servidor
	void enterChannel(string nc);

	// Sair de um canal do servidor
	void leaveChannel();

	// Comandos gestão de mensagens
	void sendMessage(string ms);

	void listMessages();

	void initServer();
};

#endif