#include <iostream>
#include "Criador.hpp"
#include "ContaBancaria.hpp"
#include "Pessoa.hpp"

Criador::Criador(){}
Criador::~Criador(){}

void Criador::criarConta(Cliente* c, ContaBancaria* cb){
	
	std::string nome;
	std::cout << "Seu nome: ";
	std::cin >> nome;
	c->setNome(nome);
	std::cout << std::endl;
	
	unsigned short idade;
	std::cout << "Sua idade: ";
	std::cin >> idade;
	c->setIdade(idade);
	std::cout << std::endl;

	unsigned long cpf;
	std::cout << "Seu CPF: ";
	std::cin >> cpf;
	c->setCpf(cpf);	
	std::cout << std::endl;

	float valor;
	std::cout << "Qual o valor inicial da conta: ";
	std::cin >> valor;
	cb->setSaldo(valor);
	std::cout << std::endl;
}
