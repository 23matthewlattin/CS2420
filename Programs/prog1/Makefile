# This is the makefile for program 1 in CS 2420
# each thing "made" has a target name, a list of dependencies, and a rule
# The format is:
# <target name>: <list of dependencies>
# <tab character> <rule to make the target>

all: p1test

p1test: p1test.o 
	g++ -o p1test p1test.o
	
p1test.o: queueADT.h p1test.cpp
	g++ -c p1test.cpp
		
clean:
	rm *.o p1test
