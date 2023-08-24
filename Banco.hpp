#ifndef BANCO_HPP
#define BANCO_HPP

#include <set>

class Cliente;

class Banco{
    public:
        Banco();
        ~Banco();


        void adicionaClinte(Cliente* cliente);
        void showClientes();

    private:
        //um set de ponteiros para clientes
        std::set<Cliente*> clientes;
       

};



#endif