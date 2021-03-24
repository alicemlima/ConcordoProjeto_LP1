#ifndef SYSTEM_H
#define SYSTEM_H

#include <map>
#include <vector>
#include "user.h"
#include "server.h"
#include "channel.h"

using namespace std;

class System
{
private:
	// Vetores dos usuários que estão no sistema
	std::vector<User*> usersVec;
	std::vector<Server*> serversVec;
	// Mapa/Dicionário para gurdar e associar emails e senhas
	std::map<string, string> login_senha;
	// O usuário atualmente logado no sistema 
	User* userCurrent;
	// O servidor que o usuário está visualizando no momento
	Server* serverCurrent;
	// O Canal que o usuário está visualizando no momento
	Channel* channelCurrent;
public:
	System();
	~System();

	// Comando para entrar do sistema
	void init();
	// Comando para sair do sistema
	void quit(string n); // exibir a mensagem “Saindo do Concordo”
	// Comando para criar usuário
	bool createUser(string e, string s, string n);
	// Comando para entra/logar no sistema
	void login(string e, string s);
	bool searchUser(string e);
	void logado();
	// Listar servidores
	void listServers();
};

#endif