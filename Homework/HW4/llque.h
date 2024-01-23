/* header file for a template singly linked list class
 * 
 * Just as without assignments, the files are included in an unuual way
 * because template classes must be fully specified to compile and link.
 * 
 * That is why the file that implements the methods is included at the
 * bottom of this file
 */

#ifndef QADT_H
#define QADT_H

// We MUST HAVE a type with a NULL or default value defined because we
// are not using exceptions, so deQueue and peek need a value to return 
// when the queue is empty
template <class aType>
class llque {
	public:
		const llque<aType>& operator=(const llque<aType> &);
		// create an assignment operator for the list
		
		bool isEmpty() const;
		// isEmpty returns true if queue is empty
		
		bool isFull();
		// isFull returns true if queue is full
		
		aType deQueue();
		// deQueue returns the element at the head of the queue and removes it
			
		void enQueue(aType);
		// enQueue() inserts an element at the tail of the queue,
		
		aType peek();
		// peek() returns the value at the head of the queue without 
		// modifying the queue contents, prints error if empty
		
		void destroyllq();
		// delete everything and set head and tail to NULL
		
		llque();
		// default constructor, initialize head and tail to NULL
		
		llque(const llque<aType>& otherQ);
		// copy constructor, used for assignment and parameter passing
		
		~llque();
		// default destructor, must delete all the elements in the linked list
		
	private:
		// We declare the type used in the linked list here so it is visible for
		// compilation, it is only used here... can put the struct in the class
		
		struct nodeType{  // the node type for a singly linked list
			aType value;
			nodeType *next;
		};

		nodeType *head;
		nodeType *tail;
		
		void copyQ(const llque<aType>& otherQ);
		// This method is used for the copy constructor and assignment
		// operator

};


#include "llque.cpp"
#endif

