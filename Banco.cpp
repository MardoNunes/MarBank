#include <iostream>
#include <set>
#include <cstdint>

#include "Banco.hpp"
#include "Cliente.hpp"
#include "ContaBancaria.hpp"

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
	ContaBancaria* ptrC;
   	std::set<Cliente*>::iterator it{clientes.begin()};
    for(; it != clientes.end(); it++){
		ptrC = (*it)->getConta();
 		std::cout << "Cliente ["<< cont << "]" << " " <<(*it)->getNome() << " " << (*it)->getIdade() << " " << ptrC->getNumeroConta() << std::endl;
		cont++;
	 
    }
}

const Cliente* Banco::buscaCliente(const uint32_t cpf){
	std::set<Cliente*>::iterator it{clientes.begin()};
	for(; it != clientes.end(); it++){
		if((*it)->getCpf() == cpf)
			return (*it);
	}

	throw (int)1;
}


const Cliente* Banco::buscaClienteNumeroConta(unsigned long numeroConta){
	ContaBancaria* ptrCB;
	std::set<Cliente*>::iterator it{clientes.begin()};
	for(; it != clientes.end(); it++){
		ptrCB = (*it)->getConta();
		if(ptrCB->getNumeroConta() == numeroConta)
			return (*it);
		
	}

	throw (int)1;
}


void Banco::transacao(ContaBancaria* contaOrigem, ContaBancaria* contaDestino, float valor){
	contaOrigem->sacar(valor);
	contaDestino->setSaldo(valor);
}




