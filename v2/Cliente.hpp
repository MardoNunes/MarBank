#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <set>
#include "Pessoa.hpp"
#include "ContaBancaria.hpp"

class Cliente : public Pessoa{
	public:
		Cliente();
		Cliente(const std::string& nome, const unsigned short idade, const unsigned long cpf);
		~Cliente();
		

		void adicionaConta( ContaBancaria* conta);
		std::set<ContaBancaria*>& getConta();

	
	private:
		std::set<ContaBancaria*> contas;
};




#endif
