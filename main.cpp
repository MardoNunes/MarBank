#include <iostream>
#include <cstdint>



#include "ContaBancaria.hpp"
#include "Console.hpp"
#include "Pessoa.hpp"
#include "Cliente.hpp"

using namespace std;

int main(){

	//testando classe pessoa
	// Pessoa p1{"Mardo", 20, 11111111111};
	// std::cout << "Nome: " << p1.getNome() << std::endl;
	// std::cout << "Idade: " << p1.getIdade() << std::endl;
	// std::cout << "CPF: " << p1.getCpf() << std::endl;

	// //testando polimorfismo de ponteiros, cliente->pessoa	
	// Cliente c1{"Joao", 20, 1111111111};
	
	// Pessoa* ptr{&c1};
	// std::cout << "Nome: " << ptr->getNome() << std::endl;
	

	// //testando a ligação de cliente com conta bancaira
	// ContaBancaria b1{"MarTech", 2, 1000};

	// c1.adicionaConta(&b1);

	// ContaBancaria* ptr2;
	// ptr2 = c1.getConta();
	// std::cout << "1" << std::endl;
	// std::cout << "saldo: " << ptr2->getSaldo() << std::endl;

	//isso funciona:
	Pessoa p1{"Mardo", 20, 11111111111};
	Cliente c1{p1.getNome(), p1.getIdade(), p1.getCpf()};

	








	Console::iniciar();

	short opc;
	std::cout << "Entre com sua opção: ";
	std::cin >> opc;
	std::cout << "opção: " << opc << std::endl;

	switch(opc){
		case 1:
			std::cout << "Criar conta" << std::endl;
			//devo instanciar um cliente
			//instanciar um conta bancria
			//e vincular conta com cliente e cliente com banco!
			//ao criar deve ser automaticamente logado
			break;
		case 2:
			std::cout << "Logim en conta" << std::endl;
			//n sei como sera o logim, acredito q apenas o cpf
			break;
		default:
			std::cout << "Entrada inválida!" << std::endl;
	}




    return 0;
}
