/* Use this program to run your test cases for homework 6.  We are looking 
 * at hash functions and the number of collisions we might have in a data 
 * set.  
 * 
 * The provided input file is text and contains 400 randomly generated
 * names.  You may generate a larger data set using http://www.randat.com/.
 * The data set was created 200 names at a time, a limitation of the website.
 * The data was then exported as xls files, and the contents were combined
 * into a single file.  I then used MicroSoft Excel to export the file as a 
 * tab delimited text file, which I edited by replaing the tab with a space 
 * and removing the header line and ensuring the final name has a newline.  
 * 
 */

#include <iostream>		/* general I/O streams */
#include <fstream>		/* file I/O */
#include <iomanip>		/* I/O formatting commands */
#include "GeneralHashFunctions.h"  // library of hash functions from 
						// https://www.partow.net/programming/hashfunctions/

using namespace std;	// needed because I'm lazy and don't feel std:: adds to 
						// understnading the program

#define FIXED_IO(x) fixed << setw(5) << setprecision(2) << x
#define NUMTAB 6

// This main program asks for the data file name then uses ONE of the 
// hash functions provided to see how many collisions occurred
int main(){
	string filename = "";	// used to capture the input file name
	string inputStr = "";	// general input string
	int i, j;				// loop control variables
	ifstream inFile; 		// Input text file
	unsigned int hashVal;	// hash value returned by the function
	int tableSizes[NUMTAB] = { 101, 10007, 401, 1009, 2003, 10007};  // prime numbers
	int countArray[tableSizes[NUMTAB-1]][NUMTAB] = {0};	// Array to count the collisions
	int collision[NUMTAB][2] = {0};
	int numberRead = 0;
	
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
		hashVal = FNVHash(inputStr);   //***** Compute the hash
		for (i=0; i < NUMTAB; i++) {
			countArray[hashVal % tableSizes[i]][i] += 1;  // Count entries per row
		}
		numberRead++;
	} // strings read in and hash collisions counted
	
	// Now output how many collisions occurred... any array value more than 1
	// indicates a collision.  We keep two counts, table rows with collisions 
	// and the total number of  strings that had a hash collision
	for(i=0; i < tableSizes[NUMTAB-1]; i++) {
		for(j=0; j < NUMTAB; j++) {
			if (countArray[i][j] > 1) {
				collision[j][0]++; // number of table rows
				collision[j][1] += countArray[i][j]; // number of entries affected
			}
		}
	}
	
	// Now print out the results includin:
	//    the number of rows in the table (usually a prime number)
	//    the rows that have multiple values
	//    the number of input strings that had collisions
	// If the number of rows is less than the number of strings input there
	// must be collisions and we would use "open hashing" with a linked list
	// for each table row
	cout << "\n----------    Test Results    -----------\n";
	cout << "Hash function used:  Robert Sedgwick\n";
	cout << "Total number of strings in the input file: " << numberRead << endl;
	// output the results for each table size used
	for (i=0; i < NUMTAB; i++) {
		cout << "Table size: " << setw(4) << tableSizes[i] << 
		" Table rows with collisions: " << setw(3) << collision[i][0] << " (" 
		<< FIXED_IO(100.0 * collision[i][0]/tableSizes[i])<< 
		"%) \t entries affected: " << setw(3) << collision[i][1] << " ("  << 
		FIXED_IO(100.0 * collision[i][1]/numberRead) << "%)\n";
	}
	cout << endl;
	return 0;
}
