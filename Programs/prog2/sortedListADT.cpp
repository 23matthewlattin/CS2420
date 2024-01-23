/* By: Matthew Lattin
 * Date: 10/04/2023
 * Desription: Program 2. Sorted doubly linked lists
 * */
 
// default constructor for the sorted list, which is implemneted with a
// doubly linked list
template <class Type>
sortedListADT<Type>::sortedListADT() 
{
	first = nullptr;				//no values in list so the defaults are null
	last = nullptr;
	numElements = 0;
}//end default constructor
	
// copy constructor for sorted list to create a copy of the list
template <class Type>
sortedListADT<Type>::sortedListADT(const sortedListADT<Type>& otherList) 
{
	copyList(otherList);    //calls copy command to copy the list
}//end copy constructor

// destructor to delete all the nodes from the list and reset
// the first, last, and numElements values
template <class Type>
sortedListADT<Type>::~sortedListADT()
{
	destroyList();		//cal function that deletes all elements in list
}//end destructor
	
// used to implement the assignment operator
template <class Type>
void sortedListADT<Type>::copyList(const sortedListADT<Type>& otherList) 
{
		
	destroyList(); //delete elements of old list

	nodeType<Type> *current = otherList.first; //set current to the other list
		
	//first = current;
	while (current != nullptr) //current points to a value 
	{ 
		nodeType<Type>* newNode = new nodeType<Type>;
		newNode->value = current->value; //copy otherList values to this list
		if (isEmpty()) 
		{ 
			first = last = newNode;		//for first value first and last = same value 
		} 
		else 
		{
			last->next=newNode;			//newNode goes after last value in list
			newNode->prev = last;		//value at last is value before the newNode
			last=newNode;				//set last to now equal the newNode
		}
		current = current->next;		//move to next value in otherList
		numElements++;					//increment the count
	} // end while
}//end copyList
	

	// overload the assignment operator for a sorted list
	template <class Type>
	const sortedListADT<Type>& sortedListADT<Type>::operator=(const sortedListADT<Type> &otherList) 
	{
		if (this != &otherList) 
		{ 
			copyList(otherList);  
		}
		return *this;
	}//end assignment operator

// isEmptyQ determines whether the list is empty or not
template <class Type>
bool sortedListADT<Type>::isEmpty() const
{
	return (first == nullptr && last == nullptr); //return if no values in list
}//end isEmpty
	
// return true if searchItem is in the list
template <class Type>
bool sortedListADT<Type>::search(const Type& searchElem) const
{
	nodeType<Type> *current = first; //start search from first value in list
	while(current != NULL)	
		{
			if(current->value == searchElem)
			{
				return true;		//return when value is found
			}//end if
			else 
			{	
				current=current->next;	//move to next value in list
			}//end else
		}//end while
	return false; //if value not found return false
}//end search	

// removeElement searches for the element passed as a parameter
// and removes it from the list if  present, printing a message
// if it is not found
template <class Type>
void sortedListADT<Type>::removeElement(const Type& remElem)
{
	nodeType<Type> * current = first;
	while (current != nullptr && !(current->value == remElem))
	{
		current = current->next;	//move to next value in list
	}//end while
	if (current != nullptr)
	{
		if (current == first)
		{
			//if there is more than one value 
			if (last == first)
			{
				first = last = nullptr;
			}
			//if there is only one value in the list
			else
			{
				first = first->next;
				first->prev= nullptr;
			}
		}//end if
		//if the remove element is the last
		else if (current == last)
		{
			last = last->prev;
			last->next = nullptr;				
		}//end else if
		//remove if in middle
		else 
		{	
			current->next->prev = current->prev;
			current->prev->next = current->next;
		}//end else 
		delete current;
		numElements--;		//decrement the count of elements
	}//end if
	else
	{
		std::cout << "Element not found in list\n";  //print if value not in list
	}//end else
}//end remove element
	
// insertElement puts the element at its sorted position in the 
// list using the friend function for comparison
template<class Type>	
void sortedListADT<Type>::insertElement(const Type& newElem) 
{
	nodeType<Type>* newNode = new nodeType<Type>;
	newNode->value = newElem;
	nodeType<Type> *current = first;
	newNode->prev = newNode->next = nullptr;
		
	//insert to empty list
	while (current != nullptr && newNode->value >= current->value)
	{	
		current=current->next;		//go to next value in list
	} //end while
	if (isEmpty())
	{					
		first = last = newNode;	
		numElements++;	
			
	}//end if
	//insert at front
	else if(current == first)
	{
		newNode->next = current;
		current->prev = newNode;
		first = newNode;		
		numElements++;				//increment the count
	} //end if
	//insert at end
	else if (current == nullptr)
	{
		newNode->prev = last;
		last->next=newNode;
		last = newNode;
		numElements++;				//increment the count	
	} //end else if
	//insert in middle
	else 
	{
		newNode->prev = current->prev;
		newNode->next = current;
		current->prev->next = newNode;
		current->prev = newNode;
		numElements++;				//increment the count	
	}  //end else
} //end insert element

// front() returns the value of the first element in the list
template <class Type>
Type sortedListADT<Type>::front() const 
{
	Type retVal;  //set a var to return if there is no value in list
	nodeType<Type> *current = first; //set current to begin of list
	if(first != NULL)
	{
		return current->value;  //return first value
	}
	else 
	{
		std::cout << "ERROR: front(). List is empty" << std::endl;
	}
	return retVal;				//return no value when list is empty
}//end front
	
// back() returns the value of the first element in the list
template <class Type>
Type sortedListADT<Type>::back() const 
{
	Type retVal;  //set a var to return if there is no value in list
	nodeType<Type> *current = last; //set current to end of list
	if (last != NULL)
	{
		return current->value;  //return last value
	}
	else 
	{
		std::cout << "ERROR: back(). List is empty" << std::endl;
	}
	return retVal; 				//return no value when the list is empty
}//end back
	
// prints the sorted list in order from first to last
template <class Type>
void sortedListADT<Type>::printInOrder() const
{	
	int count = 0;
	nodeType<Type> *current = first; //set current to the start of the list
	while(current != nullptr) //stop when there are no more values in list
	{
		count++;
		std::cout << count << " - " << current->value << std::endl; //print next value in list
		current = current->next; //move to next element in the list
	}
}//end printInOrder
	
// prints the sorted list in reverse order from last to first
template <class Type>
void sortedListADT<Type>::printRevOrder() const 
{
	nodeType<Type> *current = last; //set current to end of list
	int count = 0;
	while(current != nullptr) //continue unitll start of list is reached
	{
		count++;
		std::cout << count << " - " << current->value << std::endl; //print prev value in list
		current = current->prev;  //move to the previous value in the list
	}
}//end printRevOrder

// delete all nodes in the list and set first=last=NULL and
// numElements=0
template <class Type>
void sortedListADT<Type>::destroyList() 
{
	nodeType<Type> *current;
	while (!isEmpty()) //run unitll no values left in list
	{
		current = first;		//start from first value in list
		first = first->next;	//move to next value in list
		if(first == nullptr)
		{
			last = nullptr;
		}
		numElements--;
		delete current;			//delete the current first value in the list
	}//end while
	//set first, last, and numElements to defaults when 
	//list is gone
	first = nullptr;			
	last = nullptr;
	numElements =0;					
}//end destroy list
