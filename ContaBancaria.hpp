#ifndef CONTA_BANCARIA_HPP
#define CONTA_BANCARIA_HPP





#include "Cliente.hpp"
#include "Banco.hpp"


class ContaBancaria{

	public:
		ContaBancaria();
		ContaBancaria(const unsigned long numeroConta, const double saldo);
		ContaBancaria(const double saldo);
		~ContaBancaria();

		unsigned long getNumeroConta() const;
		void  setNumeroConta(const unsigned long novoNumero);

		double getSaldo() const;
		void setSaldo(const double valor);	//atualiza o saldo!


		void sacar(const double valor); 
		void gerarNumero();

		
		double getCofrinho() const;
		void adicionaCofrinho(const double valor);
		void resgataCofrinho(const double resgatar);

	private:
		unsigned long numeroConta;	//numero realizado para transasções
		double saldo;
		double cofrinho;	//cofrinho sera uma valor que ira ser acrescentado enquanto estiver na conta

};


#endif
