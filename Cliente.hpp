#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <boost/math/constants/constants.hpp>
#include <vector>
#include "Pessoa.hpp"
#include "Conta.hpp"

class Cliente : public Pessoa{
    public:
        Cliente();  
        Cliente(const std::string& nome, const unsigned short int idade, const unsigned long cpf, const unsigned int id, const std::string contato);
        ~Cliente();

        void adicionarConta(const Conta novaConta);

        const std::vector<Conta>& getContas() const;

    private:
        unsigned int id;
        std::string contato;
        std::vector<Conta> contas; //faz a ligação com conta bancária
};



#endif