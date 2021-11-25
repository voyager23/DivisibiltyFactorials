# makefile for source folder

# default target
tbox : toolbox.cxx
	g++ --std=c++11 -Wall -g -pg -o tbt toolbox.cxx
	
map : maptest.cxx toolbox.o
	g++ -std=c++11 -Wall -g -o maptest toolbox.o maptest.cxx
	
dfact : toolbox.o
	g++ --std=c++11 -Wall -g -o dfact toolbox.o DivisibiltyFactorials.cxx
	
toolbox.o : toolbox.cxx
	g++ --std=c++11 -Wall -g -c -o toolbox.o toolbox.cxx
	
calcs : CalcS.cxx toolbox.o
	g++ --std=c++11 -Wall -g -o calcs toolbox.o CalcS.cxx
	

	
