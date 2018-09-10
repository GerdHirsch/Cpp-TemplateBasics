/*
 * main.cpp
 *
 *  Created on: 25.06.2015
 *      Author: Gerd
 */


#include "Host.h"
#include "Base.h"
#include "NoCheckPolicy.h"
#include "CheckPolicy.h"

#include <iostream>
using namespace std;

int main(){
	cout << "PolicyBasedDesign" << endl;
	Base b;
	Derived d;

	typedef Host<Derived, NoCheck<Derived> > DerivedNoCheck;
	std::cout << std::endl<< "main(): DerivedNoCheck dnc1(&d);" << std::endl;
	DerivedNoCheck dnc1(&d);
	std::cout << std::endl<< "main(): DerivedNoCheck dnc2(dnc1);" << std::endl;
	DerivedNoCheck dnc2(dnc1);
	std::cout << std::endl<< "main(): DerivedNoCheck dnc3(0);" << std::endl;
	DerivedNoCheck dnc3(0);
	std::cout << std::endl<< "main(): dnc3 = dnc1;" << std::endl;
	dnc3 = dnc1;

	typedef Host<Base, Check<Base> > BaseCheck;
	std::cout << std::endl<< "main(): BaseCheck bc1(&d);" << std::endl;
	BaseCheck bc1(&d);
	std::cout << std::endl<< "main(): BaseCheck bc2(dnc1);" << std::endl;
	BaseCheck bc2(dnc1);

	typedef Host<Other, NoCheck<Other> > OtherNoCheck;
	//OtherNoCheck onc(dnc1); //error: cannot convert 'Derived*' to 'Other*' in initialization

	// NullPointer Exception: Pointer must not be null!
	// NullPointer Exception: Pointer must not be null!
	//BaseCheck bc3(0);

	// darf nicht möglich sein
	//typedef Host<Base, NoCheck<Base> > BaseNoCheck;
	//error: no matching function for call to 'NoCheck<Base>::NoCheck(const Host<Base, Check<Base> >&)
	//no known conversion for argument 1 from 'const Host<Base, Check<Base> >' to 'const NoCheck<Base>&'
	//BaseNoCheck bnc4(bc1);
}
