#ifndef CRIADOR_HPP
#define CRIADOR_HPP

#include "ContaBancaria.hpp"
#include "Pessoa.hpp"
//class ContaBancaria;

class Criador : public ContaBancaria{
	public:
		Criador();
		~Criador();

		void criarConta(Cliente* c, ContaBancaria* cb);
};

#endif
