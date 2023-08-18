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

        void setNome(const std::string& nome);
        void setIdade(const unsigned short int idade);
        void setCpf(const unsigned long cpf);

        bool validarCPF(unsigned long cpfTeste) const;



    private:
        std::string nome;
        unsigned char idade;
        unsigned long cpf;

};


#endif  