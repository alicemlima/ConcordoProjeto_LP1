#include "system.h"

System::System()
{
	cout << "\nOlá!! Seja bem vindo(a) ao Concordo." << endl;
	this->userCurrent =  User::userLog;
	this->serverCurrent = Server::serverLog;
	this->channelCurrent = Channel::channelLog;
	this->on = true;
}

// Muda o estado do servidor para não funcionando
void System::setOn()
{
	on = false;
}
// Sinaliza se o servidor está funcionando ou não
bool System::getOn()
{
	return on;
}

// Comandos do sistema - assim que entrar no sistema
	
// Comando para entrar do sistema
// Espécie de menu que sinaliza opções
void System::init()
{
	cout << "\n ############## CONCORDO - LOGIN ##############" << endl;
	cout << " - createUser \n - login \n - quit" << endl;
	cout << "\nDigite o comando desejado: \n"<< endl;
	string e, s, n, comando;
	cin >> comando;
	if (comando == "createUser")
	{
		cout << "Digite o email, a senha e o nome: " << endl;
		cin >> e >> s >> n;
		createUser(e, s, n);
	}
	else if (comando == "login")
	{
		cout << "Digite o email e a senha: " << endl;
		cin >> e >> s;

		if (login(e, s) == true)
		{
			do
			{
				logado();
			} while (userCurrent->getLogado() == true);
		}
		else
		{
			cout << "Tente novamente." << endl;
		}
	}
	else if (comando == "quit")
	{
		quit();
	}
}

// Comando para sair do sistema
// Chama a função setOn para fechar o sistema
void System::quit()
{
	cout << "-> Saindo do Concordo!" << endl;
	setOn();
}

// Comando para criar usuário, caso ele não exista, retorna true
// Adiciona o novo usuário no vector usersVec, adiciona o par login senha no dicionário
// muda o ID do usuário
// Caso contrário, retorna falso
bool System::createUser(string e, string s, string n)
{
	if (searchUser(n) == true)
	{
		// Não pode existir dois usuário com o mesmo nome ou email
		cout << "Usuário já cadastrado \'" << n << "\'!" << endl;
		return false;
	}
	else
	{
		User* newUser = new User(e, s, n);
		usersVec.push_back(newUser);
		login_senha.insert(pair<string,string>(e, s));
		newUser->setId(usersVec.size());
		cout << "\n-> Usuário \'" << n << "\' criado!" <<  endl;
	}
	return true;
}

// Comando para entrar/logar no sistema
// Verifica se dados informados estão corretos
// Em caso positivo, muda o usuário para logado = true
// o usuário atual e a variável global para o que foi informado e retorna true
// Caso contrário, retorna falso
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
					cout << "\n-> Logado como " << userCurrent->getNome() << "!" << endl;
					return true;
				}				
			}
		}
	}
	cout << "\nSenha ou usuário inválidos!" << endl;
	return false;
}

// Verifica se um usuário existe, caso positivo retorna true
// Caso negativo, retorna falso
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

// Inicia o loop para comando quando o usuário está logado
void System::logado()
{	string comando_2;
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
		
		enterServer(nomeServer);
	}
	else if (comando_2 == "listServers")
	{
		listServers();
	}
	else if (comando_2 == "disconnect")
	{
		disconnect();
	}
	else if (comando_2 == "removeServer")
	{
		string nomeServer;
		cin >> nomeServer;

		removeServer(nomeServer);
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
	else if (comando_2 == "listUsers")
	{
		listUsers();
	}
	else if (comando_2 ==  "salvar")
	{
		salvar();
	}
}

// Comandos dos servidores - se estiver logado

// Listar servidores
// Lista servidores - retorna o nome do servido, a descrição e se é aberto ou fechado
void System::listServers()
{
	if (serversVec.empty())
	{
		cout << "Você não possui servidores disponíveis" << endl;
	}
	else
	{
		cout << "\n############## SEUS SERVIDORES ##############\n" << endl;
		for (auto itr:serversVec)
		{
			cout << "-> " << itr->getNameserver() << endl;
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

// Comando desconectar/sair do servidor
void System::disconnect()
{
	cout << "\n-> " << userCurrent->getNome() << " saiu!" << endl;
    User::userLog = NULL;
	userCurrent->setLogado(false);
}

// Comando criar servidor
/* cria um novo servidor, adiciona o novo servidor no vector
 e modifica o servidor que está sendo visualizado para o que criamos */
void System::createServer(string ns)
{
	if (searchServer(ns) == NULL)
	{
		Server* newServer = new Server(ns);
		serversVec.push_back(newServer);
		serverCurrent = newServer;
		
		cout << "\n-> Servidor \'" << ns << "\' criado com sucesso!" << endl;
	}
	else
	{
		cout << "\nServidor com esse nome já existe!" << endl;
	}
}

// Comando entrar em um servidor
void System::enterServer(string ns)
{
	if (searchServer(ns)->getNameserver() == ns)
	{
		Server* aux = searchServer(ns);
		if (aux->getInvitecode() == "")
		{
			aux->addUser(userCurrent->getId());
			serverCurrent = aux;
			Server::serverLog = aux;
			cout << "-> Entrou no servidor \'" << serverCurrent->getNameserver() << "\' com sucesso!" << endl;
			while (Server::serverLog != NULL)
			{
				serverCurrent->initServer();
			}
			cout << serverCurrent->getNameserver() << endl;
			serverCurrent->removeUser(User::userLog->getId());
			serverCurrent = NULL;
			init();
			
		}
		else if (aux->getUsuariodonoid() == User::userLog->getId())
		{
			serverCurrent = aux;
			Server::serverLog = aux;
			cout << "-> Entrou no servidor \'" << serverCurrent->getNameserver() << "\' com sucesso!" << endl;
			do
			{
				serverCurrent->initServer();
			} while (Server::serverLog->getNameserver() == ns);
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

// Entrar em um servidor - sobrecarga de operadores
void System::enterServer(string ns, string code)
{
	if (searchServer(ns)->getNameserver() == ns)
	{
		Server* aux = searchServer(ns);
		if (aux->getInvitecode() == code)
		{
			aux->addUser(userCurrent->getId());
			serverCurrent = aux;
			cout << "-> Entrou no servidor \'" << serverCurrent->getNameserver() << "\' com sucesso!" << endl;
			do
			{
				serverCurrent->initServer();
			} while (serverCurrent->getNameserver() == ns);
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
			cout << "-> Descrição do servidor \'" << ns << "\' modificada!" << endl;
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

// Mudar o código de convite para o servidor
void System::setServer_invite_code(string ns, string code)
{
	if (searchServer(ns)->getNameserver() == ns)
	{
		Server* aux = searchServer(ns);
		if (aux->getUsuariodonoid() == userCurrent->getId())
		{
			aux->setInvitecode(code);
			cout << "-> Código de convite do servidor \'" << ns << "\' modificado!" << endl;
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

// Mudar o código de convite para o servidor - com sobrecarga de operadores
void System::setServer_invite_code(string ns)
{
	if (searchServer(ns)->getNameserver() == ns)
	{
		Server* aux = searchServer(ns);
		if (aux->getUsuariodonoid() == userCurrent->getId())
		{
			aux->setInvitecode("");
			cout << "-> Código de convite do servidor \'" << ns << "\' removido!" << endl;
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

// Remover Servidor
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
					cout << "-> Servidor \'" << ns << "\' removido!" << endl;
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

// Sair de um serividor
// void System::leaveServer()
// {
// 	cout << "-> Saindo do servidor \'" << serverCurrent->getNameserver() << "\'!" << endl;
// 	serverCurrent->removeUser(User::userLog->getId());
// 	serverCurrent = NULL;
// }

// Listar pessoas no servidor 
void System::listUsers()
{
	std::vector <int> aux_vec;
	aux_vec = serverCurrent->getParticipants();
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

// Salva as informações do usuário
void System::salvarUsuario()
{
	usuarios.open("usuarios.txt", ios::app);
	usuarios << usersVec.size();
	for (auto itr:usersVec)
	{
		usuarios << itr->getId() << endl;
		usuarios << itr->getNome() << endl;
		usuarios << itr->getEmail() << endl;
		usuarios << itr->getSenha() << endl;
	}
	usuarios.close();
}

// Salva informações sobre os servidores
void System::salvarServidores()
{
	servidores.open("servidores.txt", ios::app);
	servidores << serversVec.size() << endl;
	for (auto itr:serversVec)
	{
		servidores << itr->getUsuariodonoid() << endl;
		servidores << itr->getNameserver() << endl;
		servidores << itr->getDescript() << endl;
		servidores << itr->getInvitecode() << endl;	
		servidores << itr->getParticipants().size() << endl;	
		for (auto itrParticipants:itr->getParticipants())
		{
			servidores << itrParticipants << endl;
		}
		servidores << itr->getChannels().size() << endl;	
		for (auto itrCanal:itr->getChannels())
		{
			servidores << itrCanal->getNamechannel() << endl;
			servidores << itrCanal->getType() << endl;
			if (itrCanal->getType() == "voz")
			{
				for (auto itrCanalVoice:itr->getChannelVoice())
				{
					if (itrCanalVoice->getNamechannel() == itrCanal->getNamechannel())
					{
						servidores << 1;
						servidores << itrCanalVoice->getMessages()->getEnviadapor() << endl;
						servidores << itrCanalVoice->getMessages()->getData_hora() << endl;
						servidores << itrCanalVoice->getMessages()->getConteudo() << endl;
					}
				}
				servidores << itr->getChannelVoice().size() << endl;
			}
			else if (itrCanal->getType() == "texto")
			{
				for (auto itrCanalTexto:itr->getChannelText())
				{
					if (itrCanalTexto->getNamechannel() == itrCanal->getNamechannel())
					{
						servidores << itrCanalTexto->getMessages().size() << endl;
						for (auto itrMessages:itrCanalTexto->getMessages())
						{
							servidores << itrMessages->getEnviadapor() << endl;
							servidores << itrMessages->getData_hora() << endl;
							servidores << itrMessages->getConteudo() << endl;
						}
					}
				}
			}			
		}
	}
	servidores.close();
}

void System::salvar()
{
	salvarUsuario();
	salvarServidores();
}