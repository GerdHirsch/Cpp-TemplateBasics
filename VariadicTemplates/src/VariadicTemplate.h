/*
 * VariadicTemplate.h
 *
 *  Created on: 03.02.2016
 *      Author: Gerd
 */

#ifndef VARIADICTEMPLATE_H_
#define VARIADICTEMPLATE_H_

#include<iostream>

template<class ...Types>
void printNumArgs(Types ...args){
	std::cout << "Anzahl Argumente: " << sizeof...(args) << std::endl;
}

template<class T>
inline
void print(T argument){
	std::cout << argument;
}

void print(){}

template<class First, class ...Rest>
inline
void print(First argument, Rest ... rest){
	print(argument);
	print(", ");
	print(rest...);
}
//======================================
template<class T, class ...Args>
T makeT(Args&& ...args){
	return T(std::forward<Args>(args)...);
}


#endif /* VARIADICTEMPLATE_H_ */
