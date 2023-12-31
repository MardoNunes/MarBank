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
    std::pair<std::set<Cliente*>::iterator, bool> result = clientes.insert(cliente);
    if(!result.second)
		throw (int)3;

}


void Banco::showClientes(){
   	unsigned short cont{1};
	ContaBancaria* ptrC;
	std::cout << "Clientes cadastrados: " << std::endl;
   	std::set<Cliente*>::iterator it{clientes.begin()};
    for(; it != clientes.end(); it++){
		ptrC = (*it)->getConta();
 		std::cout << "Cliente ["<< cont << "]" << "\tNome: "<<(*it)->getNome() << "\t|" << "\tIdade: " <<(*it)->getIdade() << "\t|" << "\tN°: " <<ptrC->getNumeroConta() << std::endl;
		cont++;
	 
    }
}

const Cliente* Banco::buscaCliente(const unsigned long cpf){
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


void Banco::transacao(ContaBancaria* contaOrigem, ContaBancaria* contaDestino, double valor){
	if(valor >= 0){
		contaOrigem->sacar(valor);
		contaDestino->setSaldo(valor);
		std::cout << "Transação realizada com sucesso!" << std::endl;
	}
	else{
		throw (int)1;
	}
}

bool Banco::vereficaExistencia(const unsigned long cpf){
	std::set<Cliente*>::iterator it{clientes.begin()};
	for(; it != clientes.end(); it++){
		if((*it)->getCpf() == cpf)
			throw (int)2;
	}
	return true;
}


void Banco::showContaBancaria(const Cliente* ptrC, const ContaBancaria* ptrCB){
	std::cout << "------Sua Conta-----" << std::endl;
	std::cout << ptrC->getNome() << "\tsaldo: " << ptrCB->getSaldo() << "\tN°: " << ptrCB->getNumeroConta() << std::endl;
	std::cout << std::endl;
}


void Banco::setCofrinhos(){
	std::set<Cliente*>::iterator it{clientes.begin()};
	ContaBancaria* ptrCB;
	for(; it != clientes.end(); it++){
		ptrCB = (*it)->getConta();
		if(ptrCB->getCofrinho() != 0)
			ptrCB->rendeCofrinho(Banco::rendimento);
	}
}


//vou dar free em todos os clientes
void Banco::cleanClientes(){
	
	std::set<Cliente*>::iterator it{clientes.begin()};
	for(; it != clientes.end(); it++){
		delete (*it);
	}

}

void Banco::cleanContasBancarias(){

	std::set<Cliente*>::iterator it{clientes.begin()};
	for(; it != clientes.end(); it++){
		(*it)->freeConta();
	}
}

