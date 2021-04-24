#ifndef SYSTEM_H
#define SYSTEM_H

#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include "server.h"

using namespace std;

class System
{
private:
	// Sinaliza se o servidor está funcionando ou não
	bool on;
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
	void salvarUsuario();
	void salvarServidores();
	// Arquivo para salvar informações do servidor
	ofstream servidores;
	ofstream usuarios;
public:
	System();
	~System();
	static System* concor;
	void setOn();
	bool getOn();
	void init();
	void quit();
	bool createUser(string e, string s, string n);
	bool login(string e, string s);
	bool searchUser(string e);
	void logado();
	void listServers();
	void disconnect();
	void createServer(string ns);
	void enterServer(string ns);
	void enterServer(string nd, string code);
	Server* searchServer(string ns);
	void setServer_desc(string ns, string d);
	void setServer_invite_code(string ns, string code);
	void setServer_invite_code(string ns);
	void removeServer(string ns);
	// void leaveServer();
	void listUsers();
	void salvar();
};

#endif