#ifndef CONTA_HPP
#define CONTA_HPP

#include <boost/math/constants/constants.hpp>


class ContaBancaria{
    public:
        ContaBancaria();
        ContaBancaria(const cpp_dec_float_50 saldo, const cpp_dec_float_50 credito, const cpp_dec_float_50 fatura, const std::string& tipoConta);
        ~ContaBancaria();

        cpp_dec_float_50 getSaldo() const;
        void setSaldo(cpp_dec_float_50 valor);

        void transferir(const cpp_dec_float_50 valor);
        void pix(const cpp_dec_float_50 valor); //pix tem um limite máximo no valor!
        
        cpp_dec_float_50 getCredito() const;    //quanto de credito eu tenho, n gastos!
        void setFatura( const cpp_dec_float_50 valor);  //acrescenta valore a fatura;
        cpp_dec_float_50 getFatura() const; //quanto de credito gastos!


        void Depositar(const cpp_dec_float_50 valor);
        void Sacar(const cpp_dec_float_50 valor);
        //implementar uma função para ver sua key!

    private:
        unsigned long key;  //será usada para transações
        cpp_dec_float_50 saldo;
        cpp_dec_float_50 credito;
        cpp_dec_float_50 fatura;
        std::string tipoConta; //posso tentar fazer um enumeration;

};




#endif