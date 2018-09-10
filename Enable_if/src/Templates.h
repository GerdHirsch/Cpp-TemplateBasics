/*
 * Templates.h
 *
 *  Created on: 03.06.2016
 *      Author: Gerd
 */

#ifndef TEMPLATES_H_
#define TEMPLATES_H_
#include <type_traits>

template<class T, class = typename std::enable_if<true, typename T::Member>::type>
struct hasMember{
	enum{value = false};
};
template<class T>
struct hasMember<T, typename  std::enable_if<true, typename T::Member>::type>{
	enum {value = true};
};


#endif /* TEMPLATES_H_ */
