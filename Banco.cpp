#include <iostream>
#include <set>
#include "Banco.hpp"
#include "Cliente.hpp"

Banco::Banco():clientes{nullptr}{}
Banco::~Banco(){}

//adiciona um cliente ao banco
void Banco::adicionaClinte(Cliente* cliente){
    clientes.insert(cliente);
}


//mostra todos os clientes do banco sem dar falha de segmentação
void Banco::showClientes(){
   std::set<Cliente*>::iterator it;
    for(it = clientes.begin(); it != clientes.end(); it++){
         std::cout << (*it)->getNome() << std::endl;
    }
}




