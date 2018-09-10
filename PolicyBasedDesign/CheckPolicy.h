/*
 * CheckPolicy.h
 *
 *  Created on: 25.06.2015
 *      Author: Gerd
 */

#ifndef CHECKPOLICY_H_
#define CHECKPOLICY_H_
#include "NoCheckPolicy.h"

#include <stdexcept>
#include <iostream>


template<class T>
struct Check{
	Check(){}

	template<class T1>
	explicit Check(NoCheck<T1> const&){
		std::cout << "Check(NoCheck<T> const&)" << std::endl;
	}
	static inline void check(T const* p)
	{
		std::cout << "Check::check(T const* p)" << std::endl;
		if(!p)
		{
			throw std::runtime_error("NullPointer Exception: Pointer must not be null!");
		}
	}
};

#endif /* CHECKPOLICY_H_ */
