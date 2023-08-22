#include <iostream>
#include "ContaBancaria.hpp"
#include "Console.hpp"
#include "Pessoa.hpp"


using namespace std;

int main(){
	ContaBancaria b1{"MarTech", 2, 1000};

	std::cout << "Nome: " << b1.getNome() << std::endl;
       	std::cout << "Numero da Conta: " << b1.getNumeroConta() << std::endl;
	std::cout << "saldo: " << b1.getSaldo() << std::endl;	

	std::cout << "Depositando 40 reais!" << std::endl;
	b1.setSaldo(40);
	std::cout << "Saldo: " << b1.getSaldo() << std::endl;

	std::cout << "Sacando 27,5 reais!" << std::endl;
	b1.sacar(27.5);
	std::cout << "Saldo: " << b1.getSaldo() << std::endl;

	std::cout << "Tentando sacar mais que saldo!" << std::endl;
	try{
		b1.sacar(2000);
	}
	catch(int& ex){
		if(ex == 1)
			std::cout << "Sem saldo o suficiente!!" << std::endl;
		else
			std::cout << "Erro desconhecido!!" << std::endl;
	}

	
	Pessoa p1{"Mardo", 20, 11111111111};
	std::cout << "Nome: " << p1.getNome() << std::endl;
	std::cout << "Idade: " << p1.getIdade() << std::endl;
	std::cout << "CPF: " << p1.getCpf() << std::endl;

	Pessoa p2;
	p2.setNome("Maria");
	p2.setIdade(35);
	p2.setCpf(11111111111);

	std::cout << "Nome: " << p2.getNome() << std::endl;
	std::cout << "Idade: " << p2.getIdade() << std::endl;
	std::cout << "CPF: " << p2.getCpf() << std::endl;



	//Console::menu();
    return 0;
}
