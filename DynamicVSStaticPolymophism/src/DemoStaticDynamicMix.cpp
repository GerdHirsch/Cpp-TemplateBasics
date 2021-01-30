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
/* this is pretty much the same as in demoDynamic(),
 * but with a component as a C++ template.
 * With an adapter, you can have compile-time or static polymorphism as well as dynamic polymorphism.
 * If you have use cases where you can choose the implementation at compile time,
 * use static polymorphism with templates, the abstraction is represented as a template parameter,
 * but if you subsequently need to change the implementation at runtime in some cases
 * you can simply switch to dynamic polymorphism with the adapter implementation.
 * The adapter simply forwards the messages to the implementation.
 * The overhead is no greater than with "simple" dynamic polymorphism
 * because the methods are inline. Only the adapter methods are virtual.
 *
*/
void demoStaticDynamicMix(){

	cout << __PRETTY_FUNCTION__ << endl;
	// use component with BaseImpl1 configuration 1_1
	Static::BaseImpl1 environment1_1("No 1_1");
	auto adapter1_1 = createAdapter(&environment1_1);
	auto component = createComponent(&adapter1_1);
	component.doSomething();

	// use component with BaseImpl1 configuration 1_2
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


