#include "user.h"
#include <iostream>

// Método construtor
User::User(string n, string e, string s){
	this->nome = n;
	this->email = e;
	this->senha = s;
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