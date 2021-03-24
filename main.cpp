#include <iostream>
#include "system.h"
using namespace std;

// bool enterSystem();

User* User::userLog;

int main(int argc, char const *argv[])
{

	// enterSystem();

	System* concordo = new System();

	concordo->createUser("Primeiro@gmail.com", "123478", "primeiro");
	concordo->createUser("Segundo@gmail.com", "2220", "segundo");
	concordo->createUser("Segundo@gmail.com", "2220", "segundo");
	concordo->login("Primeiro@gmail.com", "123478");
	concordo->login("Terceiro@gmail.com", "w");
	return 0;
}

// bool enterSystem()
// {
// 	System* concordo = new System();
// 	return true;
// }