#ifndef A3MemberBC_H_
#define A3MemberBC_H_

#include "C.h"
#include "B.h"

#include <type_traits>

class A
{
public:
	A() : c{}, b{} { std::cout << "A::A()" << std::endl; }

//	template
//	<
//		class T1, class T2
//		,
//		class=typename std::enable_if_t
//		<
//			std::is_same<std::remove_reference_t<T1>, B>::value
//			&&
//			std::is_same<std::remove_reference_t<T2>, C>::value
//		>
//	>
//	A(T1&& t1, T2&& t2)
//	:
//	c(std::forward<T2>(t2)),
//	b(std::forward<T1>(t1))
//	{
//		std::cout << __PRETTY_FUNCTION__ << std::endl;
//	}
//	A(int i) : c{i}, b{i}, i{i} { std::cout << __PRETTY_FUNCTION__ << " i: " << i << ")" << std::endl; }

	A(B&& b, C&& c):c(std::move(c)),  b(std::move(b)){ std::cout << __PRETTY_FUNCTION__ << std::endl;}
	//explicit
	A(A const& src) : c{src.c}, b{src.b}, i{src.i}
		{ std::cout << __PRETTY_FUNCTION__ << std::endl; }

	//explicit
	A(A && src) : c(std::move(src.c)), b(std::move(src.b)), i{src.i}
	{
		src.i = 0;
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

	~A() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

	A& operator=(A const& src){
		c = src.c;
		b = src.b;
		i = src.i;
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return *this;
	}
	A& operator=(A && src){
		c = std::move(src.c);
		b = std::move(src.b);
		i = src.i;
		src.i = 0;
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return *this;
	}
	virtual void operation() {
//		C::operation();
//		B::operation();
		std::cout << __PRETTY_FUNCTION__ << " i: " << i << std::endl;
	}
	virtual void opConst() const { std::cout << __PRETTY_FUNCTION__ << " i: " << i << std::endl; }

	C c;
	B b;
	int i = 42;
};

#endif /* A3MemberBC_H_ */
