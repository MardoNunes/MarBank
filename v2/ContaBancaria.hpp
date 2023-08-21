#ifndef CONTA_BANCARIA_HPP
#define CONTA_BANCARIA_HPP

class ContaBancaria{
	public:
		ContaBancaria();
		ContaBancaria(const std::string nome, const unsigned long numeroConta, const float saldo);
		ContaBancaria(const std::string nome);
		~ContaBancaria();

		unsigned long getNumeroConta() const;
		void  setNumeroConta(const unsigned long novoNumero);

		float getSaldo() const;
		void setSaldo(const float valor);	//atualiza o saldo!

		std::string getNome() const;
		void setNome(const std::string nome);

		void sacar(const float valor); 

	private:
		std::string nome;
		unsigned long numeroConta;	//numero realizado para transasções
		float saldo;
};


#endif
