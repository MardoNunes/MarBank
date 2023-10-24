parametrosCompilacao=-Wall -g #-Wshadow
nomePrograma=MarBank

all: $(nomePrograma)

$(nomePrograma): main.o Pessoa.o Criador.o ContaBancaria.o Console.o Cliente.o Banco.o 
	g++ -o $(nomePrograma) main.o Pessoa.o Criador.o ContaBancaria.o Console.o Cliente.o Banco.o  $(parametrosCompilacao)

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)

Pessoa.o: Pessoa.hpp Pessoa.cpp
	g++ -c Pessoa.cpp $(parametrosCompilacao)

Criador.o: Criador.hpp Criador.cpp
	g++ -c Criador.cpp $(parametrosCompilacao)

ContaBancaria.o: ContaBancaria.hpp ContaBancaria.cpp
	g++ -c ContaBancaria.cpp $(parametrosCompilacao)

Console.o: Console.hpp Console.cpp
	g++ -c Console.cpp $(parametrosCompilacao)

Cliente.o: Cliente.hpp Cliente.cpp
	g++ -c Cliente.cpp $(parametrosCompilacao)

Banco.o: Banco.hpp Banco.cpp
	g++ -c Banco.cpp $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
