#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class aType {
	friend ostream& operator << (ostream&, const aType &);
	
public:
	bool operator>=(const aType&) const;
	bool operator==(const aType&) const;
	
	aType(string first = "", string last = "", int idnum = -1);
	
private:
	string fName;
	string lName;
	int    idNum;
};

// overload comparison for sorting by bstADT
bool aType::operator>=(const aType & otherPerson) const {
	bool retval = false;
	
	if (this->lName.compare(otherPerson.lName) > 0)
		retval = true;
	else if (this->lName == otherPerson.lName)
		retval = (this->fName.compare(otherPerson.fName) >= 0);
	return retval;
}

// overload comparison for search
bool aType::operator==(const aType & otherPerson) const {
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

aType::aType(string first, string last, int idnum){
	fName = first;
	lName = last;
	idNum = idnum;
}

// Overloaded output stream to disply aType
ostream& operator<< (ostream& theStream, const aType& thePerson) {
	theStream << "First: " << setw(20) << thePerson.fName 
				<< "  Last: " << setw(20) << thePerson.lName 
				<< "  ID#: " << thePerson.idNum;
	return theStream;
}
 
// The following line includes the template class
#include "bstADT.h"


int main(int argc, char *argv[]) {
	int i; // loop control variable
	bstADT<aType> people;  // the list we will check
	aType  testData[11] = {{"Harry", "Potter", 2010},
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
	bstADT<aType> clones; // to check assignment and copy
	
	cout << "============== Program 2 Tests ==================" << endl;
	
	cout << " 1 - Testing isEmpty for empty list: ";
	if (people.isempty()) {
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
	
	cout << " 3 - Testing min for empty tree (should get an error and 'empty' person): \n";
	cout << people.treeMin() << endl;
	cout << " 4 - Testing max for empty tree (should get an error and 'empty' person): \n";
	cout << people.treeMax() << endl;
	// Test printing with an empty list
	cout << " 5 - Testing printInOrder with an empty list (should be no output).\n";
	people.inOprint();
	
	cout << " 7 - Adding to list:  \n" << testData[0] << endl; // Harry Potter
	people.insert(testData[0]);
	cout << " 8 - Testing min:  ";
	if (people.min() == testData[0]) {
		cout << "passed\n";
	} else {
		cout << "FAILED\n";
	}
	cout << " 9 - Testing max:  ";
	if (people.max() == testData[0]) {
		cout << "passed\n";
	} else {
		cout << "FAILED\n";
	}
	
	// Test printing with only a single element
	cout << "10 - Testing printInOrder with a single element in list.\n";
	people.inOprint();

	
	cout << "12 - Add 5 more elements\n";
	for (i=1; i <= 5; i++) {
		people.insert(testData[i]);
	}
	// Test printing with multiple elements
	cout << "13 - Testing printInOrder .\n";
	people.inOprint();

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
	people.deleteNode(testData[9]);
	cout << "There should be six names in the list\n";
	people.inOprint();
	cout << "18 - Testing removeElement with existing name: \n";
	people.deleteNode(testData[4]);
	people.inOprint();
	cout << "19 - Remove the first name from the list\n";
	people.deleteNode(testData[5]);
	people.inOprint();
	cout << "20 - Remove the last name from the list\n";
	people.deleteNode(testData[3]);
	people.printInOrder();
	
	cout << "21 - Now destroy the list: ";
	people.deleteTree();
	if (people.isempty()) {
		cout << "passed\n";
	} else {
		cout << "FAILED\n";
	}
	
	clones.insert(testData[0]);
	for (i=0; i < 11; i++) { // add all eleven people to the list
		people.insert(testData[i]);
	}
	
	cout << "22 - Testing copy/assignment from list to non-empty list: \n";
	clones = people;
	cout << "The following should have eleven names: \n";
	clones.inOprint();
	
	cout<< "23 - Now James Kirk should be removed from the copy" << endl;
	clones.deleteNode(testData[8]);
	clones.inOprint();
	cout << "While the original is unchanged with 11 peopole\n";
	people.inOprint();
	
	cout << "24 - Assign a queue to itself, should not be empty\n";
	clones = clones;
	if (clones.isempty()) {
		cout << "Resulting queue is empty - FAILED\n";
	} else {
		cout << "Resulting queue is not empty, should have ten names: \n";
		clones.inOprint();
	}
	
	cout << "Now destroy both lists\n";
	clones.deleteTree();
	people.deleteTree();
	 
	cout << "------- Done --------\n\n";
	return 0;
}
