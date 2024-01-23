/* 
 * queueADT.h 
 * mlh - 8/28/2021
 * The header file defining the class interface for the queueArray abstract
 * data type.  This queue can be implemented with different types.
 * 
 * Due to linking issues with template types, the method implementation 
 * file, "queueADT.cpp" is included at the end of this file.
 * 
 */
 
 #ifndef QADT_H
 #define QADT_H
 
// Define the default maximum size of the queue
#define DEFAULTSIZE 20
 
template <class Type>
class queueADT {
	public:
		bool isEmpty();
		// isEmptyQ determines whether a queue is empty or not, returning
		// true if the queue doesn't exist or is empty and false otherwise
		
		bool isFull();
		// isFullQ determines whether a queue is full or not, returning 
		// true if the queue is full and false otherwise
		
		Type deQueue();
		// deQueue returns the element at the head of the queue and removes 
		// it by incrementing the head, return null value on nonempty queue	
			
		void enQueue(Type);
		// enQueue() inserts an element at the tail of the queue, if the 
		// queue is not full, or no change if the queue is full
		
		Type peek();
		// peek() returns the value at the head of the queue without 
		// modifying the queue contents, prints error if empty
		
		queueADT(int size = DEFAULTSIZE);
		// queueADT is a constructor for initilializing a queue. By default
		// the size is defined by DEFAULTSIZE
		
	private:
		Type *lq;     // array for a local queue
		int maxsize;  // max number of elements in the queue
		int head;     // the index for the front of the queue
		int tail;     // the index of the tail of the queue
		int count;    // the current number of elements in the queue
};

// Now include the file containing the method implementations
// YOUR JOB IS TO WRITE THE FILE queueADT.cpp, implementing the queue 
// methods
#include "queueADT.cpp"
#endif
