#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <vector>
#include "Pessoa.hpp"
#include "Conta.hpp"

class ContaBancaria;
class Cliente : public Pessoa{
    public:
        Cliente();  
        Cliente(const std::string& nome, const unsigned short int idade, const unsigned long cpf, const unsigned int id, const std::string contato);
        ~Cliente();

        void adicionarConta(const ContaBancaria& novaConta);

        const std::vector<ContaBancaria>& getContas() const;

    private:
        unsigned int id;
        std::string contato;
        std::vector<ContaBancaria> contas; //faz a ligação com conta bancária
};



#endif