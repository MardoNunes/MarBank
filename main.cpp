#include <iostream>
#include <list>
#include "ContaBancaria.hpp"
#include "Console.hpp"
#include "Pessoa.hpp"
#include "Cliente.hpp"

using namespace std;

int main(){

	//testando classe pessoa
	Pessoa p1{"Mardo", 20, 11111111111};
	std::cout << "Nome: " << p1.getNome() << std::endl;
	std::cout << "Idade: " << p1.getIdade() << std::endl;
	std::cout << "CPF: " << p1.getCpf() << std::endl;

	//testando polimorfismo de ponteiros, cliente->pessoa	
	Pessoa* ptr{&c1};
	std::cout << "Nome: " << ptr->getNome() << std::endl;
	

	//testando a ligação de cliente com conta bancaira
	ContaBancaria b1{"MarTech", 2, 1000};
	Cliente c1{"Joao", 20, 1111111111};

	c1.adicionaConta(&b1);

	ContaBancaria* ptr2;
	ptr2 = c1.getConta();
	std::cout << "1" << std::endl;
	std::cout << "saldo: " << ptr2->getSaldo() << std::endl;

    return 0;
}
