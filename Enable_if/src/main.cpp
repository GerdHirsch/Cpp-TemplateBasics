/*
 * main.cpp
 *
 *  Created on: 03.06.2016
 *      Author: Gerd
 * Dieses projekt ist im experimentierstadium, arbeit abgebrochen
 */


#include "Classes.h"
#include "Templates.h"

#include <iostream>
using namespace std;

int main(){
	cout << "Enable_if" << endl;

	cout << hasMember<ClassWithMember>::value << endl;
	cout << hasMember<ClassWithoutMember>::value << endl;
}
