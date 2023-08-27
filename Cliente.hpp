#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "Pessoa.hpp"


class ContaBancaria;

class Cliente : public Pessoa{
	public:
		using Pessoa::Pessoa;	//usa o msm construtor;
		

		void adicionaConta( ContaBancaria* conta);
		ContaBancaria* getConta();

	
	private:
		ContaBancaria* conta;	//ponteiro para a conta bancaria do cliente
};




#endif
