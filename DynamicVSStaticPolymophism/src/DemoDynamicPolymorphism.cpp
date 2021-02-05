/*
 * DemoDynamic.cpp
 *
 *  Created on: 30.01.2021
 *      Author: Gerd
 */

#include "DynamicPolymorphism.hpp"
using namespace Dynamic;

#include <iostream>
using namespace std;


void demoDynamic(){
	cout << __PRETTY_FUNCTION__ << endl;

	// use component with BaseImpl1 configuration 1_1
	EnvironmentImpl_1 environment1_1("No. 1_1");
	auto component = createComponent(&environment1_1);
	component.doSomething();

	// use component with BaseImpl1 configuration 1_2
	EnvironmentImpl_1 environment1_2("No. 1_2");
	component.setEnvironment(&environment1_2);
	component.doSomething();

	// use component with BaseImpl2 configuration 2_1
	EnvironmentImpl_2 environment2_1("No. 2_1");
	component.setEnvironment(&environment2_1);
	component.doSomething();
}
