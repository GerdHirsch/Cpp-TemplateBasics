/*
 * ScriptStack.h
 *
 *  Created on: 23.02.2014
 *      Author: Gerd
 */

#ifndef STACKWITHCONTAINERTYPEPARAMETER_H_
#define STACKWITHCONTAINERTYPEPARAMETER_H_
#include <iostream>
#include<deque>
#include<vector>
#include <stdexcept>

namespace StackWithContainerTypeParameter{

template< 	typename ElementType,
			typename Container = std::deque<ElementType> >
class Stack{
	Container container;
public:
	void push(ElementType const&);
    ElementType top(){
        if(container.empty()){
            throw std::out_of_range("top from empty stack");
        }
        return container.back();
    }
    void pop();
    bool empty(){ return container.empty();}
    // Assignment
    // damit kann jedes Objekt das top und empty implementiert zugewiesen werden
    template<class AnotherType>
    Stack<ElementType, Container>& operator=(AnotherType lhs);
    // damit können nur Stack<E, C> zugewiesen werden
    template<typename ElemType, typename ContType>
    Stack<ElementType, Container>& operator=(Stack<ElemType, ContType> lhs);

};

template<typename ElementType, class Container>
template<typename ElemType, class ContType>
Stack<ElementType, Container>&
Stack<ElementType, Container>::operator=(Stack<ElemType, ContType> lhs){
    std::cout << "Stack<ElementType, Container>::operator=(Stack<ElemType, ContType> source)" << std::endl;

   	Container temp;
   	while(!lhs.empty()){
   		temp.push_front(lhs.top());
   		lhs.pop();
   	}
   	container.swap(temp);

   	return *this;
}
template<typename ElementType, class Container>
template<class AnotherStack>
Stack<ElementType, Container>&
Stack<ElementType, Container>::operator=(AnotherStack lhs){
    std::cout << "Stack<ElementType, Container>::operator=(AnotherStack source)" << std::endl;

   	Container temp;
   	while(!lhs.empty()){
   		temp.push_front(lhs.top());
   		lhs.pop();
   	}
   	container.swap(temp);

   	return *this;
}


template<typename ElementType, class Container>
void Stack<ElementType, Container>::push(ElementType const& element){
    container.push_back(element);
}
template<typename ElementType, class Container>
void Stack<ElementType, Container>::pop(){
	if(container.empty()){
		throw std::out_of_range("pop from empty stack");
	}
	container.pop_back();
}

} // end namespace
#endif /* STACKWITHCONTAINERTYPEPARAMETER_H_ */
