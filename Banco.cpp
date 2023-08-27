#include <iostream>
#include <set>
#include "Banco.hpp"
#include "Cliente.hpp"

Banco::Banco(){}
Banco::~Banco(){}

//adiciona um cliente ao banco
void Banco::adicionaCliente(Cliente* cliente){
	//COLOCAR UMA EXCESSAO AQUI
    std::pair<std::set<Cliente*>::iterator, bool> result = clientes.insert(cliente);
    if(result.second)
	    std::cout << "sucesso" << std::endl;
    else
	    std::cout << "fracasso" << std::endl;

}


void Banco::showClientes(){
   unsigned short cont{1};
 //  std::cout << "Listando Clientes: " << std::end;
   std::set<Cliente*>::iterator it{clientes.begin()};
    for(; it != clientes.end(); it++){
 std::cout << "Cliente ["<< cont << "]" << " " <<(*it)->getNome() << " " << (*it)->getIdade() << " " << (*it)->getCpf() << std::endl;
	 
    }
}

const Cliente* Banco::buscaCliente(unsigned long cpf){
	std::set<Cliente*>::iterator it{clientes.begin()};
	for(; it != clientes.end(); it++){
		if((*it)->getCpf() == cpf)
			return (*it);
	}

	throw (int)1;
}




