/*
 * main.cpp
 *
 *  Created on: 20.03.2016
 *      Author: Gerd
 */

#include "traits.h"

#include<iostream>
using namespace std;

int main(){
	cout << "DemoTypeTraits" << endl;

	int i = 42;
	int & ri = i;
	Remove_reference<decltype(i)>::print();
	Remove_reference<decltype(ri)>::print();
}


