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
	int theNum;        // the number read from the file
	ifstream infile;  // input file nandle
	int minSoFar, maxSoFar; //ints to store then smallest and largest numbers
	
	cout << "please enter the name of the data file to read: ";
	cin >> filename;  // file to write to
	
	infile.open(filename.c_str(), ios::binary);  // open the file
	
	minSoFar = 999999999;
	maxSoFar = -1;
	nums = 0;
	
	while(!infile.eof()) {
		infile.read((char*) &theNum, sizeof(int));
		cout << "Read numer: " << theNum << endl;
		if (minSoFar > theNum) minSoFar = theNum;
		if (maxSoFar < theNum) maxSoFar = theNum;
		nums++;
	}
	
	infile.close(); // close the file
	
	cout << "We read " << nums << "integers from the file\n";
	cout << "Minimum: " << minSoFar << "\tMaximum: " << maxSoFar << endl;
	
	return 0;
	
}

