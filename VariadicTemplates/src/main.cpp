/*
 * main.cpp
 *
 *  Created on: 03.02.2016
 *      Author: Gerd
 *      C++11 programmieren torsten T. Will
 */

#include "VariadicTemplate.h"
#include "Widget.h"

#include<iostream>
#include <memory>
using namespace std;


void demoMakeT();
void demoPrint();
void demoLRValueCtors();

int main(){
	cout << "VariadicTemplates" << endl;
//	demoMakeT();
	demoLRValueCtors();
}
void demoPrint(){
	print(1, 42.1, 'c', "Hello Variadic Templates");

	cout << endl;
	printNumArgs(1, 42.1, 'c', "Hello Variadic Templates");
}
void demoLRValueCtors(){
	cout << "===demoLRValueCtors()" << endl;
	cout << "===Member m1, m2;" << endl;
	Member m1("m1");
	Member m2("m2");

	cout << R"(=== Widget w1("w1", Member("m1"), Member("m2"));)" << endl;
	Widget w1("w1", Member("m1"), Member("m2"));

	cout << R"(=== Widget w2("w2", m1, m2);)" << endl;
	Widget w2("w2", m1, m2);

	cout << R"(=== Widget w3("w3", Member("m1"), m2);)" << endl;
	Widget w3("w3", Member("m1"), m2);
}
void demoMakeT(){
//	cout << "===demoMakeT()" << endl;
//	cout << "===Member m;" << endl;
//	Member m;
//	cout << "===Widget w(\"w\", m);" << endl;
//	Widget w("w", m);
//
//	cout << "===string name(\"w1\");" << endl;
//	string name("w1");
//	cout << "===Widget w = makeT<Widget>(name, m);" << endl;
//	Widget w1 = makeT<Widget>(name, m);

//		cout << "===Widget w2 = makeT<Widget>(string("w2"), Member());" << endl;
//		Widget w2 = makeT<Widget>(Member());
//		cout << "End Block" << endl;
}


