/* 
 * sortedListADT.h 
 * mlh - 9/20/2021
 * The header file defining the class interface for a sorted list 
 * abstract data type.  This is a template class for the sorted list
 * and requires a friend function from the instantiating program to 
 * perform comparison.
 * 
 * Due to linking issues with template types, the method implementation 
 * file, "sortedListADT.cpp" is included at the end of this file.
 * 
 */
 
 #ifndef SLADT_H
 #define SLADT_H
 
template<class Type>
struct nodeType{  // the node type for a doubly-linked list
	Type value;
	nodeType<Type> *next;
	nodeType<Type> *prev;
};

 
template <class Type>
class sortedListADT {
public:
	const sortedListADT<Type>& operator=(const sortedListADT<Type> &);
	// overload the assignment operator for a sorted list
	bool isEmpty() const;
	// isEmptyQ determines whether the list is empty or not
	
	bool search(const Type& searchElem) const;
	// return true if searchItem is in the list
	
	void removeElement(const Type& remElem);
	// removeElement searches for the element passed as a parameter
	// and removes it from the list if  present, printing a message
	// if it is not found
		
	void insertElement(const Type& newElem);
	// insertElement puts the element at its sorted position in the 
	// list using the friend function for comparison
	
	Type front() const;
	// front() returns the value of the first element in the list
	
	Type back() const;
	// front() returns the value of the first element in the list
	
	void printInOrder() const;
	// prints the sorted list in order from first to last
	
	void printRevOrder() const;
	// prints the sorted list in reverse order from last to first
	
	void destroyList();
	// delete all nodes in the list and set first=last=NULL and
	// numElements=0
	
	sortedListADT();
	// default constructor for the sorted list, which is implemneted with a
	// doubly linked list
	
	sortedListADT(const sortedListADT<Type>& otherList);
	// copy constructor for sorted list to create a copy of the list
	
	~sortedListADT();
	// destructor to delete all the nodes from the list and reset
	// the first, last, and numElements values
	
private:
	nodeType<Type> *first;
	nodeType<Type> *last;
	int numElements;
	
	void copyList(const sortedListADT<Type>& otherList);
	// used to implement the assignment operator
};

// Now include the file containing the method implementations
// YOUR JOB IS TO WRITE THE FILE sortedListADT.cpp, implementing the above 
// methods
#include "sortedListADT.cpp"
#endif
