/*  This is a header file for an template class of a binary search tree
 * 
 * NOTE:  This requires a type with comparison operations for <, >, and ==
 */
 
#ifndef SLADT_H
#define SLADT_H


// structure for nodeType
template 
struct nodeType {
	aType value;
	nodeType	*parent,
					*left,
					*right;
};


template  class bstADT {

public:
	const bstADT& operator=(const bstADT &);
	// overload of the assignment operator for a binary search tree
	
	bool isempty(void);
	// returns true for an empty tree
	
	bool search(aType value);
	// method to search for a value, returns true if the value is in the 
	// tree
	
	void inOrder(void);
	// prints the elements of the tree "in-Order", need output stream to
	// be defined for aType     i.e.,  cout << aTypeVar   must work
	
	void insert(aType);
	// method to insert a value in the list
	
	bool deleteNode(aType);
	// deletes a value if it exists, returning true if deleted and false 
	// if it is not found
	
	int treeHeight(void);
	// returns the height of the tree
	
	bstADT(const bstADT& sourceTree);
	// default copy constructor
	
	bstADT(void);
	// default constructor for a bst
	
	~bstADT(void);
	// default destructor, will use deleteTree for the root node
	
private: 

	nodeType *root;    // pointer for the root of the tree
	nodeType *curNode; // pointer to node operated on by last method
	

////////////////////////////////////////////////////////////////////////
//      The following are private utility methods                     //
////////////////////////////////////////////////////////////////////////

	void inOprint(nodeType *);
	// function to traverse the tree in order and print the values, requires
	// pointer to the tree root
	
	nodeType *nextInOrder(nodeType *);
	// function to return a pointer to the next inOrder node
	
	// utility functions to return pointer to the min and max value nodes
	nodeType *treeMin(nodeType *);
	nodeType *treeMax(nodeType *);
	
	void transplant(nodeType *, nodeType *);
	// a utility function to "transplant" nodes in the tree, takes two node
	// pointers as an argument and swaps their positions in the tree
	
	nodeType *deleteTree(nodeType *); 
	// delete all the nodes in a tree
	
	void copyTree(nodeType* &,  
				nodeType*, const nodeType* );
	// makes a copy of the tree, deleting destTree if necessary, dTreep is 
	// the parent of the new tree
	
	nodeType * searchTree(nodeType *root, aType theVal);
	// search the subtree with "root" as the root of the subtree
	// return a pointer to the node if found, otherwise a nullptr value
	
	int nHeight(nodeType *aNode);
	// Determines the height of the tree with root aNode
	
	int max(int x, int y);
	// return the maximum of two integer values
};
#include "bstADT.cpp"
#endif
