#include "user.h"
#include <iostream>

// Método construtor
User::User(string e, string s, string n){
	this->email = e;
	this->senha = s;	
	this->nome = n;
}

User::User()
{
	this->nome = "";
	this->email = "";
	this->senha = "";
}

User::~User(){}

int User::getId(){
	return id;
}
void User::setId(int i){
	id = i;
}

string User::getNome(){
	return nome;
}
void User::setNome(string n){
	nome = n;
}

string User::getEmail(){
	return email;
}
void User::setEmail(string e){
	email = e;
}

string User::getSenha(){
	return senha;
}
void User::setSenha(string s){
	senha = s;
}

bool User::getLogado(){
	return logado;
}
void User::setLogado(bool l){
	logado = l;
}