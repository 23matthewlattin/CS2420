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
}

