/*
 * main.cpp
 *
 *  Created on: 23.02.2016
 *      Author: Gerd
 */

#include<iostream>
using namespace std;

template<int N>
int add(int i){
	cout << __PRETTY_FUNCTION__ << endl;
	cout << "<int N> add(int i)" << endl;
	return i + N;
}

template<>
int add<0>(int i){
	cout << __PRETTY_FUNCTION__ << endl;
	cout << "<0> add(int i)" << endl;
	return i;
}

int main(){
	cout << "FunctionTemplateValueTypeArguments" << endl;
	cout << add<5>(37) << endl;
	cout << add<0>(37) << endl;
}


