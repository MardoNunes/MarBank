#include <iostream>
#include "Pessoa.hpp"

Pessoa::Pessoa(){}
Pessoa::Pessoa(const std::string& nome, const unsigned short idade): nome{nome}{
	this->setIdade(idade);
}
Pessoa::Pessoa(const std::string& nome, const unsigned short idade, const unsigned long cpf): Pessoa(nome, idade) {
	this->setCpf(cpf);
}

Pessoa::~Pessoa(){}

std::string Pessoa::getNome() const{
	return this->nome;
}

unsigned short Pessoa::getIdade() const{
	return this->idade;
}

unsigned long Pessoa::getCpf() const{
	return this->cpf;
}

void Pessoa::setNome(const std::string& nome){
	this->nome = nome;
}

void Pessoa::setIdade(const unsigned short idade){
	if(idade > 120)
		throw (int)1;
	this->idade = idade;
}

void Pessoa::setCpf(unsigned long cpfTeste){
	if(!validarCPF(cpfTeste))
		throw (int)1;
	this->cpf = cpfTeste;
}

bool Pessoa::validarCPF(unsigned long cpfTeste) const{

	int somatorioValidaUltimo;
	int modulo;
	int somatorioValidaPenultimo = 0;
	int ultimo = cpfTeste%10;
	cpfTeste = cpfTeste/10;
	int penultimo = cpfTeste%10;
	cpfTeste = cpfTeste/10;
	
	somatorioValidaUltimo = penultimo*2;
	for(int i=2; i <= 11; i++){
		modulo = cpfTeste%10;
		cpfTeste = cpfTeste/10;
		somatorioValidaPenultimo += modulo*i;
		somatorioValidaUltimo += modulo*(i+1);
	}
	modulo = somatorioValidaPenultimo%11;
	if(modulo < 2){
		if(!penultimo)
			return false;//cpf invalido
	}else{
		if(penultimo != 11 - modulo)
			return false;//cpf invalido
	}
	modulo = somatorioValidaUltimo%11;
	if(modulo < 2){
		if(!ultimo)
			return false;//cpf invalido
	}else{
		if(ultimo != 11-modulo)
			return false;//cpf invalido
	}
	return true;//cpf valido
}


