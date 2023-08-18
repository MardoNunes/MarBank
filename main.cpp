#include <iostream>
#include "Pessoa.hpp"
#include "Cliente.hpp"
#include "Conta.hpp"





int main(){
    Cliente c1{"Mardoqueu", 20, 11111111111, 1, "(41)99999-9999"};
    ContaBancaria conta{400.00, 50, 0, "Poupança", c1};

    c1.adicionarConta(conta);

    //Acessar a conta associada ao cliente
    const std::vector<ContaBancaria>& contasDoCliente = c1.getContas();
    const ContaBancaria& contaDoCliente = contasDoCliente[0]; // Supondo que existe apenas uma conta
    std::cout << "Saldo: " << contaDoCliente.getSaldo() << std::endl;
    std::cout << "Crédito: " << contaDoCliente.getCredito() << std::endl;
    const Cliente* clienteAssociado = contaDoCliente.getCliente();
    std::cout << "Nome: " << clienteAssociado->getNome() << std::endl;

    
    




    return 0;
}