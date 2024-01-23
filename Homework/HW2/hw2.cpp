/*method implementaitons
 * 
 * */

#include <iostream>
#include "hw2.h"

using namespace std;

	bool intque::isemptyq() {
		return count == 0;
	}
	
	bool intque::isfullq() {
		return count == MAXSIZE;
	}
	
	bool intque::enqueue(int newVal) {
		if (isfullq()) {
			cerr << "enqueue: Error, queue is full. ";
			return false;
		}
			else {
				//Note: we Add at the tail, store at tail and increment count
				que[tail] = newVal;
				count++;
				tail = (tail +1) % MAXSIZE;
			}
		return true;
	}
				
	
	int intque::dequeue(){
		int returnVal = -999999999;
		
		if (isemptyq()) {
			cerr << "dequeue: Error, queue is empty, return value invalid. ";
		}
		else {
			returnVal = que[head];
			count--;
			head = (head + 1) % MAXSIZE;
		}
		return returnVal;
	}
		
	
	int intque::peek(){
		int retVal = -999999999;
		
		if (isemptyq()){
			cerr << "peek error: que is empty, value is invalid. ";
		}
		else {
			retVal = que[head];
		}
		return retVal;
		//return que[tail];
	}


	intque::intque() {
		head = tail = count = 0;
	}
