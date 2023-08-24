#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "Pessoa.hpp"


class ContaBancaria;

class Cliente : public Pessoa{
	public:
		Cliente();
		Cliente(const std::string& nome, const unsigned short idade, const unsigned long cpf);
		~Cliente();
		

		void adicionaConta( ContaBancaria* conta);
		ContaBancaria* getConta();

	
	private:
		ContaBancaria* conta;	//ponteiro para a conta bancaria do cliente
};




#endif
