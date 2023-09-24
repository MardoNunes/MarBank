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
	c->geraClientes(bank);	//gera clientes para o banco, para que nao tenha so vc


	 Console::iniciar();
	 short opc;
	 short opc2;
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
				try{
					bank->adicionaCliente(ptrC);
				}
				catch(int& ex){
					if(ex == 3){
						std::cout << "Não foi possivel adicionar cliente!" << std::endl;
						exit(1);
					}
				}

				system("clear");
				Console::menuConta();
				std::cout << "Entre com sua opção: ";
				std::cin >> opc2;
				while(opc2 != 8){
					switch(opc2){
						case 1:	//mostra os dados da conta
						{
							system("clear");
							bank->showContaBancaria(ptrC, ptrCB);
							break;
						}
						case 2:	//realiza deposito
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
						case 3:	//realiza saque
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
						case 4:	//realiza transferencia
						{
							unsigned long numeroConta;
							const Cliente* ptrC2;
							ContaBancaria* ptrCB2;
							std::cout << "Entre com o numero da conta: ";
							std::cin >> numeroConta;
							try{
								ptrC2 = bank->buscaClienteNumeroConta(numeroConta);	//busca o cliente pelo numero da conta
								ptrCB2 = ptrC2->getConta();	//pega a conta do cliente encontrado
								double valor;
								std::cout << "Entre com o valor da transferência: ";
								std::cin >> valor;
								bank->transacao(ptrCB, ptrCB2, valor);	//realizo a transação!
							}catch(int& ex){
								if(ex == 1)
									std::cout << "Conta não encontrada!" << std::endl;
							}
							//libera a memoria
							delete ptrCB2;
							delete ptrC2;							
							break;
						}
						case 5:	//adiciona valor ao cofringo
						{
							std::cout << "Entre com o valor: ";
							double valor;
							std::cin >> valor;
							ptrCB->adicionaCofrinho(valor);
							break;
						}
						case 6:	//mostra o valor do cofrinho
						{
							std::cout << "Valor do cofrinho: " << ptrCB->getCofrinho() << std::endl;
							break;
						}
						case 7:	//resgata valor no cofrinho
						{
							std::cout << "Entre com o valor a ser resgatado: ";
							double resgatar;
							std::cin >> resgatar;
							try{
								ptrCB->resgataCofrinho(resgatar);
							}
							catch(int& ex){
								if(ex == 1)
									std::cout << "Valor inválido!" << std::endl;
							}
						}
						default:
							std::cout << "Entrada inválida!" << std::endl;
					}
					
					Console::menuConta();
					std::cout << "Entre com sua opção: ";
					std::cin >> opc2;	
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
					ptrC = bank->buscaCliente(cpf);	//resgata o cliente pelo cpf
					ContaBancaria* ptrCB;
					ptrCB = ptrC->getConta();
					       
					//colocar tela menuContaBancaria
					//tratar as entradas
					system("clear");
					Console::menuConta();
					std::cout << "Entre com sua opção: ";
					std::cin >> opc2;
					while(opc2 != 8){
						switch(opc2){
							case 1:
							{
								system("clear");
								bank->showContaBancaria(ptrC, ptrCB);
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
							ContaBancaria* ptrCB2;
							std::cout << "Entre com o numero da conta: ";
							std::cin >> numeroConta;
							
							try{
								ptrC2 = bank->buscaClienteNumeroConta(numeroConta);	//busca o cliente pelo numero da conta
								ptrCB2 = ptrC2->getConta();	//pega a conta do cliente encontrado
								double valor;
								std::cout << "Entre com o valor da transferência: ";
								std::cin >> valor;
								bank->transacao(ptrCB, ptrCB2, valor);	//realizo a transação!
							}catch(int& ex){
								if(ex == 1)
									std::cout << "Conta não encontrada!" << std::endl;
							}

							//libera a memoria
							delete ptrCB2;
							delete ptrC2;

							break;
							}
							case 5:	//adiciona valor ao cofringo
							{
								std::cout << "Entre com o valor: ";
								double valor;
								std::cin >> valor;
								ptrCB->adicionaCofrinho(valor);
								break;
							}
							case 6:	//mostra o valor do cofrinho
							{
								std::cout << "Valor do cofrinho: " << ptrCB->getCofrinho() << std::endl;
								break;
							}
							case 7:	//resgata valor no cofrinho
						{
							std::cout << "Entre com o valor a ser resgatado: ";
							double resgatar;
							std::cin >> resgatar;
							try{
								ptrCB->resgataCofrinho(resgatar);
							}
							catch(int& ex){
								if(ex == 1)
									std::cout << "Valor inválido!" << std::endl;
							}
						}
							default:
								std::cout << "Entrada inválida!" << std::endl;
						}
						
						Console::menuConta();
						std::cout << "Entre com sua opção: ";
						std::cin >> opc2;
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
				break;
			}
		 	default:
		 		std::cout << "Entrada inválida! " << std::endl;
		}
	
		bank->setCofrinhos();	//rende um quantia em todos o cofrinhos
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
