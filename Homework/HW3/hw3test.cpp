/* By: Matthew Lattin
 * Date: 09/08/2023
 * Description: test of bit representations
 * 
 * */
 
 #include <iostream>
 #include "hw3.h"

 
 using namespace std;
 
	int main (void){
		bits bitsTest;
		
		int intA = 12;
		int intB = 12;
	
		bitsTest.printlebits(&intA, 4);
		bitsTest.printbebits(&intB, 4);
		
		float floatA = 12.23;
		float floatB = 12.23;
		
		bitsTest.printlebits(&floatA, 4);
		bitsTest.printbebits(&floatB, 4);
		
		string stringA = "Helloworld";
		string stringB = "Hellowworld";
		
		bitsTest.printlebits(&stringA, 4);
		bitsTest.printbebits(&stringB, 4);
		
		return 0;
	
	}
