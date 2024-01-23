# A Makefile for homework 6
# NOTE:  Because we have separate files we MUST compile to object files 
# and link them together to create the executable
#
hw06: hw06.o GeneralHashFunctions.o
	g++ -o hw06 hw06.o GeneralHashFunctions.o
	
hw06.o: hw06.cpp GeneralHashFunctions.h
	g++ -c hw06.cpp

GeneralHashFunctions.o: GeneralHashFunctions.cpp GeneralHashFunctions.h
	g++ -c GeneralHashFunctions.cpp
	
clean:
	rm *.o hw06
