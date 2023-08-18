#include <iostream>
#include <vector>
#include "Cliente.hpp"


Cliente::Cliente(){}
Cliente::~Cliente(){}
Cliente::Cliente(const std::string& nome, const unsigned short int idade, const unsigned long cpf, const unsigned int id, const std::string contato): 
Pessoa{nome, idade, cpf}, id{id}, contato{contato}{

}

void Cliente::adicionarConta(const ContaBancaria& novaConta){
    contas.push_back(novaConta);
}

const std::vector<ContaBancaria>& Cliente::getContas() const{
    return contas;
}