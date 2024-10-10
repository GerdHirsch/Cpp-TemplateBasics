/*
 * DynamicPolymorphism.hpp
 *
 *  Created on: 30.01.2021
 *      Author: Gerd
 */

#ifndef DYNAMICPOLYMORPHISM_HPP_
#define DYNAMICPOLYMORPHISM_HPP_

#include <iostream>

namespace Dynamic{

class Environment{
public:
	virtual void operation() = 0;
};
/*
 * A component is only responsible for one thing (SRP).
 * It delegates everything else to its environment.
 * In dynamic polymorphism, this is typically represented by an abstract base class
 * and defined from the component's point of view!
 * A user of the component must provide the environment,
 * i.e. an implementation of the base class.
 * The implementations are typically defined in other namespaces
 * and not, as in this example, in the same namespace as the component.
 *
 * With dynamic polymorphism, different configurations of the environment as well
 * as completely different implementations can be exchanged at runtime.
 */
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

class EnvironmentImpl_1 : public Environment {
public:
	EnvironmentImpl_1(std::string const& name):name(name){}

	void operation() override {
		std::cout << __PRETTY_FUNCTION__ << ": " << name <<  std::endl;
	}
private:
	std::string name;
};

class EnvironmentImpl_2 : public Environment {
public:
	EnvironmentImpl_2(std::string const& name):name(name){}
	void operation() override {
		std::cout << __PRETTY_FUNCTION__ << ": " << name <<  std::endl;
	}
private:
	std::string name;
};

inline
Component createComponent(Environment* environment){ return Component(environment);}

}//end namespace Dynamic
#endif /* DYNAMICPOLYMORPHISM_HPP_ */
