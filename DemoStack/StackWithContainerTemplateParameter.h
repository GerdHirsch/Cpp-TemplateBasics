/*
 * ScriptStack.h
 *
 *  Created on: 23.02.2014
 *      Author: Gerd
 */

#ifndef STACKWITHCONTAINERTTEMPLATEPARAMETER_H_
#define STACKWITHCONTAINERTTEMPLATEPARAMETER_H_
#include <iostream>
#include<deque>

namespace StackWithContainerTemplateParameter{

template< 	typename ElementType,
			template<typename ElementType, typename = std::allocator<ElementType> >
			class Container = std::deque >
class Stack{
	Container <ElementType> container;
public:
    bool empty(){ return container.empty();}

	void push(ElementType const&);
    ElementType top(){
        if(container.empty()){
            throw std::out_of_range("top from empty stack");
        }
        return container.back();
    }
    void pop(){
    	if(container.empty()){
    		throw std::out_of_range("pop from empty stack");
    	}
    	container.pop_back();
    }
    // Assignment
//    template<typename ElemType, typename ContType>
//    Stack<ElementType, Container>& operator=(Stack<ElemType, ContType> source);

//    {
//
//    	Container<ElementType> temp;
//    	while(!source.empty()){
//    		temp.push_front(source.top());
//    		source.pop();
//    	}
//    	container.swap(temp);
//
//    	return *this;
//    }
};

//template<typename ElementType, class Container>
//template<typename ElemType, class ContType>
//Stack<ElementType, Container>&
//Stack<ElementType, Container>::operator=(Stack<ElemType, ContType> source){
//
//   	Container<ElementType> temp;
//   	while(!source.empty()){
//   		temp.push_front(source.top());
//   		source.pop();
//   	}
//   	container.swap(temp);
//
//   	return *this;
//   }


template<typename ElementType, template<typename, typename> class Container>
void Stack<ElementType, Container>::push(ElementType const& element){
    container.push_back(element);
}
//template<typename ElementType, class Container>
//void Stack<ElementType, Container>::pop(){
//	if(container.empty()){
//		throw std::out_of_range("pop from empty stack");
//	}
//	container.pop_back();
//}

} // end namespace
#endif /* STACKWITHCONTAINERTTEMPLATEPARAMETER_H_ */
