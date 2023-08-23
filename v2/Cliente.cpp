#include <iostream>
#include <set>
#include "Cliente.hpp"

Cliente::Cliente(){}
Cliente::Cliente(const std::string& nome, const unsigned short idade, const unsigned long cpf): Pessoa(nome, idade, cpf), contas{nullptr}{}
Cliente::~Cliente(){}

void Cliente::adicionaConta(ContaBancaria* conta){
	contas.insert(conta);
}


//retorna um referencia para o comeco da lista
std::set<ContaBancaria*>& Cliente::getConta(){
	return contas;
}
