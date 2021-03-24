#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User
{
private:
	int id;
	bool logado;
	string nome;
	string email;
	string senha;
public:
	User(string e, string s, string n);
	User();
	~User();
	
	static User* userLog;
	
	int getId();
	void setId(int i);

	string getNome();
	void setNome(string n);

	string getEmail();
	void setEmail(string e);

	string getSenha();
	void setSenha(string s);

	bool getLogado();
	void setLogado(bool l);
};
#endif