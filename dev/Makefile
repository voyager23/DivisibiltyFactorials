# makefile for dev folder

all: CalcS.cxx toolbox.o
	g++ -Wall -g -o divfact toolbox.o CalcS.cxx
	
toolbox.o : toolbox.cxx
	g++ -Wall -g -c -o toolbox.o toolbox.cxx
	
