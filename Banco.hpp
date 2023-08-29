#ifndef BANCO_HPP
#define BANCO_HPP

#include <set>
#include "ContaBancaria.hpp"    

class Cliente;

class Banco{
    public:
        Banco();
        virtual ~Banco();


        void adicionaCliente(Cliente* cliente);
	    const Cliente* buscaCliente(unsigned long cpf);
        void showClientes();
        const Cliente* buscaClienteNumeroConta(unsigned long numeroConta);
        void transacao(ContaBancaria* contaOrigem, ContaBancaria* contaDestino, float valor);

    private:
        //um set de ponteiros para clientes
        std::set<Cliente*> clientes;
       

};



#endif
