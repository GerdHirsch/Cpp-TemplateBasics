/*
 * IsPowerOf2.h
 *
 *  Created on: 22.05.2018
 *      Author: Gerd
 */

#ifndef ISPOWEROF2_H_
#define ISPOWEROF2_H_

#include <cstddef>

template<size_t v, size_t mask=1>
struct countOnesImpl;

template<size_t v>
struct countOnesImpl<v, 1u<<((sizeof(size_t)*8)-1)>
{
	static constexpr size_t mask{1u<<((sizeof(size_t)*8)-1)};
	static constexpr size_t value = (v & mask) == 0
			? 0
			: 1;
};
template<size_t v, size_t mask>
struct countOnesImpl{
	static constexpr size_t value = (v & mask) == 0
			? countOnesImpl<v, mask<<1 >::value
			: 1 + countOnesImpl<v, mask<<1 >::value;
};

template<size_t value>
size_t countOnes = countOnesImpl<value>::value;


constexpr std::size_t countNumberOfOnes(std::size_t value){
	std::size_t numOnes{0};
	constexpr size_t numBits = sizeof(value) * 8;
	size_t mask{1};
	for(size_t i=0; i< numBits; ++i, mask<<=1)
		if( (value & mask) != 0) ++numOnes;

	return numOnes;
}
constexpr bool isPowerOfTwo(std::size_t value){
	return countNumberOfOnes(value) == 1;
//	return countOnes<value>::value;
}



#endif /* ISPOWEROF2_H_ */
