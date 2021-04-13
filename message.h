#ifndef MESSAGE_H
#define MESSAGE_H
#include <ctime>
#include "user.h"

class Message
{
private:
	string data_hora,
	conteudo,
	enviadaPor;
public:
	Message(string ms);
	~Message();

	string getData_hora();
	void setData_hora(string dh);

	string getConteudo();
	void setconteudo(string ct);

	string getEnviadapor();
	void setEnviadapor(string nome);

	string systemTime();
};

#endif