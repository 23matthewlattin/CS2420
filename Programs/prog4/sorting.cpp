/* Name: Matthew Lattin
 * Date: 11/06/2023
 * Description: This program will take a binary I/O file with up to 
 * 1,000,000 records and compare the time it takes different algortims 
 * to sort the files. The code to read and write binary files has been 
 * taken from the homework assignment to read and write binary files. 
 */
#include <iostream> /* general I/O streams */
#include <fstream>  /* file I/O */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time for random seed */
#include <ctime>

using namespace std;

//**************************bubble sort****************//
void bubbleSort(int A[], int length) {
	bool didSwap;
	int tmpVal, i, j;
	std::clock_t c_start = std::clock();  // start timer
	for (i = 0; i <= length-1; i++) {
		didSwap = false;
		for (j = length; j >= i + 1; j--){
			if (A[j] < A[j-1]){
				//swap (A[j], A[j-1]); can use this. This won't swap array elements
				tmpVal = A[j]; //create a var to store value to swap
				A[j] = A[j-1];	//set j to j-1. j is now bigger than j-1
				A[j-1] = tmpVal; //set j-1 to what j was. j-1 now smaller
				didSwap = true;	
			}//end if 
		}//end inner for loop
	}//end outer for loop
	std::clock_t c_end = std::clock();    // end timer
	long double time_elapsed_sec = (long double)(c_end - c_start) / CLOCKS_PER_SEC;
	std::cout << "CPU time used: " << time_elapsed_sec << " sec\n";
}//end bubble sort
			
//*****************quick sort**********************//
//partion function comes first, so it can be used in the quicksort function
int partition(int A[], int p, int r) {
	int i, j, x;
	int tmpVal;
	x = A[r]; //x = right value
	i = p-1;
	for (j = p; j <= r-1; j++){  //j = left value
		if (A[j] <= x) { //if left value less than right value
			i++;
			tmpVal = A[i]; //create a var to store value to swap
			A[i] = A[j];	//set a[i] to a[j]
			A[j] = tmpVal; //set a[j] to what a[i] was
		}//end if
	}//end for
	
	tmpVal = A[i + 1]; //create a var to store value to swap
	A[i + 1] = A[r];	//set a[i + 1] to a[r]
	A[r] = tmpVal; //set a[r] to what a[i+1] was		
	return i+1;
}//end partition

void quickSort(int A[], int p, int r) {
	int q;
	if (p < r){ //if left less than right
		q = partition(A, p, r);	//set q to a partition of left and right		
		quickSort(A, p, q-1); //sort one partion that was created
		quickSort (A, q+1, r); //sort the other partition created
	}//end if

}//end quicksort	

//********************end quick sort*****************//
	


int main (void) {
	string filename;   // name to store the generated data
	int i;             // loop control variable
	int count;          // the number of values to store in the file
	int theNum;        // the random number (values in range 0 - 100,000,000)
	int end, begin, size;
	ifstream infile;  // input file nandle

	
	
	//*********Read in the file ********************************/ 
	
	cout << "please enter the name of the data file to read: ";
	cin >> filename;  // file to read
	
	infile.open(filename.c_str(), ios::binary);  // open the file
	//find how big the file is
	begin = infile.tellg();
	infile.seekg(0, ios::end);
	end = infile.tellg();
	size = end - begin;
	count = size/sizeof(int);
	infile.seekg(0, ios::beg);
	//create the arrays to be a size equal to size of binary file read in
	int* fileArray = new int[count]; //array to store values read in
	int* bubbleArray = new int[count]; //array to store copy of values read in. use 
							//for bubble sort
	int* quickArray = new int[count]; //array to store copy of values read in. use for
						  //quick sort
	i = 0;
	while(!infile.eof()) { 							//loop through the file read in
		infile.read((char*) &theNum, sizeof(int));
		fileArray[i]= theNum; //set array at index i to the number read
							  //in from the file
		i++;
	}
						  
	/*for (i=0; i < count; i++){
		(infile.read((char*) &theNum, sizeof(int))))//read in the file
			fileArray[i]= theNum; //set array at index i to the number read
							  //in from the file
	}
	* */

	//test bubbleSort*********************************************************
	//copy fileArray into bubbleArray
	for (i =0; i < count; i++) {
		bubbleArray[i] = fileArray[i]; 
	}
	bubbleSort(bubbleArray, count-1); //run bubbleArray
	//print out results from bubbleSort
	for (int i =0; i < 20; i++) {
		//print 1st 20 values from sorted array. If entire array is printed
		//it can exceed the amount of lines that can be shown
		cout << " Bubble Array value: "<< i << ": " << bubbleArray[i] << endl;
	}
	cout << endl;
	//end test bubbleSort
	
	//test quickSort***********************************************************
	//copy fileArray into quickArray
	for (i =0; i < count; i++) {
		quickArray[i] = fileArray[i]; 
	}
	std::clock_t c_start = std::clock();  // start timer
	quickSort(quickArray, 0, count-1);	
		std::clock_t c_end = std::clock();    // end timer
		long double time_elapsed_sec = (long double)(c_end - c_start) / CLOCKS_PER_SEC;
		std::cout << "CPU time used: " << time_elapsed_sec << " sec\n";
	//print results from quickSort
	for (i =0; i < 20; i++) {
		//print 1st 20 values from sorted array. If entire array is printed
		//it can exceed the amount of lines that can be shown
		cout << " Quick Array value: " << i << ": " << quickArray[i] << endl;
	}
	
	cout << endl;
	//end test quickSort

	infile.close(); // close the file
	
	cout << "We read " << count << " integers from the file\n";
}
