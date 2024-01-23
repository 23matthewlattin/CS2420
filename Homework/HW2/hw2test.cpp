/* test program for homework
 * matthew lattin */
 
 #include <iostream>
 #include "hw2.h"
 
 using namespace std;
 
 int main (void) {
	 
	 intque myQue;
	 int i; //loop control variable
	 
	 cout << "testing is empty: ";
	 if (myQue.isemptyq()) { 
		cout << "Pass\n";
	 }
	 else {
		 cout << "Fail\n";
		}
		
		
	cout << "testing is full: ";
	 if (myQue.isfullq()) { 
		 cout << "Pass\n";
	 }
	 else {
		 cout << "Fail\n";
		}
		
	 cout << "testing dequeue: ";
	 if (myQue.dequeue()) { 
		 cout << "Fail\n";
	 }
	 else {
		 cout << "Pass\n";
		} 
		
		
	 cout << "testing enqueue: ";
	 if (myQue.enqueue(i)) { 
		 cout << "Pass\n";
	 }
	 else {
		 cout << "Fail\n";
		}
		
	 cout << "testing dequeue: ";
	 if (myQue.dequeue()) { 
		 cout << "Fail\n";
	 }
	 else {
		 cout << "Pass\n";
		} 
		
		
	cout << "testing peek: ";
	 if (myQue.peek()) { 
		 cout << "Fail\n";
	 }
	 else {
		 cout << "Pass\n";
		}
		
	/****************************************************************
	 * **************************************************************
	 * Testing in a for loop to check if the queue gets full. *******/
	 
	 cout << "testing in a for loop. *******************************\n";
	 
	 for(i=0; i <= MAXSIZE; ++i){
		 
	 
	 
	 cout << "testing is empty: ";
	 if (myQue.isemptyq()) { 
		 cout << "Pass\n";
	 }
	 else {
		 cout << "Fail\n";
		}
		
		
	cout << "testing is full: ";
	 if (myQue.isfullq()) { 
		 cout << "Pass\n";
	 }
	 else {
		 cout << "Fail\n";
		}
		
		
	 cout << "testing enqueue: ";
	 if (myQue.enqueue(i)) { 
		 cout << "Pass\n";
	 }
	 else {
		 cout << "Fail\n";
		}
		
    /* dequeue isn't used to test how enqueue works when there is no more
     * room */
	/* cout << "testing dequeue: ";
	 if (myQue.dequeue()) { 
		 cout << "Pass\n";
	 }
	 else {
		 cout << "Fail\n";
		} */
		
		
	cout << "testing peek: ";
	 if (myQue.peek()) { 
		 cout << "Fail\n";
	 }
	 else {
		 cout << "Pass\n";
		}
		
	}
}


