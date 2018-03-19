/*
 * Main.cpp
 *
 *  Created on: 17.09.2016
 *      Author: Gerd
 */

#include <iostream>
using namespace std;

// forward declaration
namespace gh{
	template<class T> class C;
}

//primary template
template<template<class> class TT>
struct Widget{
public:
	void operation(){
		cout << "Widget<TT>" << endl;
	}
};
//spezialisierung for Template gh::C
template<>
struct Widget<gh::C>{
	void operation(){
		cout << "Widget<gh::C>" << endl;
	}
};

namespace gh{

template<class T> class C{

	// Achtung: Name des Templates C entspricht hier dem Namen der Klasse C<T>
	C *pC1; 		// ok, entspricht aber: C<T> *pC;
	C<T> *pC2;		// dasselbe wie pC1

	// Achtung: Name des Templates C entspricht hier dem template C
	Widget<C> w1;
	Widget<gh::C> w2; // dasselbe wie w1
public:
	C() : pC1(this){ pC2 = this; } // default Ctor
	C(C const&) {/* copy Ctor entspricht: C(C<T> const& rhs) */}
	void operation(){
		cout << "gh::C<T>::operation()" << endl;
		w1.operation(); // spezialisierung wird verwendet
	}
	C* getThis(){ return pC1;}
};

} // end namespace

template<class T> class C{
	Widget<C> w1;
	Widget< ::C> w2; // dasselbe wie w1
	//Widget<::C> w2; // error: '<::' cannot begin a template-argument list
public:
	void operation(){
		cout << "C<T>::operation()" << endl;
		w1.operation(); // primary Template wird verwendet
	}
};

int main(){
	cout << "Injected Class Name" << endl;

	cout << "gh::C<void> c1;" << endl;
	gh::C<void> c1;
	cout << "c1.operation();" << endl;
	c1.operation();
	gh::C<void> c1a(c1); // copy Ctor

	cout << "C<void> c2;" << endl;
	C<void> c2;
	cout << "c2.operation();" << endl;
	c2.operation();
}


