#include <iostream>
#include <list>
#include "Cliente.hpp"



void Cliente::adicionaConta(ContaBancaria* conta){
	this->conta = conta;
}



ContaBancaria* Cliente::getConta(){
	return this->conta;
}
