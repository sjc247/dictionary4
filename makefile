DICTIONARY : dictionary.o main.o
	g++ dictionary.o main.o -o DICTIONARY

dictionary.o : dictionary.cpp dictionary.h
	g++ -c dictionary.cpp

main.o : main.cpp dictionary.h
	g++ -c main.cpp

