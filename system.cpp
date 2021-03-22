#include "system.h"

System::System()
{
	User* creator = new User("criador@gmail.com", "criado00", "criador");
	usersVec.push_back(creator->getNome());
}

bool System::quit()
{
	cout << "Saindo do Concordo!";
	return true;
}

bool System::createUser(string e, string s, string n)
{
	if (searchUser(n) == true)
	{
		// Pode acontecer de existir dois usuários com o mesmo nome, mas os emails devem ser diferentes
		cout << "Usuário já cadastrado!" << endl;
		return false;
	}
	else
	{
	User* newUser = new User(e, s, n);
	usersVec.push_back(n);

	cout << "Usuário criado!" <<  endl;
	}
	return true;
}
void System::login(string e, string s)
{

}
bool System::searchUser(string n)
{
	for (int i = 0; i < (usersVec.size()); i++)
	{
		if (usersVec[i] == n)
		{
			return true;
		}
	}

	return false;
}

