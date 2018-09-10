/*
 * NoCheckPolicy.h
 *
 *  Created on: 25.06.2015
 *      Author: Gerd
 */

#ifndef NOCHECKPOLICY_H_
#define NOCHECKPOLICY_H_
#include <iostream>
template<class T>
struct NoCheck{

	static void check(T const* p){
		std::cout << "NoCheck::check(T const* p)" << std::endl;
	}
};



#endif /* NOCHECKPOLICY_H_ */
