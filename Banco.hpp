#ifndef BANCO_HPP
#define BANCO_HPP

#include <set>
#include "Cliente.hpp"

class Banco{
    public:
        Banco();
        ~Banco();


        void adicionaClinte();
        std::set<Cliente*>& getCliente() const;

    private:
        std::set<Cliente*> clientes;

};



#endif