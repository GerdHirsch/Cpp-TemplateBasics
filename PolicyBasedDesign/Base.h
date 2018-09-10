/*
 * Base.h
 *
 *  Created on: 25.06.2015
 *      Author: Gerd
 */

#ifndef BASE_H_
#define BASE_H_

#include <iostream>

class Base{
public:
	virtual ~Base(){}
	virtual void operation()const{ std::cout << "Base::operation()" << std::endl;}
};
class Derived : public Base{

	virtual void operation()const{ std::cout << "Derived::operation()" << std::endl;}
};

class Other{};

#endif /* BASE_H_ */
