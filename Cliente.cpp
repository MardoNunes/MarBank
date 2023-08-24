#include <iostream>
#include <list>
#include "Cliente.hpp"


Cliente::Cliente(){}
Cliente::Cliente(const std::string& nome, const unsigned short idade, const unsigned long cpf): Pessoa(nome, idade, cpf){}
Cliente::~Cliente(){}

void Cliente::adicionaConta(ContaBancaria* conta){
	this->conta = conta;
}



ContaBancaria* Cliente::getConta(){
	return this->conta;
}
