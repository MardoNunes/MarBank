#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>

class Pessoa{
    public:
        Pessoa();
        Pessoa(const std::string& nome, const unsigned short idade, const unsigned long cpf);
        ~Pessoa();


        std::string getNome() const;
        unsigned short int getIdade() const;
        unsigned long getCpf() const;

        void setNome();
        void setIdade();
        void setCpf();

        bool validarCPF(unsigned long cpfTeste) const;



    private:
        std::string fnome;
        unsigned char idade;
        unsigned long cpf;

};


#endif  