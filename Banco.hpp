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

        //pegará cada cofrinho dos clientes e colocará um valor constante.
        void setCofrinhos();    //como se fosse CDI, ira render grana

        void cleanClientes();    //limpa o set de clientes
        void cleanContasBancarias();


    private:
        //um set de ponteiros para clientes
        std::set<Cliente*> clientes;
        
        constexpr static double rendimento{0.5};
       

};



#endif
