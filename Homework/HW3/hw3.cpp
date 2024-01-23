

#include <iostream>
#include "hw3.h"

void bits::printlebits(void* ptr, int bytes) {
     char* onebyte = (char*)ptr; // Declare a pointer to a byte and initialize
                                   // to the address of the parameter
     int i;                        // loop control variable 

     if (bytes > 0) {
          printlebits((void*) (onebyte + 1), bytes - 1); // print higher order bytes first
          for (i = 7; i > -1; i--) { // print bits left to right (high to low)
               if (*onebyte & (1 << i)) {  // if the bit is 1, print '1'
                    cout << "1";
               }
               else {                  // otherwise print '0'
                    cout << "0";
               }
               if (i == 4 || i == 0)
                    cout << " ";
          }
     }
}  // end of function printlebits


void bits::printbebits(void* ptr, int bytes) {
     char* onebyte = (char*)ptr; // Declare a pointer to a byte and initialize
                                   // to the address of the parameter
     int i;                        // loop control variable 

     if (bytes > 0) { // print the first byte then the others
          for (i = 7; i > -1; i--) { // print bits left to right (high to low)
               if (*onebyte & (1 << i)) {  // if the bit is 1, print '1'
                    cout << "1";
               }
               else {                  // otherwise print '0'
                    cout << "0";
               }
               if (i == 4 || i == 0)
                    cout << " ";
          }
          printbebits((void*) (onebyte + 1), bytes - 1); // print the rest of the bytes
     }
}  // end of function printbebits
