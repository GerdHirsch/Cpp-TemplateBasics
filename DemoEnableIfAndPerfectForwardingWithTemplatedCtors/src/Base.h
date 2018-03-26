/*
 * Base.h
 *
 *  Created on: 21.03.2018
 *      Author: Gerd
 */

#ifndef BASE_H_
#define BASE_H_
#include <type_traits>
#include <iostream>

class Member{
public:
	~Member(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	Member(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	Member(Member const& rhs){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	Member(Member&& rhs){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	Member(int i){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

};
template<class T1, class T2>
struct enableForMembersOnlyFunction
		: // Delegation by inheritance
		std::enable_if
		<
			std::is_same< std::remove_reference_t<T1>, Member>::value
			&&
			std::is_same<std::remove_reference_t<T2>, Member>::value
		>
{};
template<class T1, class T2>
using enableForMembersOnly = typename enableForMembersOnlyFunction<T1, T2>::type;


class Base{
public:
	template
	< class T1
	, class T2
	, class= enableForMembersOnly<T1, T2>
//	, class = std::enable_if_t
//		<
//			std::is_same< std::remove_reference_t<T1>, Member>::value
//			&&
//			std::is_same<std::remove_reference_t<T2>, Member>::value
//		>
	>
	Base(T1&& t1, T2&& t2)
	: m1(std::forward<T1>(t1)),
	  m2(std::forward<T2>(t2))
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
//	Base(Member& m1, Member& m2):m1(m1), m2(m2){
//		std::cout << __PRETTY_FUNCTION__ << std::endl;
//	}
	Member m1, m2;

	Base(Base const& rhs) : m1(rhs.m1), m2(rhs.m2){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	Base(Base&& rhs): m1(std::move(rhs.m1)), m2(std::move(rhs.m2)){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	Base(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	~Base(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
private:
};


#endif /* BASE_H_ */
