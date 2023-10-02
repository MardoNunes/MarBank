#include <iostream>
#include "ContaBancaria.hpp"


ContaBancaria::ContaBancaria() {}
ContaBancaria::ContaBancaria(const double saldo): saldo{saldo}{}
ContaBancaria::ContaBancaria(const unsigned long numeroConta, const double saldo): numeroConta{numeroConta}, saldo{0}, cofrinho{0}{
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

void ContaBancaria::adicionaCofrinho(const double valor){
	if(valor <= this->saldo){
		this->saldo = this->saldo - valor;
		this->cofrinho = this->cofrinho + valor;
	}
	else{
		throw (int)1;
	}
}

void ContaBancaria::rendeCofrinho(const double valor){
	this->cofrinho = this->cofrinho + valor;
}

double ContaBancaria::getCofrinho() const{
	return this->cofrinho;
}

void ContaBancaria::resgataCofrinho(const double valor){
	
	if(valor <= cofrinho){
		this->cofrinho = this->cofrinho - valor;
		this->saldo = this->saldo + valor;
		return;
	}
	throw (int)1;
}




