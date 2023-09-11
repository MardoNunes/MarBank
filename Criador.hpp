#ifndef CRIADOR_HPP
#define CRIADOR_HPP

#include "ContaBancaria.hpp"
#include "Pessoa.hpp"
#include "Cliente.hpp"
#include "Banco.hpp"


class Criador : public ContaBancaria{
	public:
		Criador();
		~Criador();

		void criarConta(Cliente* c, ContaBancaria* cb, Banco* bank);
		void geraClientes(Banco* const bank);
};

#endif
