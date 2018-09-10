#ifndef STACKWITHELEMENTPARAMETER_H
#define STACKWITHELEMENTPARAMETER_H

#include <iostream>
#include <vector>
#include <stdexcept>

namespace StackWithElementParameter{

template<typename ElementType>
class Stack{
    std::vector<ElementType> container;
public:

    void push(ElementType const& element){ container.push_back(element); }
    void pop();

    ElementType top(){
        if(container.empty()){ 
            throw std::out_of_range("top from empty stack");
        }
        return container.back();
    }
};
template<typename ElementType>
void Stack<ElementType>::pop(){
	if(container.empty()){
		throw std::out_of_range("pop from empty stack");
	}
	container.pop_back();
}

template<>
class Stack<void*>{
    std::vector<void*> container;
public:
    void push(void* element){
        std::cout << "Stack<void*>::push(void*)" << std::endl;
        container.push_back(element);
    }
    void pop();
    void* top(){ 
        std::cout << "Stack<void*>::top()" << std::endl;
        if(container.empty()){ 
            throw std::out_of_range("Stack<void*>::top from empty stack");
        }
        return container.back();
    }
};

void Stack<void*>::pop(){ 
        std::cout << "Stack<void*>::pop()" << std::endl;
        if(container.empty()){ 
            throw std::out_of_range("Stack<void*>::pop from empty stack");
        }
        container.pop_back();
    }

// Spezialisierung für Pointer
template<typename ElementType>
class Stack<ElementType*>{
    Stack<void*> elems;
public:
    void push(ElementType* element){
        elems.push(element);
    }
    void pop(){ 
        elems.pop();
    }
    ElementType* top(){
        return (ElementType*)elems.top();
    }
};

void demoStack(){
    std::cout << "Stack with Element Parameter" << std::endl;

    Stack<int> intStack;
    Stack<int*> intPStack;
    Stack<std::string*> stringPStack;


    int i;// j, k;
    intStack.push(42);
    intPStack.push(&i);
    std::cout << "=>  intStack.top(): " << intStack.top() << std::endl;
    std::cout << "=> intPStack.top(): " << intPStack.top() << std::endl;
    try{
        std::cout << "1 intStack.pop()" << std::endl;
        intStack.pop();
        std::cout << "2 intStack.pop()" << std::endl;
        intStack.pop();
        std::cout << "3 intStack.pop()" << std::endl;
        intStack.pop();
        std::cout << "4 intStack.pop()" << std::endl;

    }catch(std::out_of_range & e){
        std::cout << "catch(out_of_range & e): " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try{
        std::cout << "1 intPStack.pop()" << std::endl;
        intPStack.pop();
        std::cout << "2 intPStack.pop()" << std::endl;
        intPStack.pop();
        std::cout << "3 intPStack.pop()" << std::endl;
        intPStack.pop();

    }catch(std::out_of_range & e){
        std::cout << "catch(out_of_range & e): " << e.what() << std::endl;
    }
}

}// end namespace
#endif //STACKWITHELEMENTPARAMETER_H

