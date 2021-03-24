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
	for (int i = 0; i < (usersVec.size()); i++)
	{
		if (usersVec[i]->getNome() == n)
		{
			return true;
		}
	}
	return false;
}

void System::listServers()
{

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

			/* cria um novo servidor e modifica o servidor que está 
			sendo visualizado para o que criamos */
			serverCurrent = serverCurrent->createServer(nomeServer);
			
			//Armazena o novo servidor no vector
			serversVec.push_back(serverCurrent);
			break;
		}
		else if (comando == "enterServer")
		{
			string nomeServer;
			cin >> nomeServer;
			
			serverCurrent->enterServer(nomeServer);
		}
		else if (comando == "listServers")
		{
			listServers();
		}
		
	}		
}