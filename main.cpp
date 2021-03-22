#include <iostream>
#include "system.h"
using namespace std;

int main(int argc, char const *argv[])
{
	System* concordo = new System();

	cout << "Olá!! Seja bem vindo(a) ao Concordo." << endl; 
	concordo->createUser("Primeiro@gmail.com", "123478", "primeiro");
	return 0;
}