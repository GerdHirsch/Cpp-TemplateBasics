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

/*
 * A component is only responsible for one thing (SRP).
 * It delegates everything else to its environment.
 * In static polymorphism, this is typically represented by a template parameter
 * and defined from the component's point of view!
 * With the concepts of C++20, the necessary properties of the implementation can be described.
 * A user of the component must provide the environment,
 * i.e. an implementation for the template parameter.
 * The implementations are typically defined in other namespaces
 * and not, as in this example, in the same namespace as the component.
 *
 * With static polymorphism, the variant of the implementation
 * must be defined at compile time.
 * Therefore, only different configurations of the environment
 * but not different implementations can be exchanged at runtime.
 */

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
