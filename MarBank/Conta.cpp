#include <iostream>
#include <string>
#include "Conta.hpp"
//#include "Cliente.hpp"



ContaBancaria::ContaBancaria(const Cliente& cliente):cliente(cliente){}
ContaBancaria::~ContaBancaria(){}

ContaBancaria::ContaBancaria(const float saldo, const float credito, const float fatura, const std::string& tipoConta, const Cliente& client):
saldo{saldo}, credito{credito}, fatura{0}, tipoConta{tipoConta}, cliente(client){

}

float ContaBancaria::getSaldo() const{
    return this->saldo;
}

void ContaBancaria::setSaldo(const float valor){
    this->saldo = this->saldo + valor;
}

float ContaBancaria::getCredito() const{
    return this->credito;
}

void ContaBancaria::setFatura(const float valor){
    this->fatura = this->fatura + fatura;
}

float ContaBancaria::getFatura() const{
    return this->fatura;
}

void ContaBancaria::Depositar(const float valor){
    this->saldo = this->saldo + valor;
}

void ContaBancaria::Sacar(const float valor){
    this->saldo = this->saldo - valor;
}

void Cliente* ContaBancaria::getCliente() const{
    return &cliente;
}

//tranferir()

//pix()

