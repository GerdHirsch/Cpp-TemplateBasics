/*
 * Traits.h
 *
 *  Created on: 20.03.2016
 *      Author: Gerd
 */

#ifndef TRAITS_H_
#define TRAITS_H_

#include <iostream>

template<class T>
struct Remove_reference{
//	typedef T type;
	using type = T;
	static void print(){ std::cout << "T isn´t reference" << std::endl; }
};
template<class T>
struct Remove_reference<T&>{
	using type = T;
	static void print(){ std::cout << "T is reference" << std::endl;}
};

template<class T>
using RemoveReference = typename Remove_reference<T>::type;


#endif /* TRAITS_H_ */
