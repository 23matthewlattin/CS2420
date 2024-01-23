/* This program generates a binary data file of random numbers to use in 
 * testing sorting algorithms.
 */
#include <iostream> /* general I/O streams */
#include <fstream>  /* file I/O */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time for random seed */

using namespace std;


int main (void) {
	string filename;   // name to store the generated data
	int i;             // loop control variable
	int nums;          // the number of values to store in the file
	int theNum;        // the random number (values in range 0 - 100,000,000)
	ofstream outfile;  // output file nandle
	ifstream infile;  // input file nandle
	int minSoFar, maxSoFar; //ints to store then smallest and largest numbers
	
	srand (time(NULL));  /* initialize random seed: */
	
	cout << "please enter the name of the data file to create: ";
	cin >> filename;  // file to write to
	cout << "How many integers to write to the file? ";
	cin >> nums;      // number of integers to write
	
	outfile.open(filename.c_str(), ios::binary);  // open the file
	
	for (i=0; i < nums; i++ ) {  // loop to generate the numbers
		theNum = rand() % 100000000; // generate an integer value up to 100M
		outfile.write((char * ) &theNum, sizeof(int));  // store the value
	}
	
	outfile.close(); // close the file
	
	cout << "please enter the name of the data file to read: ";
	cin >> filename;  // file to write to
	
	infile.open(filename.c_str(), ios::binary);  // open the file
	
	minSoFar = 1000000000; //number is bigger than any number that will be generated. Ensure actual min is found
	maxSoFar = -1; //small so the actual max is always found
	nums = 0; //count number of values read in 
	
	while(!infile.eof()) { 							//loop through the file read in
		nums++;
		infile.read((char*) &theNum, sizeof(int));
		cout << "Read number: " << theNum << endl;
		if (minSoFar > theNum) minSoFar = theNum;	//find smallest value in file
		if (maxSoFar < theNum) maxSoFar = theNum;	//find biggest value in file
		
	}
	
	infile.close(); // close the file
	
	cout << "We read " << nums << " integers from the file\n";
	cout << "Minimum: " << minSoFar << "\tMaximum: " << maxSoFar << endl;
	
}


