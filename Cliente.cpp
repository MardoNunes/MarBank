#include <iostream>
#include "Cliente.hpp"

Cliente::Cliente(){}

Cliente::Cliente(const std::string& nome, const unsigned short int idade, const unsigned long cpf, const unsigned int id, const std::string contato): 
Pessoa{nome, idade, cpf}, id{id}, contato{contato}{

}

