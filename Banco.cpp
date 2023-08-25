#include <iostream>
#include <set>
#include "Banco.hpp"
#include "Cliente.hpp"

Banco::Banco(){}
Banco::~Banco(){}

//adiciona um cliente ao banco
void Banco::adicionaClinte(Cliente* cliente){
//    clientes.insert(cliente);

    std::pair<std::set<Cliente*>::iterator, bool> result = clientes.insert(cliente);
    if(result.second)
	    std::cout << "sucesso" << std::endl;
    else
	    std::cout << "fracasso" << std::endl;

}


//mostra todos os clientes do banco sem dar falha de segmentação
void Banco::showClientes(){
   std::set<Cliente*>::iterator it{clientes.begin()};
    for(; it != clientes.end(); it++){
         std::cout << (*it)->getNome() << std::endl;
	 std::cout << (*it)->getIdade() << std::endl;
    }
}




