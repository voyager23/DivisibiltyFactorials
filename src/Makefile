# makefile for dev folder

all : factorial_primes.cxx toolbox.o
	g++ --std=c++11 -Wall -g -o factprimes toolbox.o factorial_primes.cxx
	
calcs : CalcS.cxx toolbox.o
	g++ --std=c++11 -Wall -g -o divfact toolbox.o CalcS.cxx
	
toolbox.o : toolbox.cxx
	g++ --std=c++11 -Wall -g -c -o toolbox.o toolbox.cxx
	
