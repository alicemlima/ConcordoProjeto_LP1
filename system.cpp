#include "system.h"

System::System()
{
	cout << "Olá!! Seja bem vindo(a) ao Concordo." << endl;
	this->userCurrent = NULL;
	this->serverCurrent = NULL;
	this->channelCurrent = NULL;
	// init();
}

void System::init()
{
	string comando, e, s, n;
	cout << "Digite o comando desejado: ";
	cin >> comando;

	if (comando == "createUser")
	{
		cin >> e >> s >> n;
		createUser(e, s, n);
	}
	else if (comando == "login")
	{
		cin >> e >> s;
		login(e, s);
	}
	else if (comando == "quit")
	{
		cin >> n;
		quit(n);
	}
}

// Ainda falta implementar um forma de fechar o sistema
void System::quit(string n)
{
	for (int i = 0; i < (usersVec.size()); i++)
	{
		if (usersVec[i]->getNome() == n)
		{
			usersVec[i]->setLogado(true);
			break;
		}
	}
	cout << "Saindo do Concordo!";
}

bool System::createUser(string e, string s, string n)
{
	if (searchUser(n) == true)
	{
		// Não pode existir dois usuário com o mesmo nome ou emails
		cout << "Usuário já cadastrado!" << endl;
		return false;
	}
	else
	{
		User* newUser = new User(e, s, n);
		usersVec.push_back(newUser);
		login_senha.insert(pair<string,string>(e, s));
		newUser->setId(usersVec.size());
		cout << "Usuário criado!" <<  endl;
	}
	return true;
}

void System::login(string e, string s)
{
	for (auto itr:login_senha)
	{
		if (itr.first == e && itr.second == s)
		{
			for (int i = 0; i < (usersVec.size()); i++)
			{
				if (usersVec[i]->getEmail() == e)
				{
					usersVec[i]->setLogado(true);
					userCurrent = usersVec[i];
					User::userLog = userCurrent;
					cout << "Logado como " << userCurrent->getNome() << "!" << endl;
					logado();
					break; // É necessário esse "break?"
				}				
			}
			break;
		}
		else if (itr.first != e || itr.second != s)
		{
			cout << "Senha ou usuário inválidos!!" << endl;
			break;
		}
	}
}

bool System::searchUser(string n)
{
	for (auto itr:usersVec)
	{
		if (itr->getNome() == n)
		{
			return true;
		}
	}
	return false;
}

void System::logado()
{
	while (userCurrent->getLogado() == true)
	{
		string comando = " ";
		cout << "Digite o comando desejado: ";
		cin >> comando;
		
		if (comando == "createServer")
		{
			string nomeServer;
			cin >> nomeServer;

			createServer(nomeServer);
			break;
		}
		else if (comando == "enterServer")
		{
			string nomeServer;
			cin >> nomeServer;
			
			enterServer(nomeServer);
		}
		else if (comando == "listServers")
		{
			listServers();
		}
		else if (comando == "disconnect")
		{
			disconnect();
		}		
	}		
}


 void System::disconnect()
{
	cout << User::userLog->getNome();
    User::userLog = NULL;
	cout << "Saindo do Concordo!";
	userCurrent->setLogado(false);
}

/* cria um novo servidor, adiciona o novo servidor no vector
 e modifica o servidor que está sendo visualizado para o que criamos */
void System::createServer(string ns)
{
	if (searchServer(ns) == NULL)
	{
		Server* newServer = new Server(ns);
		serversVec.push_back(newServer);
		serverCurrent = newServer;
	}
	else
	{
		cout << "Servidor com esse nome já existe!" << endl;
	}
}

void System::enterServer(string ns)
{
	if (searchServer(ns)->getNameserver() == ns)
	{
		Server* aux = searchServer(ns);
		if (aux->getInvitecode() == "")
		{
			aux->addUser(userCurrent->getId());
			serverCurrent = aux;
			cout << "Entrou no servidor com sucesso!" << endl;
		}
		else if (aux->getUsuariodonoid() == User::userLog->getId())
		{
			serverCurrent = aux;
			cout << "Entrou no servidor com sucesso!" << endl;
		}
		else
		{
			cout << "Servidor requer código de convite!" << endl;
		}
	}
	else
	{
		cout << "O sevidor \'" << ns << "\' não existe!" << endl;
	}
}

void System::enterServer(string ns, string code)
{
	if (searchServer(ns)->getNameserver() == ns)
	{
		Server* aux = searchServer(ns);
		if (aux->getInvitecode() == code)
		{
			aux->addUser(userCurrent->getId());
			serverCurrent = aux;
			cout << "Entrou no servidor com sucesso!" << endl;
		}
		else
		{
			cout << "Código incorreto!" << endl;
		}
	}
	else
	{
		cout << "Sevidor \'" << ns << "\' não existe!" << endl;
	}
}

// Verifica se um servidor existe
// caso exista retorna o vetor, caso contrário retorna NULL
Server* System::searchServer(string ns)
{
	if (serversVec.empty())
	{
		return 	NULL;
	}
	else
	{
	for (auto itr:serversVec)
	{
		if (itr->getNameserver() == ns)
		{
			return itr;
		}
	}
	}
	return 	NULL;
}

void System::setServer_desc(string ns, string d)
{
	if (searchServer(ns)->getNameserver() == ns)
	{
		Server* aux = searchServer(ns);
		if (aux->getUsuariodonoid() == userCurrent->getId())
		{
			aux->setDescript(d);
			cout << "Descrição do servidor \'" << ns << "\'  modificada!" << endl;
		}
		else
		{
			cout << "Você não pode alterar a descrição de um servidor que não foi criado por você" << endl;
		}
	}
	else
	{
		cout << "Sevidor \'" << ns << "\' não existe!" << endl;
	}
}

void System::setServer_invite_code(string ns, string code)
{
	if (searchServer(ns)->getNameserver() == ns)
	{
		Server* aux = searchServer(ns);
		if (aux->getUsuariodonoid() == userCurrent->getId())
		{
			aux->setInvitecode(code);
			cout << "Código de convite do servidor \'" << ns << "\' modificado!" << endl;
		}
		else
		{
			cout << "Você não pode alterar o código de convite de um servidor que não foi criado por você" << endl;
		}
	}
	else
	{
		cout << "Sevidor \'" << ns << "\' não existe!" << endl;
	}
}

void System::setServer_invite_code(string ns)
{
	if (searchServer(ns)->getNameserver() == ns)
	{
		Server* aux = searchServer(ns);
		if (aux->getUsuariodonoid() == userCurrent->getId())
		{
			aux->setInvitecode("");
			cout << "Código de convite do servidor \'" << ns << "\' removido!" << endl;
		}
		else
		{
			cout << "Você não pode alterar o código de convite de um servidor que não foi criado por você" << endl;
		}
	}
	else
	{
		cout << "Sevidor \'" << ns << "\' não existe!" << endl;
	}
}

void System::listServers()
{
	if (serversVec.empty())
	{
		cout << "\n Você não possui servidores disponíveis" << endl;
	}
	else
	{
		for (auto itr:serversVec)
		{
			cout << itr->getNameserver() << endl;
			cout << itr->getDescript() << endl;
			if (itr->getInvitecode() != "")
			{
				cout << "Servidor aberto" << endl;
			}
			else
			{
				cout << "Servidor fechado" << endl;
			}
			cout << "\n";
		}
	}
}

void System::removeServer(string ns)
{
	if (searchServer(ns)->getNameserver() == ns)
	{
		Server* aux = searchServer(ns);
		if (aux->getUsuariodonoid() == userCurrent->getId())
		{
			for (int i = 0; i < (usersVec.size()); i++)
			{
				if (serversVec[i]->getNameserver() == ns)
				{
					serversVec.erase(serversVec.begin() + i);
					cout << "Servidor \'" << ns << "\' removido!" << endl;
				}
			}
		}
		else
		{
			cout << "Você não é o dono do servidor \'" << ns << "\'!" << endl;
		}
	}
	else
	{
		cout << "Sevidor \'" << ns << "\' não existe!" << endl;
	}	
}

// Esses comandos não serão necessário (adicionar os argumentos no loop0
void System::leaveServer()
{
	serverCurrent->removeUser(User::userLog->getId());
	serverCurrent = NULL;
}

// void System::listUsers()
// {
// 	serverCurrent->
// }