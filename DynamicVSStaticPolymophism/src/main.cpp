/*
 * main.cpp
 *
 *  Created on: 30.01.2021
 *      Author: Gerd
 */


void demoDynamic();
void demoStatic();
void demoStaticDynamicMix();

#include <iostream>
using namespace std;
/*
 * This project demonstrates the use of dynamic and static polymorphism
 * and how static polymorphism can be dynamised.
 * It is only a sketch of how it works.
 * All objects are on the stack.
 * In real projects, the lifetime of the objects must be taken into account.
 */
int main(){
	cout << "DynamicVSStaticPolymophism" << endl;
	cout << "========================================================" << endl;
	demoDynamic();
	cout << "========================================================" << endl;
	demoStatic();
	cout << "========================================================" << endl;
	demoStaticDynamicMix();
	cout << "========================================================" << endl;

}

