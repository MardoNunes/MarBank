#include <iostream>
#include <cstdint>

#include "Criador.hpp"
#include "ContaBancaria.hpp"
#include "Pessoa.hpp"
#include "Cliente.hpp"
#include "Banco.hpp"



Criador::Criador(){}
Criador::~Criador(){}

void Criador::criarConta(Cliente* c, ContaBancaria* cb, Banco* bank){
	

	std::string nome;
	std::cout << "Seu nome: ";
	std::cin.ignore();
	std::getline(std::cin, nome);
	c->setNome(nome);
	std::cout << std::endl;
	
	unsigned short idade;
	short ctrl;
	do{
		ctrl = 0;
		std::cout << "Sua idade: ";
		std::cin >> idade;
		try{
			c->setIdade(idade);

		}catch(int& e){
			std::cout << "Deve ser de maior!!" << std::endl;
			ctrl = 1;
		}
		std::cout << std::endl;
	}while(ctrl == 1);

	unsigned long cpf;
	do{
		ctrl = 0;
		std::cout << "Seu CPF: ";
		std::cin >> cpf;
		try{
			c->setCpf(cpf);	
			bank->vereficaExistencia(cpf);
		}catch(int& ex){
			if(ex == 1)
				std::cout << "CPF invalido" << std::endl;
			else if(ex == 2)
				std::cout << "CPF ja cadastrado" << std::endl;
			ctrl = 1;
			
		}
		std::cout << std::endl;
	}while(ctrl == 1);
	double valor;
	std::cout << "Qual o valor inicial da conta: ";
	std::cin >> valor;
	cb->setSaldo(valor);
	std::cout << std::endl;

	//gera um numero aleatorio para a conta
	cb->gerarNumero();

	std::cout << "Conta criada com sucesso!!" << std::endl;
}

void Criador::geraClientes(Banco* const bank){

	//clientes gerados dinamicamente
	Cliente* c1{new Cliente{"Joao", 20, 12345678910}};
	Cliente* c2{new Cliente{"Maria", 30, 12345678911}};
	Cliente* c3{new Cliente{"Jose", 40, 12345678912}};

	//contas geradas dinamicamente
	ContaBancaria* cb1{new ContaBancaria{1000}};
	cb1->gerarNumero();

	ContaBancaria* cb2{new ContaBancaria{2000}};
	cb2->gerarNumero();

	ContaBancaria* cb3{new ContaBancaria{3000}};
	cb3->gerarNumero();

	//adicionando as contas aos clientes
 	c1->adicionaConta(cb1);
	c2->adicionaConta(cb2);
	c3->adicionaConta(cb3);		
	


	//adicionando os clientes ao banco
	try{
 		bank->adicionaCliente(c1);
		bank->adicionaCliente(c2);
		bank->adicionaCliente(c3);
	}
	catch(int& ex){
		if(ex == 3){
			std::cout << "Não foi possivel adicionar cliente!" << std::endl;
			exit(1);
		}
	}
	
}