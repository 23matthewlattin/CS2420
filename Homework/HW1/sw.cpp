/* sw.cpp implements template class method */

template <class myType>
void swapClass<myType>::swap12(void) {
    swap(var1, var2);
}  

template <class myType>
void swapClass<myType>::swap13(void) {
    swap(var1, var3);
}  

template <class myType>
void swapClass<myType>::swap23(void) {
    swap(var2, var3);
}

// Private function to swap any two values of myType 
template <class myType>
void swapClass<myType>::swap(myType& first, myType& second) {
    myType temp = first; // local variable of type myType
    first = second;
    second = temp;
}

