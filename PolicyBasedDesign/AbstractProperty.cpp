/*
 * AbstractProperty.cpp
 *
 *  Created on: 26.06.2015
 *      Author: Gerd
 */

class AbstractProperty{

	template<class PropType>
	void setValue(PropType const& value){
		_setValue(&value);
	}
	template<class PropType>
	PropType* getValue() const{

	}
	virtual void _setValue(void* newValue) = 0;
};
template<class T>
class Property : public AbstractProperty {
	virtual const T& getValue()const{
		AbstractProperty::getValue<T>()
	}
	using AbstractProperty::getValue;
};
void f{
	Property<T> p;

}

