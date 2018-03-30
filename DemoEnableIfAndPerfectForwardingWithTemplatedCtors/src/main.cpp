/*
 * main.cpp
 *
 *  Created on: 20.03.2018
 *      Author: Gerd
 */

#include "Base.h"

#include <iostream>
#include <memory>
using namespace std;

/**	replaces std::make_unique to see how ...arg
 	is substituted and how ...Arg is deduced
 */
template<class T, class ...Arg>
std::unique_ptr<T> makeUnique(Arg&& ...arg){
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	return std::unique_ptr<T>(new T(std::forward<Arg>(arg)...));
}

int main(){
	cout << "DemoEnableIfAndPerfectForwardingWithTemplatedCtors" << endl;

	cout << "befor block" << endl;
	{
		cout << "Member m1, m2;" << endl;
		Member m1, m2;
		cout << "=== auto p1 = makeUnique<Base>(m1, m2);" << endl;
		auto p1 = makeUnique<Base>(m1, m2);
		cout << "=== auto p2 = makeUnique<Base>(Member(), Member());" << endl;
		auto p2 = makeUnique<Base>(Member(), Member());
		cout << "=== auto p3 = makeUnique<Base>(Member(), m2);" << endl;
		auto p3 = makeUnique<Base>(Member(), m2);
// remove comment and see error message remove Base::enableForMembersOnly and see it working !!!
//		cout << "=== auto p4 = makeUnique<Base>(1, 2);" << endl;
//		auto p4 = makeUnique<Base>(1, 2);
		cout << "end block" << endl;
	}
	cout << "after block" << endl;

}
