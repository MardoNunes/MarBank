#include <iostream>
#include <cstdint>
#include <set>


#include "ContaBancaria.hpp"
#include "Console.hpp"
#include "Pessoa.hpp"
#include "Cliente.hpp"
#include "Banco.hpp"
#include "Criador.hpp"

using namespace std;

int main(){
	 Console::iniciar();
	 short opc;
	 std::cout << "Entre com sua opção: ";
	 std::cin >> opc;
	 std::cout << "opção: " << opc << std::endl;

	 switch(opc){
	 	case 1:{
	 		std::cout << "Criar conta" << std::endl;
			Criador c;
			Cliente* ptrC = new Cliente; //ponteiro para um cliente
			ContaBancaria* ptrCB = new ContaBancaria; //ponteiro para uma conta

			c.criarConta(ptrC, ptrCB); //passo esses ponteiros e atribuo valores aonde apotam

			ptrC->adicionaConta(ptrCB); //cliente recebe sua conta criada
			
	 		//ao criar deve ser automaticamente logado
		
	 		break;
		       }
	 	case 2:
		       {
			Cliente c{"Mardo", 20, 11111111111};
			ContaBancaria cb;
			cb.setSaldo(400);
			c.adicionaConta(&cb);
			Cliente c1{"Maria", 35, 12203328959};
			ContaBancaria cb1;
			cb1.setSaldo(4000);
			c1.adicionaConta(&cb1);



	 		std::cout << "Login: " << std::endl;
	 		//n sei como sera o logim, acredito q apenas o cpf
			Banco bank;
			bank.adicionaCliente(&c);
			bank.adicionaCliente(&c1);
			unsigned long cpf;
			const Cliente* ptrC;
			std::cout << "Entre com o seu CPF: ";	
			std::cin >> cpf;
			try{
				ptrC = bank.buscaCliente(cpf);
				ContaBancaria* ptrCB;
				ptrCB = ptrC->getConta();
				std::cout << ptrC->getNome() <<" "<<ptrCB->getSaldo() << std::endl;
			       	ptrCB->setSaldo(50);
		       		std::cout << ptrCB->getSaldo() << std::endl;	       
				//colocar tela menuContaBancaria
				//tratar as entradas
			}
			catch(int& ex){
				if(ex == 1)
					std::cout << "Login inválido!" << std::endl;
			}
			break;
		       }
	 	default:
	 		std::cout << "Entrada inválida!" << std::endl;
	}




    return 0;
}
