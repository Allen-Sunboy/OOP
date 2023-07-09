all: test

test: main.o product.o sum.o
	g++ main.o product.o sum.o -o main

main.o: main.cpp functions.h
	g++ -c main.cpp -o main.o

product.o: product.cpp functions.h
	g++ -c product.cpp -o product.o
	
sum.o: sum.cpp functions.h
	g++ -c sum.cpp -o sum.o

clean:
	rm *.o main

debug: main.o2 product.o2 sum.o2
	g++ main.o product.o sum.o -o main
	
main.o2: main.cpp functions.h
	g++ -c main.cpp -o main.o -D DEBUG

product.o2: product.cpp functions.h
	g++ -c product.cpp -o product.o -D DEBUG
	
sum.o2: sum.cpp functions.h
	g++ -c sum.cpp -o sum.o -D DEBUG
