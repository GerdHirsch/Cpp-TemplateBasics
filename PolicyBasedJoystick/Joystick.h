#ifndef __JOYSTICK_H__
#define __JOYSTICK_H__
#include <iostream>


struct DefaultHandler{
    static void Handle(){}
};

template<int num>
struct DefaultDynamicHandler{
    typedef void(*PF)();
    static void setHandler(PF handler){
            Handler() = handler;
    }
    static PF getHandler(){ return Handler();}
    static void Handle(){
        if(Handler()){
        	Handler()();
        }
    }
private:
    static PF& Handler(){
        static PF pf = nullptr;
        return pf;
    }
};

template<
    class LeftHandler = DefaultHandler,
    class DownHandler = DefaultHandler,
    class RightHandler = DefaultHandler,
    class UpHandler = DefaultHandler,
    class PushHandler = DefaultHandler
        >
struct DefaultJoystickRepository{
    typedef LeftHandler Left;
    typedef DownHandler Down;
    typedef RightHandler Right;
    typedef UpHandler Up;
    typedef PushHandler Push;
};

template<
    class LeftHandler = DefaultDynamicHandler<0>,
    class DownHandler = DefaultDynamicHandler<1>,
    class RightHandler = DefaultDynamicHandler<2>,
    class UpHandler = DefaultDynamicHandler<3>,
    class PushHandler = DefaultDynamicHandler<4>
        >
struct DynamicJoystickRepository
		: DefaultJoystickRepository<
		  LeftHandler,
		  DownHandler,
		  RightHandler,
		  UpHandler,
		  PushHandler
		  >
		{};


template<class Repository=DefaultJoystickRepository<> >
class Joystick : public Repository {
public:
    typedef Joystick<Repository> this_type;

    static void simulateLeft(){
        std::cout << "Joystick::simulateLeft()" << std::endl;
        this_type::Left::Handle();
    }
    static void simulateRight(){
        std::cout << "Joystick::simulateRight()" << std::endl;
        this_type::Right::Handle();
    }
    static void simulatePush(){
        std::cout << "Joystick::simulatePush()" << std::endl;
        this_type::Push::Handle();
    }

};

#endif //__JOYSTICK_H__
