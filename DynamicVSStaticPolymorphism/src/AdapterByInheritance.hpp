/*
 * StaticDynamicMix.hpp
 *
 *  Created on: 30.01.2021
 *      Author: Gerd
 */

#ifndef ADAPTER_BY_INHERITANCE_HPP_
#define ADAPTER_BY_INHERITANCE_HPP_

#include "StaticPolymorphism.hpp"
#include <iostream>

namespace Static{
class AbstractEnvironment{
public:
	virtual void operation() = 0;
};
/*
 * With a simple adapter, as outlined here,
 * static polymorphism can be subsequently dynamised if required
 * without greater overhead than with "normal" dynamic polymorphism.
 * The implementation is non-invasive,
 * i.e. the existing classes do not have to be adapted.
 */
template<class Environment>
class Adapter : public AbstractEnvironment, public Environment{
public:
	using Environment::operation;

	Adapter(Environment const& environment): Environment(environment){}
	void operation() override {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		Environment::operation();
	}
private:
	// Environment *environment;
};

template<class Environment>
Adapter<Environment> createAdapter(Environment const& environment){
	return Adapter<Environment>(environment);
}
/*
 This overload ensures that a component is instantiated with AbstractEnvironment when an adapter is passed
 */
template<class Environment>
Component<AbstractEnvironment> createComponent(Adapter<Environment> *adapter){
	return Component<AbstractEnvironment>(adapter);
}

}// end of namespace Static
#endif /* ADAPTER_BY_INHERITANCE_HPP_ */
