/* p2test.cpp
 * 09/21/2021
 * This is the test program for the implementation of the sorted list
 * ADT
 * 
 * Modified 09/26/2022 to add a test for the assignment operator when you 
 * assign a queue to itself (if it is destroyed it is an error)
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class personType {
	friend ostream& operator << (ostream&, const personType &);
	
public:
	bool operator>=(const personType&) const;
	bool operator==(const personType&) const;
	
	personType(string first = "", string last = "", int idnum = -1);
	
private:
	string fName;
	string lName;
	int    idNum;
};

// overload comparison for sorting by sortedListADT
bool personType::operator>=(const personType & otherPerson) const {
	bool retval = false;
	
	if (this->lName.compare(otherPerson.lName) > 0)
		retval = true;
	else if (this->lName == otherPerson.lName)
		retval = (this->fName.compare(otherPerson.fName) >= 0);
	return retval;
}

// overload comparison for search
bool personType::operator==(const personType & otherPerson) const {
	bool equal = true;
	
	if (otherPerson.lName != this->lName) {
		equal = false;
	} else if (otherPerson.fName != this->fName) {
		equal = false;
	} else if (otherPerson.idNum != this->idNum) {
		equal = false;
	}
	return equal;
}

personType::personType(string first, string last, int idnum){
	fName = first;
	lName = last;
	idNum = idnum;
}

// Overloaded output stream to disply personType
ostream& operator<< (ostream& theStream, const personType& thePerson) {
	theStream << "First: " << setw(20) << thePerson.fName 
				<< "  Last: " << setw(20) << thePerson.lName 
				<< "  ID#: " << thePerson.idNum;
	return theStream;
}
 
// The following line includes the template class
#include "sortedListADT.h"


int main(int argc, char *argv[]) {
	int i; // loop control variable
	sortedListADT<personType> people;  // the list we will check
	personType  testData[11] = {{"Harry", "Potter", 2010},
								{"Hermoine", "Granger", 2011},
								{"Albus", "Dumbledore", 1001},
								{"Severus", "Snape", 1520},
								{"John", "Sheridan", 3705},
								{"Delenn", "", 3892},
								{"G'Kar", "", 4140},
								{"David", "Sheridan", 3705},
								{"James", "Kirk", 2302},
								{"Spock", "", 2253},
								{"Leonard", "McCoy", 2247}};
	sortedListADT<personType> clones; // to check assignment and copy
	
	cout << "============== Program 2 Tests ==================" << endl;
	
	cout << " 1 - Testing isEmpty for empty list: ";
	if (people.isEmpty()) {
		cout << "passed\n";
	} else {
		cout << "FAILED\n";
	}
	
	cout << " 2 - Testing search for empty list: ";
	if (people.search(testData[0])) {
		cout << "FAILED\n";
	} else {
		cout << "passed\n";
	}
	
	cout << " 3 - Testing front for empty list (should get an error and 'empty' person): \n";
	cout << people.front() << endl;
	cout << " 4 - Testing back for empty list (should get an error and 'empty' person): \n";
	cout << people.back() << endl;
	// Test printing with an empty list
	cout << " 5 - Testing printInOrder with an empty list (should be no output).\n";
	people.printInOrder();
	cout << " 6 - Testing printRevOrder with an empty list (should be no output).\n";
	people.printRevOrder();
	
	
	cout << " 7 - Adding to list:  \n" << testData[0] << endl; // Harry Potter
	people.insertElement(testData[0]);
	cout << " 8 - Testing front:  ";
	if (people.front() == testData[0]) {
		cout << "passed\n";
	} else {
		cout << "FAILED\n";
	}
	cout << " 9 - Testing back:  ";
	if (people.back() == testData[0]) {
		cout << "passed\n";
	} else {
		cout << "FAILED\n";
	}
	
	// Test printing with only a single element
	cout << "10 - Testing printInOrder with a single element in list.\n";
	people.printInOrder();
	cout << "11 - Testing printRevOrder with a single element in list.\n";
	people.printRevOrder();
	
	cout << "12 - Add 5 more elements\n";
	for (i=1; i <= 5; i++) {
		people.insertElement(testData[i]);
	}
	// Test printing with multiple elements
	cout << "13 - Testing printInOrder .\n";
	people.printInOrder();
	cout << "14 - Testing printRevOrder.\n";
	people.printRevOrder();
	
	cout << "15 - Testing search with an existing element: ";
	if (people.search(testData[4])) {
		cout << "passed\n";
	} else {
		cout << "FAILED\n";
	}
	
	cout << "16 - Testing search with an non-existing element: ";
	if (people.search(testData[9])) {
		cout << "FAILED\n";
	} else {
		cout << "passed\n";
	}
	
	cout << "17 - Testing removeElement with non-existent element: \n";
	people.removeElement(testData[9]);
	cout << "There should be six names in the list\n";
	people.printInOrder();
	cout << "18 - Testing removeElement with existing name: \n";
	people.removeElement(testData[4]);
	people.printInOrder();
	cout << "19 - Remove the first name from the list\n";
	people.removeElement(testData[5]);
	people.printInOrder();
	cout << "20 - Remove the last name from the list\n";
	people.removeElement(testData[3]);
	people.printInOrder();
	
	cout << "21 - Now destroy the list: ";
	people.destroyList();
	if (people.isEmpty()) {
		cout << "passed\n";
	} else {
		cout << "FAILED\n";
	}
	
	clones.insertElement(testData[0]);
	for (i=0; i < 11; i++) { // add all eleven people to the list
		people.insertElement(testData[i]);
	}
	
	cout << "22 - Testing copy/assignment from list to non-empty list: \n";
	clones = people;
	cout << "The following should have eleven names: \n";
	clones.printInOrder();
	
	cout<< "23 - Now James Kirk should be removed from the copy" << endl;
	clones.removeElement(testData[8]);
	clones.printInOrder();
	cout << "While the original is unchanged with 11 peopole\n";
	people.printInOrder();
	
	cout << "24 - Assign a queue to itself, should not be empty\n";
	clones = clones;
	if (clones.isEmpty()) {
		cout << "Resulting queue is empty - FAILED\n";
	} else {
		cout << "Resulting queue is not empty, should have ten names: \n";
		clones.printInOrder();
	}
	
	cout << "Now destroy both lists\n";
	clones.destroyList();
	people.destroyList();
	 
	 cout << "------- Done --------\n\n";
	return 0;
}
