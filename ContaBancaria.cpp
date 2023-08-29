#include <iostream>
#include "ContaBancaria.hpp"


ContaBancaria::ContaBancaria() {}
ContaBancaria::ContaBancaria(const std::string nome): nome{nome}{}
ContaBancaria::ContaBancaria(const std:: string nome, const unsigned long numeroConta, const float saldo): nome{nome}, numeroConta{numeroConta}, saldo{0}{
}
ContaBancaria::~ContaBancaria() {}

unsigned long ContaBancaria::getNumeroConta() const{
	return this->numeroConta;
}

void ContaBancaria::setNumeroConta(const unsigned long novoNumero){
	this->numeroConta = novoNumero;
}

float ContaBancaria::getSaldo() const{
	return this->saldo;
}

void ContaBancaria::setSaldo(const float valor){
	if(valor < 0)
		throw (int)1;
	this->saldo = this->saldo + valor;
}

std::string ContaBancaria::getNome() const{
	return this->nome;
}

void ContaBancaria::setNome(const std::string nome){
	this->nome = nome;
}

void ContaBancaria::sacar(const float valor){
	if(valor > this->saldo)
		throw (int)1;
	this->saldo = this->saldo - valor;
}

void ContaBancaria::gerarNumero(){
	this->numeroConta = rand() % 100000;
}








