/*
 * Widget.h
 *
 *  Created on: 03.02.2016
 *      Author: Gerd
 */

#ifndef WIDGET_H_
#define WIDGET_H_
#include <iostream>

class Member{
public:
//	template<class Name>
//	Member(Name&& name) ... verdeckt die Copy- & Move Ctors !!!


	explicit Member(std::string&& name)
	: name(std::move(name))
	{}
	explicit Member(std::string const& name)
	: name(name) // copy
	{}

	Member(Member const& rhs) : name(rhs.name){
		std::cout << "Member(Member const& rhs)" << name << std::endl;
	}
	Member(Member && rhs) : name(std::move(rhs.name)){
		std::cout << "Member(Member && rhs)" << name << std::endl;
	}
	~Member(){
		std::cout << "~Member()" << name << std::endl;
	}
private:
	std::string name;
};

class Widget{
public:
	Widget()
	: name("default"), m1("m1"), m2("m2")
	{
		std::cout << "Widget()" << name << std::endl;
	}
	//=================================================================
	// zwei parameter benötigen 4 Ctors für L- & R-Value Referenzen
	// Sonst wird der L-Value const & Ctor verwendet
	Widget(std::string const& name, Member const& m1, Member const& m2)
	:name(name), m1(m1), m2(m2)
	{
		std::cout << "Widget(std::string const& name, Member const& m1, Member const& m2): " << this->name  << std::endl;
	}
	Widget(std::string && name, Member && m1, Member && m2)
	:name(std::move(name)), m1(std::move(m1)), m2(std::move(m2))
	{
		std::cout << "Widget(std::string && name, Member && m1, Member && m2): " << this->name << std::endl;
	}
	// template<class Name, class M> // nur 2 Typeparameter funktioniert nicht wenn M1&& und M2& ist
	// Widget w3("w3", Member("m1"), m2);
	template<class Name, class M1, class M2>
	Widget(Name && name, M1 && m1, M2 && m2)
	:name(std::forward<Name>(name)),
	 m1(std::forward<M1>(m1)),
	 m2(std::forward<M2>(m2))
	{
		std::cout << "template<class Name, class M> Widget(Name && name, M && m1, M && m2): " << this->name << std::endl;
	}
	//=================================================================
	Widget(Widget const& rhs):name(rhs.name), m1(rhs.m1), m2(rhs.m2){
		std::cout << "Widget(Widget const& rhs)" << name << std::endl;
	}
	Widget(Widget && rhs):name(std::move(rhs.name)), m1(std::move(rhs.m1)), m2(std::move(rhs.m2)){
		std::cout << "Widget(Widget && rhs)" << name << std::endl;
	}
	~Widget(){
		std::cout << "~Widget(): " << name << std::endl;
	}
private:
	std::string name;
	Member m1;
	Member m2;
};



#endif /* WIDGET_H_ */
