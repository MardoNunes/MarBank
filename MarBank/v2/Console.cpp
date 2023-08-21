#include <iostream>
#include "Console.hpp"

void Console::menu(){
	std::cout << "=============================================" << std::endl;
	std::cout << "\t\t\tMARBANK\t\t\t " << std::endl;
	std::cout << "=============================================" << std::endl;
	std::cout << std::endl;
	std::cout << "1 - Criar uma conta" << std::endl;
	std::cout << "2 - Vizualisar sua Conta" << std::endl;
	std::cout << "3 - Realizar deposito" << std::endl;
	std::cout << "4 - Realizar saque" << std::endl;
	std::cout << "5 - Listar Clientes" << std::endl;
	std::cout << "6 - Sair" << std::endl;

}
