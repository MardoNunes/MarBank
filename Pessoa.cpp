#include <iostream>
#include <cstdint>
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
	if(idade < 18)
		throw (int)1;
	this->idade = idade;
}

void Pessoa::setCpf(const unsigned long cpfTeste){
    
	if(!validarCPF(cpfTeste))
		throw (int)1;
	this->cpf = cpfTeste;
}

//so verefica se possui 11 digitos, para não se preocupar com os digitos verificadores
bool Pessoa::validarCPF(unsigned long cpf) const{
    unsigned int cont{0};


    //verifica se possui 11 digitos
    while(cpf != 0){
        cpf /= 10;
        cont++;
    }


    if(cont != 11)
        return false;
    return true;
    
}


