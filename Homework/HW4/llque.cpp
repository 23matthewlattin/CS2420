/* method implementation file.  
 * 
 * Included in the header because this is a template. 
 * 
 * Name: Matthew Lattin 
 */
  


 
 
 

template <class aType>
const llque<aType>& llque<aType>::operator=(const llque<aType> &otherQ) {
// this same memory as otherList means delete then copy... except we
// would delete what we needed to copy

///What in the world?  What code goes here?  Must be pretty complex.
	if (this != &otherQ) { // don't do self assignment
		copyQ(otherQ);  // use the private copy method
	}


	return *this;
}

template <class aType>
bool llque<aType>::isEmpty() const {  // isEmpty returns true if queue is empty
	return (head == NULL && tail==NULL); 
	// could just check one, but this will also verify we are 
	// handling pointers properly
}

template <class aType>
bool llque<aType>::isFull(){ // isFull returns true if queue is full, for a linked list, it
	// is probably never full, unless we can't allocate a new node
	return false;
}

template <class aType>
aType llque<aType>::deQueue(){ // deQueue returns the element at the head 
	aType returnVal;
	nodeType *tmpNode = head; // initialize the poitner to the head
	
	if (isEmpty()) {
		cerr << "deQueue: ERROR - queue is empty, return value invalid.\n";
	} else {

/// What code belongs here???
		returnVal = head->value;   // get the return value
		head = tmpNode->next;      // set head to point to the next element
		if (tail == tmpNode)       // If this was the only element
			tail = NULL;           //     set tail to NULL too
		delete tmpNode;            // delete the node  
		





	}
	return returnVal;              // return the value
}
	
template <class aType>
void llque<aType>::enQueue(aType newVal) { // add an element at the tail of the queue,
	nodeType *newNode;  // Don't allocate here for consistency and errors
	
	if ((newNode = new nodeType) == NULL) { // error allocating node
		cerr << "enQueue: ERROR - failed to allocate node\n";
	} else {

/// looks like I forgot something here... what could it be
		newNode->value = newVal; // save the data
		newNode->next = NULL; // save the data
		if (isEmpty()) { // no nodes yet
			head = newNode; // make the head of the queue
		} else {
			tail->next = newNode; // insert after last element
		}
		tail = newNode; // and set tail to the new element



	}
}

template <class aType>                
aType llque<aType>::peek() { // look at the element at the head
	aType returnVal;
	if (isEmpty()) {
		cerr << "peek: ERROR - queue is empty, return value invalid.\n";
	} else {
		returnVal = head->value;   // get the return value
	}
	return returnVal;
}	

template <class aType>
void llque<aType>::destroyllq(){ // delete everything and set head and tail to NULL
	nodeType *tmp;
	
/// This is almost embarassing... what code fits here?
	while(!isEmpty()) {
		tmp = head;
		head = tmp->next;
		if(tmp == tail) tail = NULL;
		delete tmp;

	// all pointers should be NULL now
}

template <class aType>
llque<aType>::llque() { // default constructor, initialize head and tail to NULL
	head = tail = NULL;
}

template <class aType>
llque<aType>::llque(const llque<aType>& otherQ) { // for parameter passing
	copyQ(otherQ);
}

template <class aType>
llque<aType>::~llque() { // default destructor, must delete all the elements 
	destroyllq();
}

template <class aType>
void llque<aType>::copyQ(const llque<aType>& otherQ) {
// This method is used for the copy constructor and assignment
// operator
// We could use enQueue to perform the construction, but it would take more time
	nodeType *newNode;
	nodeType *current = otherQ.head; // initialize to other list pointer
	
	destroyllq();  // delete all the elements of the old queue


/// Darn, did it again... what is the name of this method again?
	if (!otherQ.isEmpty()) { // there are elements to copy
		while (current != NULL) { // the pointer to the otherQ points at something
			newNode = new nodeType;
			newNode->value = current->value;
			newNode->next = NULL;
			if (isEmpty()) { // we are copying the first element
				head = tail = newNode; // set head and tail to newNode
			} else {
				tail->next = newNode;
				tail = newNode;
			}
			current = current->next;
		} // end while
	} // end if



}
