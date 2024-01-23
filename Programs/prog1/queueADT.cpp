/* By: Matthew Lattin
 * Date: 9/04/2023
 * Desription: Implement methods for a queue as an array
 * */
 

	//return true if there are no values in the array
	template <class Type>
	bool queueADT<Type>::isEmpty(){
		//the count changes when values are added and removed
		return count == 0;	
	}
	
	//return true if the array is full and can't hold more values
	template <class Type>
	bool queueADT<Type>::isFull(){
		//maxsize is the size of the array being called. 
		//when maxsize and count are the same all values have been 
		//added to the array 
		return count == maxsize;	
	}
	
	//remove the value at the head of the queue
	//increase where the head is making the queue smaller
	template <class Type>
	Type queueADT<Type>::deQueue(){
		//retVal is a var of type Type which means it can be of any 
		//type that the array is called as
		//retVal used to return the value of the queue as it is removed
		Type retVal;
		if(isEmpty()){
			cout << "Error: the queue is empty, no values to remove.\n\n";
		}
		else{
			//return value is value at current head of the queue
			retVal = lq[head];
			
			//head increases to move to next value in the local queue lq
			head = (head + 1) % maxsize;
			
			//count goes down because another value has been removed 
			//queue and count of 0 will indicate empty queue
			count--;
			
		}
		return retVal;			
	}
	
	//add values to the queue if there is room for more values
	template <class Type>
	void queueADT<Type>::enQueue(Type t){
			
		if (isFull()){
			cout << "Error: the queue is full, can't complete enqueue.\n\n";
		}
		else {
			//value at tail of queue is equal to the value that is 
			//entered when this array is called
			//saved to local queue lq
			lq[tail] = t;
			
			//tail is now higher so next value in lq can be added
			tail = (tail + 1) % maxsize;
			
			//count increases so that it is known when the queue reaches
			//its maxsize
			count++;
		}
	}
	
	//return the value found at the head of the queue if there is a
	//value inside the queue
	template <class Type>
	Type queueADT<Type>::peek(){
		if(isEmpty()){
			cout << "Error: the queue is empty, no values to peek.\n\n";
		}
		//if there are values in local queue lq then the value at the 
		//current head of the queue is returned. 
		return lq[head];
	}
	
	//constructor
	//sets the default value for maxsize of queue
	template <class Type>
	queueADT<Type>::queueADT(int size){
		maxsize = size;
		
		//lq = local array with a size of value entered when the 
		//constructor is called
		lq = new Type[maxsize];
		
	}
	


