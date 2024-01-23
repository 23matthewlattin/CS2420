/* this is a quick test program for the linked list queue provided 
 * in homework 4.
 */
#include <iostream>

using namespace std;

#include "llque.h"

int main(void) {
	
	int i, j, k; // don't know if I will use these
	
	// create the list
	llque<int> myintQ;
	
	cout << "Test isEmpty... should be true ";
	if (myintQ.isEmpty()) {
		cout << "pass\n";
	} else { 
		cout << "FAIL\n";
	}
	
	cout << "Test enqueue for '3', value returned from peek: ";
	myintQ.enQueue(3);
	cout << myintQ.peek() << "  ";
	if (myintQ.peek() != 3) {
		cout << "FAIL\n";
	} else {
		cout << "pass\n";
	}
	
	
	
	return 0;
	
}
