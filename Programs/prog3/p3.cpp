/*
  * Name: Matthew Lattin
  * Date: 10/10/23
  * Description: This is the 3rd programming assingment. This creates a hash
  * table that uses open hashing to store the values in linked lists. 
  * The code from hw06.cpp in the hash table homework assignment was 
  * taken to use as a starting point for the 3rd programming assignment.
  * 
  */

#include <iostream>		/* general I/O streams */
#include <fstream>		/* file I/O */
#include <iomanip>		/* I/O formatting commands */
#include "sortedListADT.h"
#include "GeneralHashFunctions.cpp"																			

using namespace std;	// needed because I'm lazy and don't feel std:: adds to 
						// understnading the program

#define FIXED_IO(x) fixed << setw(5) << setprecision(2) << x
#define HASHSIZE 211 //this will be used to define an array of HASHSIZE size

int main(){
	
	string filename = "";	// used to capture the input file name
	string inputStr = "";	// general input string
	int i, j;				// loop control variables
	ifstream inFile; 		// Input text file
	unsigned int hashVal;	// hash value returned by the function
	sortedListADT<string> hashTable[HASHSIZE]; //declares an array of sortedListADT with
											   //a string type and a size of HASHSIZE
	/*
	 * Open the data file, should be text strings
	 */
	cout << "please enter the name of the data file to read: ";
	cin >> filename;	// file to write to
	
	inFile.open(filename);
	if (!inFile) {
		cerr << "Unable to open input file, exiting!\n";
		exit(1);		// input file failure
	}
	/* 
	 * Read in the input file, count the number of strings read
	 */
	while(getline(inFile,inputStr)){  // read a line from the file
		hashVal = RSHash(inputStr);   //***** Compute the hash
		i = hashVal % HASHSIZE; //set int i to be equal to the new found hashVal % HASHSIZE
								//to set i to the new found remainder
		hashTable[i].insertElement(inputStr); //take the input string from the file read in
											  //and insert at value i of hashTable
	} // strings read in and hash collisions counted
	
	cout << "\n----------    Test Results    -----------\n";
	cout << "Hash function used:  Robert Sedgwick\n";
	// output the results for each linked list used
	for (i=0; i < HASHSIZE; i++) {
			cout << " Hash Values: " << i << endl; //output i
			hashTable[i].printInOrder(); //output the elements stored at i using
										 //printInOrder from sortedListADT
			cout << "\n\n";   			 //new line to seperate each list 
	}
	return 0;
}
