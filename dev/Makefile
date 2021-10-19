# makefile for dev folder

all: CalcS.cxx toolbox.o
	g++ --std=c++11 -Wall -g -o divfact toolbox.o CalcS.cxx
	
toolbox.o : toolbox.cxx
	g++ --std=c++11 s-Wall -g -c -o toolbox.o toolbox.cxx
	
