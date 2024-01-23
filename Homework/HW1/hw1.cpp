/*hw1.cpp
*this is homework #1 which implements a simple template
* made by me....
* By: Matthew Lattin
*/
 
#include <iostream>
#include "sw.h"
using namespace std;


int main(void) {
	swapClass<int> intSwap;
	swapClass<string> strSwap;
	
	intSwap.var1 = 20;						//set int values to swap
	intSwap.var2 = 40;
	intSwap.var3 = 60;
	
	cout << "Initial intSwap values: " << intSwap.var1 << "\t" <<
		intSwap.var2 << "\t" << intSwap.var3 << endl;
	intSwap.swap12();
	intSwap.swap23();
	intSwap.swap12();
	
	cout << "After swapping values:  " << intSwap.var1 << "\t" <<
		intSwap.var2 << "\t" << intSwap.var3 << endl;
		
		
	strSwap.var1 = "baseball";				// set string values to swap
	strSwap.var2 = "basketball";
	strSwap.var3 = "football";
	
	cout << "Initial strSwap values: " << strSwap.var1 << "\t" <<
		strSwap.var2 << "\t" << strSwap.var3 << endl;
	strSwap.swap12();
	strSwap.swap23();
	strSwap.swap12();
	
	cout << "After swapping values:  " << strSwap.var1 << "\t" <<
		strSwap.var2 << "\t" << strSwap.var3 << endl;

		
}
