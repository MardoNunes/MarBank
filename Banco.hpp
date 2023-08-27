#ifndef BANCO_HPP
#define BANCO_HPP

#include <set>

class Cliente;

class Banco{
    public:
        Banco();
        ~Banco();


        void adicionaCliente(Cliente* cliente);
	const Cliente* buscaCliente(unsigned long cpf);
        void showClientes();

    private:
        //um set de ponteiros para clientes
        std::set<Cliente*> clientes;
       

};



#endif
