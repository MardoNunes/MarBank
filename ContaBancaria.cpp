#include <iostream>
#include "ContaBancaria.hpp"


ContaBancaria::ContaBancaria() {}
ContaBancaria::ContaBancaria(const double saldo): saldo{saldo}{}
ContaBancaria::ContaBancaria(const unsigned long numeroConta, const double saldo): numeroConta{numeroConta}, saldo{0}{
}
ContaBancaria::~ContaBancaria() {}

unsigned long ContaBancaria::getNumeroConta() const{
	return this->numeroConta;
}

void ContaBancaria::setNumeroConta(const unsigned long novoNumero){
	this->numeroConta = novoNumero;
}

double ContaBancaria::getSaldo() const{
	return this->saldo;
}

void ContaBancaria::setSaldo(const double valor){
	if(valor < 0)
		throw (int)1;
	this->saldo = this->saldo + valor;
}


void ContaBancaria::sacar(const double valor){
	if(valor > this->saldo)
		throw (int)1;
	this->saldo = this->saldo - valor;
}

void ContaBancaria::gerarNumero(){
	this->numeroConta = rand() % 100000;
}








