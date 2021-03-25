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

	// Comandos do sistema - assim que entrar no sistema
	// Comando para entrar do sistema
	void init();
	// Comando para sair do sistema
	void quit(string n);
	// Comando para criar usuário
	bool createUser(string e, string s, string n);
	// Comando para entra/logar no sistema
	void login(string e, string s);
	// Verifica se um usuário existe
	bool searchUser(string e);
	// Inicia o loop para comando quando o usuário está logado
	void logado();

	// Comandos dos servidores - se estiver logado
	// Listar servidores
	void listServers();
	// Comando desconectar/sair do servidor
	void disconnect();
	// Comando criar servidor
	// retorna um servidor para ser armazenado no sistema
	void createServer(string ns);
	// Mudar descrição do servidor
	void setServer_desc(string ns, string d);
	// Mudar o código de convite para o servidor
	void setServer_invite_code(string ns, string code);
	void setServer_invite_code(string ns);
	// Remover Servidor
	void removeServer(string ns);
	// Entrar em um servidor
	void enterServer(string ns);
	void enterServer(string nd, string code);
	// Sair de um serividor
	void leaveServer();
	// Listar pessoas no servidor 
	void listUsers();
	// Verifica se um servidor existe
	Server* searchServer(string ns);
};

#endif