#include <iostream>
#include <cstdint>
#include "Pessoa.hpp"

Pessoa::Pessoa(){}
Pessoa::Pessoa(const std::string& nome, const unsigned short idade): nome{nome}{
	this->setIdade(idade);
}
Pessoa::Pessoa(const std::string& nome, const unsigned short idade, const uint32_t cpf): Pessoa(nome, idade) {
	this->setCpf(cpf);
}

Pessoa::~Pessoa(){}

std::string Pessoa::getNome() const{
	return this->nome;
}

unsigned short Pessoa::getIdade() const{
	return this->idade;
}

uint32_t Pessoa::getCpf() const{
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

void Pessoa::setCpf(uint32_t cpfTeste){
	if(!validarCPF(cpfTeste))
		throw (int)1;
	this->cpf = cpfTeste;
}

bool Pessoa::validarCPF(uint32_t cpf) const{
    
    uint32_t somatorioValidaUltimo;
    uint32_t modulo;
    uint32_t somatorioValidaPenultimo{0};
    uint32_t ultimo{(uint32_t)(cpf % 10)};
    cpf /= 10;
    uint32_t penultimo{(uint32_t)(cpf % 10)};
    cpf /= 10;

    somatorioValidaUltimo = penultimo * 2;
    for(int i{2}; i <= 11; i++){
        modulo = cpf % 10;
        cpf /= 10;
        somatorioValidaPenultimo += modulo * i;
        somatorioValidaUltimo += modulo * (i + 1);
    }
	std::cout << "ultimo: " << ultimo << std::endl;
	std::cout << "penultimo: " << penultimo << std::endl;

    modulo = somatorioValidaPenultimo % 11;
	std::cout << "modulo: " << modulo << std::endl;
    if(modulo < 2){
        if(penultimo != 0){
			std::cout << "aqui" << std::endl;
            return false;
        }
    }
    else{
        if(penultimo != 11 - modulo){
			std::cout << "aqui2" << std::endl;
            return false;
        }
    }
    modulo = somatorioValidaUltimo % 11;
	std::cout << "modulo: " << modulo << std::endl;
    if(modulo < 2){
        if(ultimo != 0){
			std::cout << "aqui3" << std::endl;
            return false;
        }
    }
    else{
        if(ultimo != 11 - modulo){
			std::cout << "aqui4" << std::endl;
            return false;
        }
    }
	std::cout << "true" << std::endl;
    return true;
}


