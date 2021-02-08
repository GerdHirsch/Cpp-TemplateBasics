/*
 * DemoStatic.cpp
 *
 *  Created on: 30.01.2021
 *      Author: Gerd
 */

#include "StaticPolymorphism.hpp"
using namespace Static;


#include <iostream>
using namespace std;

void demoStatic(){

	cout << __PRETTY_FUNCTION__ << endl;

	// NOTE: component1
	// use component1 with EnvironmentImpl_1 configuration 1_1
	EnvironmentImpl_1 environment1_1("No 1_1");
	auto component1 = createComponent(&environment1_1);
	component1.doSomething();

	// use component1 with EnvironmentImpl_1 configuration 1_2
	EnvironmentImpl_1 environment1_2("No 1_2");
	component1.setEnvironment(&environment1_2);
	component1.doSomething();

	// NOTE: component2
	// use component2 with EnvironmentImpl_2 configuration 2_1
	EnvironmentImpl_2 environment2_1("No 2_1");
	auto component2 = createComponent(&environment2_1);
	component2.doSomething();

	// use component1 with BaseImpl2 is not possible!
	// error: no matching function for call to
//	component1.setEnvironment(&environment2_1);

}
/* output
void demoStatic()
void Static::Component<Environment>::doSomething() [with Environment = Static::EnvironmentImpl_1]
void Static::EnvironmentImpl_1::operation(): No 1_1
void Static::Component<Environment>::doSomething() [with Environment = Static::EnvironmentImpl_1]
void Static::EnvironmentImpl_1::operation(): No 1_2
void Static::Component<Environment>::doSomething() [with Environment = Static::EnvironmentImpl_2]
void Static::EnvironmentImpl_2::operation(): No 2_1
 */


