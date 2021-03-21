#ifndef USER_H
#define USER_H

class User
{
private:
	int id;
	string nome;
	string email;
	string senha;
public:
	User(string e, string s, string n);
	~User();
	
	int getId();
	void setId(int i);

	string getNome();
	void setNome(string n);

	string getEmail();
	void setEmail(string e);

	string getSenha();
	void setSenha(string s);
};
#endif