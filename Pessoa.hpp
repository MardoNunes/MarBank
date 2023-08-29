#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>


class ContaBancaria;

class Pessoa{
    public:
        Pessoa();
	    Pessoa(const std::string& nome, const unsigned short idade);
        Pessoa(const std::string& nome, const unsigned short idade, const unsigned long cpf);
        virtual ~Pessoa();


        std::string getNome() const;
        unsigned short  getIdade() const;
        unsigned long getCpf() const;

        void setNome(const std::string& nome);
        void setIdade(const unsigned short idade);
        void setCpf(unsigned long cpfTeste);

        bool validarCPF(unsigned long cpfTeste) const;



    private:
        std::string nome;
        unsigned char idade;
        unsigned long cpf;

};


#endif  
