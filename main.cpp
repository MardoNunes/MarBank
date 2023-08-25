#include <iostream>
#include <cstdint>
#include <set>


#include "ContaBancaria.hpp"
#include "Console.hpp"
#include "Pessoa.hpp"
#include "Cliente.hpp"
#include "Banco.hpp"

using namespace std;

int main(){

	

	//adicionar um clinte ao banco
	ContaBancaria* cb = new ContaBancaria{"Joao", 2, 400};
	Banco b1;
 	Cliente* c1 = new Cliente{"Joao", 20, 1111111111};
	
 	Cliente* c2 = new Cliente{"Maria", 25, 1111111111};
	
 	Cliente* c3 = new Cliente{"Carlos", 32, 1111111111};

	b1.adicionaClinte(c1);
	b1.adicionaClinte(c2);
	b1.adicionaClinte(c3);

	b1.showClientes();
	
	

	delete c1;





	// Console::iniciar();

	// short opc;
	// std::cout << "Entre com sua opção: ";
	// std::cin >> opc;
	// std::cout << "opção: " << opc << std::endl;

	// switch(opc){
	// 	case 1:
	// 		std::cout << "Criar conta" << std::endl;
	// 		//devo instanciar um cliente
	// 		//instanciar um conta bancria
	// 		//e vincular conta com cliente e cliente com banco!
	// 		//ao criar deve ser automaticamente logado
	// 		break;
	// 	case 2:
	// 		std::cout << "Logim en conta" << std::endl;
	// 		//n sei como sera o logim, acredito q apenas o cpf
	// 		break;
	// 	default:
	// 		std::cout << "Entrada inválida!" << std::endl;
	//}




    return 0;
}
