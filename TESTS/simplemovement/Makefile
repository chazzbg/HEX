
BASEDIR = /home/chazz/HEX

HEXAPODDIR = $(BASEDIR)/LIB_HEXAPOD


HEXAPOD = $(HEXAPODDIR)/hexapod.cpp $(HEXAPODDIR)/hexapod.h

LIBS = -D_GNU_SOURCE=1 -D_REENTRANT -pthread -lpthread -lrt -ldl -lm

simple : main.cpp $(HEXAPOD) 
	g++ -std=c++0x -O3 -g -o simple main.cpp $(HEXAPOD) $(LIBS)

clean :
	rm -f simple
