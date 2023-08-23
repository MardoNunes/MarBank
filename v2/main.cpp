#include <iostream>
#include "ContaBancaria.hpp"
#include "Console.hpp"
#include "Pessoa.hpp"
#include "Cliente.hpp"

using namespace std;

int main(){
	ContaBancaria b1{"MarTech", 2, 1000};
	
	Pessoa p1{"Mardo", 20, 11111111111};
	std::cout << "Nome: " << p1.getNome() << std::endl;
	std::cout << "Idade: " << p1.getIdade() << std::endl;
	std::cout << "CPF: " << p1.getCpf() << std::endl;

	Cliente* c1{new Cliente{"Joao", 20, 1111111111}};
	
	Pessoa* ptr{c1};
	std::cout << "Nome: " << ptr->getNome() << std::endl;
	
	c1->adicionaConta(&b1);
	std::set<ContaBancaria*>& contas = c1->getConta();
	for(auto it = contas.begin(); it != contas.end(); it++)
		std::cout << "Saldo: " << (*it)->getSaldo() << std::endl;

    return 0;
}
