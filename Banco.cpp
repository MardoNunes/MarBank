#include <iostream>
#include <set>
#include "Banco.hpp"

Banco::Banco():clientes{nullptr}{}
Banco::~Banco(){}

void Banco::adicionaClinte(Cliente* cliente){
    clientes.insert(cliente);
}

std::set<Cliente*>& Banco::getCliente() const{
    return this->clientes;
}
