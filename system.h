#ifndef SYSTEM_H
#define SYSTEM_H
#include "user.h"

class System
{
private:
	/* Lista de IDs dos usuários e servidores
	 que estão no servidor */
	string users[],
	servidores[];	
public:
	System();
	~System();
	// Comando para sair do sistema
	void quit(); // exibir a mensagem “Saindo do Concordo”
	// Comando para criar usuário
	void createUser(string e, string s, string n); // Pode ser um booleano? Exibir “Usuário já existe!”, “Usuário criado”
	// Comando para entra/logar no sistema
	void login(string e, string s); // Exibir “Logado como julio.melo@imd.ufrn.br”, “Senha ou usuário inválidos!”
};

#endif