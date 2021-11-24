# makefile for source folder

# default target

map : maptest.cxx toolbox.o
	g++ -std=c++11 -Wall -g -o maptest toolbox.o maptest.cxx
	
dfact : toolbox.o
	g++ --std=c++11 -Wall -g -o dfact toolbox.o DivisibiltyFactorials.cxx
	
toolbox.o : toolbox.cxx
	g++ --std=c++11 -Wall -g -c -o toolbox.o toolbox.cxx
	
calcs : CalcS.cxx toolbox.o
	g++ --std=c++11 -Wall -g -o calcs toolbox.o CalcS.cxx
	
tbox : toolbox.cxx
	g++ --std=c++11 -Wall -g -o tbt toolbox.cxx
	
