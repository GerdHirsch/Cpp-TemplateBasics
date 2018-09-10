/*
 * StackFixedSized.h
 *
 *  Created on: 02.03.2014
 *      Author: Gerd
 */

#ifndef STACKFIXEDSIZED_H_
#define STACKFIXEDSIZED_H_

namespace StackWithFixedSizedParameter{

template<typename E, std::size_t N>
class Stack{
	E container[N];
	std::size_t numElements;
public:
	Stack();
	void push(E const& e);
	void pop();
	E top() const;
	bool empty() const { return numElements == 0; }
	bool full() const { return numElements == N; }
};

template<typename E, std::size_t N>
Stack<E, N>::Stack() : numElements(0){/*nothing to do*/}

template<typename E, std::size_t N>
void Stack<E, N>::push(E const& e) {
	if(full()) throw std::logic_error("Stack<>::push() overflow");

	container[numElements++] = e;
}

template<typename E, std::size_t N>
E Stack<E, N>::top() const {
	if(empty()) throw std::logic_error("Stack<>::top() underflow");

	return container[numElements-1];
}

template<typename E, std::size_t N>
void Stack<E, N>::pop() {
	if(empty()) throw std::logic_error("Stack<>::pop() underflow");

	--numElements;
}


} // end namespace StackWithFixedSizedParameter

#endif /* STACKFIXEDSIZED_H_ */
