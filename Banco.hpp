#ifndef BANCO_HPP
#define BANCO_HPP

#include <set>
#include <stdint.h>
#include "ContaBancaria.hpp"    

class Cliente;

class Banco{
    public:
        Banco();
        virtual ~Banco();


        void adicionaCliente(Cliente* cliente);
	    const Cliente* buscaCliente(const unsigned long cpf);
        void showClientes();
        const Cliente* buscaClienteNumeroConta(unsigned long numeroConta);
        void transacao(ContaBancaria* contaOrigem, ContaBancaria* contaDestino, double valor);
        bool vereficaExistencia(const unsigned long cpf);  //verifica se o cliente existe no banco
        void showContaBancaria(const Cliente* ptrC, const ContaBancaria* ptrCB);

    private:
        //um set de ponteiros para clientes
        std::set<Cliente*> clientes;
       

};



#endif
