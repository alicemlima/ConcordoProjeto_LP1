#include <iostream>
#include "system.h"
using namespace std;

User* User::userLog;
Server* Server::serverLog;
Channel* Channel::channelLog;

int main(int argc, char const *argv[])
{
	System* concordo = new System();
	
	do
	{
		concordo->init();
	} while (concordo->getOn() == true);
	return 0;
}