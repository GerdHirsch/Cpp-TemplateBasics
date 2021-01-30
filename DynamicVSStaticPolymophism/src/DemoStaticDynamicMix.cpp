/*
 * DemoStaticDynamicMix.cpp
 *
 *  Created on: 30.01.2021
 *      Author: Gerd
 */

#include "Adapter.hpp"
using namespace Static;

#include <iostream>
using namespace std;

void demoStaticDynamicMix(){
	cout << __PRETTY_FUNCTION__ << endl;
	// use component with BaseImpl1 configuration 1_1
	Static::BaseImpl1 environment1_1("No 1_1");
	auto adapter1_1 = createAdapter(&environment1_1);
	auto component = createComponent(&adapter1_1);
	component.doSomething();

	// use component1 with BaseImpl1 configuration 1_2
	BaseImpl1 environment1_2("No 1_2");
	auto adapter1_2 = createAdapter(&environment1_2);
	component.setEnvironment(&adapter1_2);
	component.doSomething();

	// use component with BaseImpl2 configuration 2_1
	BaseImpl2 environment2_1("No 2_1");
	auto adapter2_1 = createAdapter(&environment2_1);
	component.setEnvironment(&adapter2_1);
	component.doSomething();

}


