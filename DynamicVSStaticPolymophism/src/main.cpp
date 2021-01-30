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
 */
int main(){
	cout << "DynamicVSStaticPolymophism" << endl;
	demoDynamic();
	demoStatic();
	demoStaticDynamicMix();

}

