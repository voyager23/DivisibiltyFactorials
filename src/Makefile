# Cxx Makefile Template

.PHONY : clean all go

CFLAGS = -Wall -ggdb
LIBS =

OBJECTS = DivisibiltyFactorials.o library.o

HEADERS = DivisibiltyFactorials.hxx library.hxx

OBJS = $(addprefix ../obj/, $(OBJECTS) )
HDRS = $(addprefix ../inc/, $(HEADERS))
OUT = ../obj/$@

RUNFILE = ../bin/DivisibiltyFactorials

all : $(OBJECTS) $(HDRS)
	g++ $(CFLAGS) $(OBJS) $(LIBS) -o $(RUNFILE)

DivisibiltyFactorials.o : DivisibiltyFactorials.cxx $(HDRS)
	g++ -c $(CFLAGS) $< -o $(OUT)
	
library.o : library.cxx $(HDRS)
	g++ -c $(CFLAGS) $< -o $(OUT)

# ----------------------------------------------------------------------

go :
	@echo "Running file $(RUNFILE)"
	$(RUNFILE)
	



