#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>
#include <cstdint>


class ContaBancaria;

class Pessoa{
    public:
        Pessoa();
	    Pessoa(const std::string& nome, const unsigned short idade);
        Pessoa(const std::string& nome, const unsigned short idade, const uint32_t cpf);
        virtual ~Pessoa();


        std::string getNome() const;
        unsigned short  getIdade() const;
        uint32_t getCpf() const;

        void setNome(const std::string& nome);
        void setIdade(const unsigned short idade);
        void setCpf(uint32_t cpfTeste);

        bool validarCPF(uint32_t cpfTeste) const;



    private:
        std::string nome;
        unsigned char idade;
        uint32_t cpf;

};


#endif  
