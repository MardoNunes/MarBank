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
	
	Banco* bank{new Banco};
	Criador* c{new Criador};
	c->geraClientes(bank);


	 Console::iniciar();
	 short opc;
	 std::cout << "Entre com sua opção: ";
	 std::cin >> opc;

	while(opc != 4){
		 switch(opc){
		 	case 1:{
				system("clear");
		 		std::cout << "Criar conta:" << std::endl;
				Cliente* ptrC{new Cliente}; //ponteiro para um cliente
				ContaBancaria* ptrCB{new ContaBancaria}; //ponteiro para uma conta

				c->criarConta(ptrC, ptrCB, bank); //passo esses ponteiros e atribuo valores aonde apotam

				ptrC->adicionaConta(ptrCB); //cliente recebe sua conta criada

				//banco recebe o cliente
				bank->adicionaCliente(ptrC);

				system("clear");
				Console::menuConta();
				std::cout << "Entre com sua opção: ";
				std::cin >> opc;
				while(opc != 5){
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
							double valor;
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
							double valor;
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
						case 4:
						{
							unsigned long numeroConta;
							const Cliente* ptrC2;
							std::cout << "Entre com o numero da conta: ";
							std::cin >> numeroConta;
							ptrC2 = bank->buscaClienteNumeroConta(numeroConta);	//busca o cliente pelo numero da conta
							ContaBancaria* ptrCB2;
							ptrCB2 = ptrC2->getConta();	//pega a conta do cliente encontrado
							double valor;
							std::cout << "Entre com o valor da transferência: ";
							std::cin >> valor;
							bank->transacao(ptrCB, ptrCB2, valor);	//realizo a transação!

							//libera a memoria
							delete ptrCB2;
							delete ptrC2;							
							break;
						}
						case 5:
						{
							//libera a memoria
							delete ptrCB;
							delete ptrC;

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
					ptrC = bank->buscaCliente(cpf);
					ContaBancaria* ptrCB;
					ptrCB = ptrC->getConta();
					       
					//colocar tela menuContaBancaria
					//tratar as entradas
					system("clear");
					Console::menuConta();
					std::cout << "Entre com sua opção: ";
					std::cin >> opc;
					while(opc != 5){
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
								double valor;
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
								double valor;
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
							case 4:
							{
							unsigned long numeroConta;
							const Cliente* ptrC2;
							std::cout << "Entre com o numero da conta: ";
							std::cin >> numeroConta;
							
							try{
								ptrC2 = bank->buscaClienteNumeroConta(numeroConta);	//busca o cliente pelo numero da conta
								ContaBancaria* ptrCB2;
								ptrCB2 = ptrC2->getConta();	//pega a conta do cliente encontrado
								double valor;
								std::cout << "Entre com o valor da transferência: ";
								std::cin >> valor;
								bank->transacao(ptrCB, ptrCB2, valor);	//realizo a transação!
							}catch(int& ex){
								if(ex == 1)
									std::cout << "Conta não encontrada!" << std::endl;
							}

							break;
							}
							case 5:
							{
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
					if(ex == 1){
						std::cout << "Login inválido!" << std::endl;
						break;
					}
				}
				break;
			       }
			case 3:
			{
				bank->showClientes();
			}
		 	default:
		 		std::cout << "Entrada inválida! 1" << std::endl;
		}
	

		Console::iniciar();
		std::cout << "Entre com sua opção: ";
	 	std::cin >> opc;
		system("clear");
	}



	//libera a memoria
	delete bank;
	delete c;



    return 0;
}
