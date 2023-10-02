#include <iostream>

#include "Cliente.hpp"
#include "ContaBancaria.hpp"


void Cliente::adicionaConta(ContaBancaria* conta){
	this->conta = conta;
}



ContaBancaria* Cliente::getConta() const{
	return this->conta;
}

void Cliente::freeConta(){
	delete this->conta;
}