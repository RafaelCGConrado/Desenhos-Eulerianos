all: grafo.o  main.o
	gcc grafo.o  main.o -o grafo -std=c99 -Wall

grafo.o:
	gcc -c grafo.c -o grafo.o


main.o:
	gcc -c main.c -o main.o
	 
clean:
	rm *.o grafo

run:
	./grafo
