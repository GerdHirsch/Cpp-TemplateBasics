/*
 * Host.h
 *
 *  Created on: 25.06.2015
 *      Author: Gerd
 */

#ifndef HOST_H_
#define HOST_H_
#include <iostream>

template<class T, class CheckPolicy>
class Host : public CheckPolicy{
public:
	Host(T* pointer):pointer(pointer){
		std::cout << "Host(T* pointer)" << std::endl;
		CheckPolicy::check(pointer);
	}

	template<class T2, class CP>
	Host(Host<T2, CP> const& rhs) :
		CheckPolicy(rhs),
		pointer(rhs.getPointer())
	{
		std::cout << "Host(Host<T2, CP> const& rhs)" << std::endl;
		CheckPolicy::check(pointer);
	}

	T* getPointer()const{ return pointer; }
private:
	T* pointer;
};



#endif /* HOST_H_ */
