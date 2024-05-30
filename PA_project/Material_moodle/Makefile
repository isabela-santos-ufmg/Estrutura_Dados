
# Regra padrão
all: bin/pa1.out 

# Regra para construir o executável
bin/pa1.out: obj/PA.o | bin
	g++ -Wall -Wextra -std=c++11 obj/PA.o -o bin/pa1.out
# Regra para compilar objetos
obj/PA.o: src/PA.c | obj
	g++ -Wall -Wextra -std=c++11 -c src/PA.c -o obj/PA.o

test: bin/pa1.out
	bin/pa1.out -z 9 -s 27 -a q
