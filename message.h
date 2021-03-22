#ifndef MESSAGE_H
#define MESSAGE_H

#include "user.h"

class Message
{
private:
	string data_hora,
	conteudo;
	int enviadaPor;
public:
	Message();
	~Message();
};

#endif