#include "system.h"

System::System()
{
	cout << "\nOlá!! Seja bem vindo(a) ao Concordo." << endl;
	this->userCurrent = NULL;
	this->serverCurrent = NULL;
	this->channelCurrent = NULL;
	this->on = true;
}

void System::setOn()
{
	on = false;
}

bool System::getOn()
{
	return on;
}

void System::init()
{
	string e, s, n, comando;
	cin >> comando;
	
	if (comando == "createUser")
	{
		cout << "Digite o email, a senha e o nome: ";
		cin >> e >> s >> n;
		createUser(e, s, n);
	}
	else if (comando == "login")
	{
		cout << "Digite o email e a senha: ";
		cin >> e >> s;

		if (login(e, s) == true)
		{
			string comando_2;
			do
			{
				logado();
			} while (userCurrent->getLogado() == true);
		}
		else
		{
			cout << "Tente novamente" << endl;
		}
	}
	else if (comando == "quit")
	{
		quit();
	}
}

void System::quit()
{
	cout << "\nSaindo do Concordo!" << endl;
	setOn();
}

bool System::createUser(string e, string s, string n)
{
	if (searchUser(n) == true)
	{
		// Não pode existir dois usuário com o mesmo nome ou email
		cout << "\nUsuário já cadastrado \'" << n << "\'!" << endl;
		return false;
	}
	else
	{
		User* newUser = new User(e, s, n);
		usersVec.push_back(newUser);
		login_senha.insert(pair<string,string>(e, s));
		newUser->setId(usersVec.size());
		cout << "\nUsuário \'" << n << "\' criado!" <<  endl;
	}
	return true;
}

bool System::login(string e, string s)
{
	for (auto itr:login_senha)
	{
		if (itr.first == e && itr.second == s)
		{
			int aux_vec = usersVec.size();
			for (int i = 0; i < aux_vec; i++)
			{
				if (usersVec[i]->getEmail() == e)
				{
					usersVec[i]->setLogado(true);
					userCurrent = usersVec[i];
					User::userLog = userCurrent;
					cout << "\n Logado como " << userCurrent->getNome() << "!" << endl;
					return true;
				}				
			}
		}
	}
	cout << "\nSenha ou usuário inválidos!!" << endl;
	return false;
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
	string comando_2;
	cin >> comando_2;

	if (comando_2 == "createServer")
	{
		string nomeServer;
		cin >> nomeServer;
		createServer(nomeServer);
	}
	else if (comando_2 == "enterServer")
	{
		string nomeServer, code;
		cin >> nomeServer >> code;
		
		enterServer(nomeServer, code);
	}
	else if (comando_2 == "listServers")
	{
		listServers();
	}
	else if (comando_2 == "disconnect")
	{
		disconnect();
	}
	else if (comando_2 == "setServer_desc")
	{
		string nomeServer, desc;
		cin >> nomeServer >> desc;

		setServer_desc(nomeServer, desc);
	}
	else if (comando_2 == "setServer_invite_code")
	{
		string nomeServer, code;
		cin >> nomeServer >> code;

		setServer_invite_code(nomeServer, code);
	}
	else if (comando_2 == "removeServer")
	{
		string nomeServer;
		cin >> nomeServer;

		removeServer(nomeServer);
	}
	else if (comando_2 == "leaveServer")
	{
		leaveServer();
	}
	else if (comando_2 == "listUsers")
	{
		listUsers();
	}
}

 void System::disconnect()
{
	cout << "Saindo do Concordo!" << endl;
    User::userLog = NULL;
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
		
		cout << "\nServidor \'" << ns << "\' criado com sucesso!" << endl;
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
			cout << "Descrição do servidor \'" << ns << "\' modificada!" << endl;
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

// Lista servidores - retorna o nome do servido, a descrição e se é aberto ou fechado
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
			if (itr->getInvitecode() == "")
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
			int aux_vec = usersVec.size();
			for (int i = 0; i < aux_vec; i++)
			{
				if (serversVec[i]->getNameserver() == ns)
				{
					serversVec.erase(serversVec.begin() + i);
					cout << "Servidor \'" << ns << "\' removido!" << endl;
					break;
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

void System::leaveServer()
{
	cout << "\nSaindo do servidor \'" << serverCurrent->getNameserver() << "\'!" << endl;
	serverCurrent->removeUser(User::userLog->getId());
	serverCurrent = NULL;
}

void System::listUsers()
{
	std::vector <int> aux_vec;
	aux_vec = serverCurrent->listParticipants();
	for (auto itr:aux_vec)
	{
		for (auto itr_2:usersVec)
		{
			if (itr == itr_2->getId())
			{
				cout << itr_2->getNome() << endl;
			}
		}
	}
}