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

	// use component1 with BaseImpl1 configuration 1_1
	EnvironmentImpl_1 environment1_1("No 1_1");
	auto component1 = createComponent(&environment1_1);
	component1.doSomething();

	// use component1 with BaseImpl1 configuration 1_2
	EnvironmentImpl_1 environment1_2("No 1_2");
	component1.setEnvironment(&environment1_2);
	component1.doSomething();

	// use component2 with BaseImpl2 configuration 2_1
	EnvironmentImpl_2 environment2_1("No 2_1");
	auto component2 = createComponent(&environment2_1);
	component2.doSomething();

	// use component1 with BaseImpl2 is not possible!
	// error: no matching function for call to
//	component1.setEnvironment(&environment2_1);

}


