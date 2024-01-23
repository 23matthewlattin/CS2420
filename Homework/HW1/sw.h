/*template class definition */

#ifndef TEMPDONE
#define TEMPDONE
template <class myType>
class swapClass {
public:
	void swap12(void);
	void swap13(void);
	void swap23(void);
    myType var1, var2, var3;
private:
    void swap(myType&, myType&);
};

#include "sw.cpp"
#endif
