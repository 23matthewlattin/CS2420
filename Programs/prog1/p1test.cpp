/*  p1test.cpp
 *  mlh - 8/28/2021
 *  This is the test program for implementing a queue as an array
 *  The template class is instantiated and tested with two types to 
 *  verify correct operation.
 */
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// The following line includes the template class
#include "queueADT.h"


int main(int argc, char *argv[]) {
	
	// declare two queues, one of strings and one of int
	queueADT<int> intQueue(5);
	queueADT<string> stringQueue(7);
	// declare test values to use
	int testint[10] = {5, 2, 3, 7, 11, 13, 17, 19, 23, 29};
	string teststring[10] = {"Harry Potter", "Hermoine Granger", 
							"Albus Dumbledore", "Severus Snape",
							"John Sheridan", "Delenn", "G'Kar",
							"James Kirk", "Spock", "Leonard McCoy"};
							
	int returnint;       // used to test returned value from dequeue
	string returnstring; // used to test returned value from dequeue
	int i; // loop control variable 
	
	//----------------No declarations beyond this point----------------//
	
	// Test 01 "isEmpty" for intQueue
	cout << "Testing isEmpty for an empty queue: " ;
	if (intQueue.isEmpty()) {
		cout << "passed" << endl;
	} else {
		cout << "FAILED"<< endl;
	}
	
	// Test 02 "isFull" for stringQueue
	cout << "Testing isFull for an empty queue: " ;
	if (stringQueue.isFull()) {
		cout << "FAILED" << endl;
	} else {
		cout << "passed"<< endl;
	}

	// Test 03 enqueue for both intQueue and stringQueue
	intQueue.enQueue(testint[0]);
	stringQueue.enQueue(teststring[0]);
	
	// Test 04 check function of peek and see if value was enqueued
	if (intQueue.peek() == testint[0]) {
		cout << "Function peek confirms enqueue for integer" << endl;
	} else {
		cout << "Function peek or enQueue FAILED for integers" << endl;
	}
	
	if (stringQueue.peek() == teststring[0]) {
		cout << "Function peek confirms enqueue for string" << endl;
	} else {
		cout << "Function peek or enQueue FAILED for strings" << endl;
	}
	
	// Test 05 & 06 check isEmpty and isFull for non-empty and non-full queues
	cout << "Testing isEmpty for a non-empty queue: " ;
	if (intQueue.isEmpty()) {
		cout << "FAILED" << endl;
	} else {
		cout << "passed"<< endl;
	}
	
	cout << "Testing isFull for a non-empty and non-full queue: " ;
	if (stringQueue.isFull()) {
		cout << "FAILED" << endl;
	} else {
		cout << "passed"<< endl;
	}
	
	// Test 07 check deQueue, value returned
	returnint = intQueue.deQueue();
	returnstring = stringQueue.deQueue();
	
	cout << "deQueue for int type ";
	if (returnint == testint[0]) {
		cout << "passed" << endl;
	} else {
		cout << "FAILED" << endl;
	}
	cout << "deQueue for string type ";
	if (returnstring == teststring[0]) {
		cout << "passed" << endl;
	} else {
		cout << "FAILED" << endl;
	}
	
	// Test 08 "isEmpty" for intQueue
	cout << "Testing isEmpty after dequeue: " ;
	if (intQueue.isEmpty()) {
		cout << "passed" << endl;
	} else {
		cout << "FAILED"<< endl;
	}
	
	// Test 09 "isFull" for stringQueue
	cout << "Testing isFull after dueue: " ;
	if (stringQueue.isFull()) {
		cout << "FAILED" << endl;
	} else {
		cout << "passed"<< endl;
	}
	
	// Test 10 Maximum capacity of intQueue, enqueue 5 values
	for (i=1; i <= 5; i++) {
		cout << "Enqueue " << setw(2) << testint[i] << " ";
		intQueue.enQueue(testint[i]);
		cout << " --->  enqueue complete" << endl;
	}
	
	// Test 11 test fail on enqueue for next element
	cout << "Enqueue " << testint[6] << " ";
	intQueue.enQueue(testint[6]);
	cout << " --->  enqueue complete, should have error message" << endl;
	
	// Test 12 "isFull" for intQueue
	cout << "Testing isFull for full queue: " ;
	if (intQueue.isFull()) {
		cout << "passed" << endl;
	} else {
		cout << "FAILED"<< endl;
	}
	
	// Test 13 "isEmpty" for intQueue as full queue
	cout << "Testing isEmpty for full queue: " ;
	if (intQueue.isEmpty()) {
		cout << "FAILED" << endl;
	} else {
		cout << "passed"<< endl;
	}
	

	// Test 14 dequeue four elements, testing their values:
	for (i=1; i <= 4; i++) {
		cout << "Dequeue " << setw(2) << testint[i] << " ";
		if (intQueue.deQueue() != testint[i]) {
			cout << "bad value: FAILED" << endl;
		} else {
			cout << "passed" << endl;
		}
	}
	cout << "intQueue now contains only " << testint[5] << endl;
	
	// Test 15 add remaining elements for intQueue
	for(i=7; i < 10; i++) { // bad design choice to use "10" 
		cout << "Enqueue " << setw(2) << testint[i] << " ";
		intQueue.enQueue(testint[i]);
		cout << " --->  enqueue complete" << endl;
	}
		
	// Test 16 dequeue all integers 
	cout << "Dequeue " << testint[5] << " ";
	if (intQueue.deQueue() != testint[5]) {
		cout << "bad value: FAILED" << endl;
	} else {
		cout << "passed" << endl;
	}
	for (i=7; i < 10; i++) {
		cout << "Dequeue " << setw(2) << testint[i] << " ";
		if (intQueue.deQueue() != testint[i]) {
			cout << "bad value: FAILED" << endl;
		} else {
			cout << "passed" << endl;
		}
	}		
	
	// Test 18 check for empty queue
	cout << "Trying to dequeue from intQueue, should be empty. " << endl;
	returnint = intQueue.deQueue();
	cout << "Returned value: " << returnint << 
			" should have had error message" << endl;
	
	// Test 19 use while loop to file the string queue
	i = 0; // we will enqueue from the start of our array
	while (!stringQueue.isFull()) {
		cout << "stringQueue.enQueue value: " << setw(16) << left << teststring[i] << " ";
		stringQueue.enQueue(teststring[i]);
		cout << " ---> enqueue complete" << endl;
		i++;
	}
	
	// current status
	cout << "stringQueue is full, " << i << " strings added (should be 7)" << endl;
	
	// Test 20 enqueue to a full queue of strings
	cout << "Attempt to enqueue " << teststring[i] << endl;
	stringQueue.enQueue(teststring[i]);
	cout << "stringQueue.enQueue should have generated an error message" << endl;
	
	// Test 21: Verify queue order
	i = 0;
	while (!stringQueue.isEmpty()) {
		cout << "Dequeue " << setw(16) << left << teststring[i] << " returned value: " << 
				stringQueue.deQueue() << endl;
		i++;
	}
	
	// Test 21 error message from peek if queue is empty (value must be returned)
	cout << "stringQueue.peek() from empty queue should return error" << endl;
	cout << "Peek returns " << stringQueue.peek() << endl;
	
	cout << endl << "Tests complete" << endl; 
}
