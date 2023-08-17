#include <iostream>
#include "Pessoa.hpp"
#include "Cliente.hpp"
#include "Conta.hpp"

#include <boost/math/constants/constants.hpp>



int main(){
    Cliente c1{"Mardoqueu", 20, 11111111111, 1, "(41)99843-1833"};
    Conta conta{400.00, 50, 0, "Poupança"};

    c1.adicionarConta(conta);

    std::cout << "Saldo: " << c1.getSaldo() << std::endl;
    std::cout<< "Crédito: " << c1.getCredito() << std::endl;




    return 0;
}