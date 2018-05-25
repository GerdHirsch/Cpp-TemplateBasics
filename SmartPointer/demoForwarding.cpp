/*
 * demoForwarding.cpp
 *
 *  Created on: 22.03.2018
 *      Author: Gerd
 */
#include "UniquePointer.h"
#include "A3MemberBC.h"


#include <iostream>
using namespace std;

void demoForwarding(){
	cout << "demoForwarding" << endl;

	cout << "=== befor block" << endl;
	{
		cout << "=== B m1; C m2;" << endl;
		B m1; C m2;
//		cout << "=== auto p1 = makeUnique<A>(m1, m2);" << endl;
//		auto p1 = makeUnique<A>(m1, m2);
		cout << "=== A a(B(), C());" << endl;
		A a(B(), C());
//		cout << "=== auto p2 = makeUnique<A>(B(), C());" << endl;
//		auto p2 = makeUnique<A>(A(), B());
//		cout << "=== auto p3 = makeUnique<A>(B(), m2);" << endl;
//		auto p3 = makeUnique<A>(B(), m2);
//		cout << "=== auto p4 = makeUnique<A>(m1, C());" << endl;
//		auto p4 = makeUnique<A>(B(), m2);
//		cout << "=== auto p5 = makeUnique<A>(1, 2);" << endl;
//		auto p5 = makeUnique<A>(1, 2);
		cout << "=== end block" << endl;
	}
	cout << "=== after block" << endl;

}


