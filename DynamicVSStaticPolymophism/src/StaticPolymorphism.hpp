/*
 * StaticPolymorphism.hpp
 *
 *  Created on: 30.01.2021
 *      Author: Gerd
 */

#ifndef STATICPOLYMORPHISM_HPP_
#define STATICPOLYMORPHISM_HPP_

#include <iostream>
#include <string>

namespace Static{

template <class Environment>
class Component{
public:
	Component(Environment *environment) : environment(environment){}

	void doSomething(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		environment->operation();
	}
	void setEnvironment(Environment *environment){ this->environment = environment; }
private:
	Environment *environment;
};

class BaseImpl1 {
public:
	BaseImpl1(std::string const& name):name(name){}
	void operation() {
		std::cout << __PRETTY_FUNCTION__ << ": " << name << std::endl;
	}
private:
	std::string name;
};

class BaseImpl2 {
public:
	BaseImpl2(std::string const& name):name(name){}
	void operation() {
		std::cout << __PRETTY_FUNCTION__ << ": " << name << std::endl;
	}
private:
	std::string name;
};

template<class Environment>
inline
Component<Environment> createComponent(Environment* environment){
	return Component<Environment>(environment);
}

} // end of namespace
#endif /* STATICPOLYMORPHISM_HPP_ */
