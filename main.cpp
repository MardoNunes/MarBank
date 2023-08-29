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
	//BANCO DEVE SER INSTANCIADO AQ
	Banco bank;

	 Console::iniciar();
	 short opc;
	 std::cout << "Entre com sua opção: ";
	 std::cin >> opc;
	 std::cout << "opção: " << opc << std::endl;

	while(opc != 4){
		 switch(opc){
		 	case 1:{
		 		std::cout << "Criar conta" << std::endl;
				Criador c;
				Cliente* ptrC{new Cliente}; //ponteiro para um cliente
				ContaBancaria* ptrCB{new ContaBancaria}; //ponteiro para uma conta

				c.criarConta(ptrC, ptrCB); //passo esses ponteiros e atribuo valores aonde apotam

				ptrC->adicionaConta(ptrCB); //cliente recebe sua conta criada

				//banco recebe o cliente
				bank.adicionaCliente(ptrC);

				system("clear");
				Console::menuConta();
				std::cout << "Entre com sua opção: ";
				std::cin >> opc;
				while(opc != 4){
					switch(opc){
						case 1:
						{
							system("clear");
							std::cout << std::endl;
							std::cout << "------Sua Conta-----" << std::endl;
							std::cout << ptrC->getNome() << " " << ptrCB->getSaldo() << " " << ptrCB->getNumeroConta() << std::endl;
							std::cout << std::endl;
							break;
						}
						case 2:
						{
							system("clear");
							std::cout << std::endl;
							std::cout << "-----Realizar deposito-----" << std::endl;
							std::cout << "Entre com o valor: ";
							float valor;
							std::cin >> valor;
							try{
								ptrCB->setSaldo(valor);
								std::cout << "Deposito realizado com sucesso!" << std::endl;
							}
							catch(int& ex){
								if(ex == 1)
									std::cout << "Valor inválido!" << std::endl;
							}
							break;
						}
						case 3:
						{
							system("clear");
							std::cout << std::endl;
							std::cout << "-----Realizar saque---" << std::endl;
							std::cout << "Entre com o valor: ";
							float valor;
							std::cin >> valor;
							try{
								ptrCB->sacar(valor);
								std::cout << "Saque realizado com sucesso!" << std::endl;
							}
							catch(int& ex){
								if(ex == 1)
									std::cout << "Saldo insuficiente!" << std::endl;
							}
							break;
						}
						default:
							std::cout << "Entrada inválida!2" << std::endl;
					}
					
					Console::menuConta();
					std::cout << "Entre com sua opção: ";
					std::cin >> opc;
					system("clear");
					
				}


		 		break;
			       }
		 	case 2:
			       {
			
		 		std::cout << "Login: " << std::endl;
				unsigned long cpf;
				const Cliente* ptrC;
				std::cout << "Entre com o seu CPF: ";	
				std::cin >> cpf;
				try{
					ptrC = bank.buscaCliente(cpf);
					ContaBancaria* ptrCB;
					ptrCB = ptrC->getConta();
					       
					//colocar tela menuContaBancaria
					//tratar as entradas
					system("clear");
					Console::menuConta();
					std::cout << "Entre com sua opção: ";
					std::cin >> opc;
					while(opc != 4){
						switch(opc){
							case 1:
							{
								system("clear");
								std::cout << std::endl;
								std::cout << "------Sua Conta-----" << std::endl;
								std::cout << ptrC->getNome() << " " << ptrCB->getSaldo() << " " << ptrCB->getNumeroConta() << std::endl;
								std::cout << std::endl;
								break;
							}
							case 2:
							{
								system("clear");
								std::cout << std::endl;
								std::cout << "-----Realizar deposito-----" << std::endl;
								std::cout << "Entre com o valor: ";
								float valor;
								std::cin >> valor;
								try{
									ptrCB->setSaldo(valor);
									std::cout << "Deposito realizado com sucesso!" << std::endl;
								}
								catch(int& ex){
									if(ex == 1)
										std::cout << "Valor inválido!" << std::endl;
								}
								break;
							}
							case 3:
							{
								system("clear");
								std::cout << std::endl;
								std::cout << "-----Realizar saque---" << std::endl;
								std::cout << "Entre com o valor: ";
								float valor;
								std::cin >> valor;
								try{
									ptrCB->sacar(valor);
									std::cout << "Saque realizado com sucesso!" << std::endl;
								}
								catch(int& ex){
									if(ex == 1)
										std::cout << "Saldo insuficiente!" << std::endl;
								}
								break;
							}
							default:
								std::cout << "Entrada inválida!3" << std::endl;
						}
						
						Console::menuConta();
						std::cout << "Entre com sua opção: ";
						std::cin >> opc;
						system("clear");
						
				}
				}
				catch(int& ex){
					if(ex == 1)
						std::cout << "Login inválido!" << std::endl;
				}
				break;
			       }
			case 3:
			{
				bank.showClientes();
			}
		 	default:
		 		std::cout << "Entrada inválida! 1" << std::endl;
		}

		Console::iniciar();
		std::cout << "Entre com sua opção: ";
	 	std::cin >> opc;
		system("clear");
	}



    return 0;
}
