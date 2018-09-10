/*
 * MixingTypTemplateParameter.cpp
 *
 *  Created on: 01.03.2014
 *      Author: Gerd
 */

#include <iostream>
#include "StackWithContainerTypeParameter.h"
#include "StackWithContainerTemplateParameter.h"
#include "StackFixedSized.h"

using namespace std;
namespace templ = StackWithContainerTemplateParameter;
namespace type = StackWithContainerTypeParameter;
namespace fixed = StackWithFixedSizedParameter;

void demoMixingTypeTemplateParameter(){
	cout << "demoMixingTypeTemplateParameter" << endl;

	templ::Stack<double> i1Stack;
	type::Stack<double> i2Stack;

	i1Stack.push(1);
	i2Stack = i1Stack;
	cout << "i2Stack.top(): " << i2Stack.top() << endl;

	fixed::Stack<int, 3> fi3Stack;
	fixed::Stack<int, 3> fi3aStack;
	fi3Stack.push(3);

	fi3aStack = fi3Stack;
	cout << "fi3aStack.top(): " << fi3aStack.top() << endl;

	i2Stack = fi3Stack;
	cout << "i2Stack.top(): " << i2Stack.top() << endl;
}

namespace StackWithContainerTemplateParameter{
void demoStack(){
    std::cout << "Stack with Container Template Parameter" << std::endl;

	Stack<int> i1Stack;
	Stack<int> i2Stack;
	Stack<double> dStack;
	i1Stack.push(42);

	i2Stack = i1Stack;
	std::cout << "i2Stack.top():" << i2Stack.top();

	//dStack = i1Stack;

}
} // end namespace StackWithContainerTemplateParameter

namespace StackWithContainerTypeParameter{
void demoStack(){
    std::cout << "Stack with Container Type Parameter" << std::endl;

	Stack<int> i1Stack;
	Stack<int> i2Stack;
	i1Stack.push(1);

    // Zwei gleiche Stack Typen zuweisen-> Compiler generierter Assignment Operator
	i2Stack = i1Stack;
	std::cout << "i2Stack.top():" << i2Stack.top() << std::endl;

	Stack<double> dStack;

	// Zwei Stacks mit unterschiedlichen Typen zuweisen
	dStack = i1Stack;
	std::cout << "dStack.top():" << dStack.top() << std::endl;

	Stack<int, std::vector<int> > iVStack;
	iVStack.push(2);
	i2Stack = iVStack;
	std::cout << "i2Stack.top():" << i2Stack.top() << std::endl;

	//error: 'class std::vector<int, std::allocator<int> >' has no member named 'push_front'
	//iVStack = i1Stack;
}

} // end namespace StackWithContainerTypeParameter
