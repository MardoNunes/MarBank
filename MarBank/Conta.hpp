#ifndef CONTA_HPP
#define CONTA_HPP

#include "Cliente.hpp"


class Cliente;
class ContaBancaria{
    public:
        ContaBancaria(const Cliente& cliente);
        ContaBancaria(const float saldo, const float credito, const float fatura, const std::string& tipoConta, const Cliente& client);
        ~ContaBancaria();

        const Cliente* getCliente() const;

        float getSaldo() const;
        void setSaldo(float valor);

        void transferir(const float valor);
        void pix(const float valor); //pix tem um limite máximo no valor!
        
        float getCredito() const;    //quanto de credito eu tenho, n gastos!
        void setFatura( const float valor);  //acrescenta valore a fatura;
        float getFatura() const; //quanto de credito gastos!


        void Depositar(const float valor);
        void Sacar(const float valor);
        //implementar uma função para ver sua key!

    private:
        unsigned long key;  //será usada para transações
        float saldo;
        float credito;
        float fatura;
        std::string tipoConta; //posso tentar fazer um enumeration;

        const Cliente& cliente;

};




#endif
