#ifndef SYSTEM_H
#define SYSTEM_H

#include <map>
#include <vector>
#include "user.h"
#include "server.h"
#include "channel.h"

class System
{
private:
	// Vetores dos usuários e servidores que estão no sistema
	std::vector<string> usersVec;
	std::vector<string> serversVec;
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

	// Comando para sair do sistema
	bool quit(); // exibir a mensagem “Saindo do Concordo”
	// Comando para criar usuário
	bool createUser(string e, string s, string n); // Pode ser um booleano? Exibir “Usuário já existe!”, “Usuário criado”
	// Comando para entra/logar no sistema
	void login(string e, string s); // Exibir “Logado como julio.melo@imd.ufrn.br”, “Senha ou usuário inválidos!”
	bool searchUser(string e);
};

#endif