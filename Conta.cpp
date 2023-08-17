#include <iostream>
#include <boost/math/constants/constants.hpp>
#include <string>
#include "Conta.hpp"

using boost::multiprecision::cpp_dec_float_50;

ContaBancaria::ContaBancaria(){}

ContaBancaria::ContaBancaria(const cpp_dec_float_50 saldo, const cpp_dec_float_50 credito, const cpp_dec_float_50 fatura, const std::string& tipoConta):
saldo{saldo}, credito{credito}, fatura{0}, tipoConta{tipoConta}{

}

cpp_dec_float_50 ContaBancaria::getSaldo() const{
    return this->saldo;
}

void ContaBancaria::setSaldo(const cpp_dec_float_50 valor){
    this->saldo = *this + valor;
}

cpp_dec_float_50 ContaBancaria::getCredito() const{
    return this->credito;
}

void ContaBancaria::setFatura(const cpp_dec_float_50 valor){
    this->fatura = *this + fatura
}

cpp_dec_float_50 ContaBancaria::getFatura() const{
    return this->fatura;
}

void ContaBancaria::Depositar(const cpp_dec_float_50 valor){
    this->saldo = *this + valor;
}

void ContaBancaria::Sacar(const cpp_dec_float_50 valor){
    this->saldo = *this - valor;
}

//tranferir()

//pix()

