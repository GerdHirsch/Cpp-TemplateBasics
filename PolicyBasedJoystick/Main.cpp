#include <iostream>
#include "Joystick.h"

using namespace std;
void leftHandler(){
    cout << "dynamic leftHandler()" << endl;
}
void rightHandler(){
    cout << "dynamic rightHandler()" << endl;
}
struct LeftHandler{
    static void Handle(){
        cout << "static LeftHandler::Handle()"  << endl;
    }
};
struct RightHandler{
    static void Handle(){
        cout << "static RightHandler::Handle()"  << endl;
    }
};
void demoStaticBound(){
    cout << "StaticBound" << endl;
    typedef DefaultJoystickRepository<
        LeftHandler, 
        DefaultHandler, 
        RightHandler> JoystickRepository;
    typedef Joystick<JoystickRepository> StaticBound;
    StaticBound::simulateLeft();
    StaticBound::simulateRight();
    StaticBound::simulatePush();
}
void demoDynamicBound(){
    cout << "DynamicBound" << endl;
    typedef Joystick<DynamicJoystickRepository<> > DynamicBound;
    DynamicBound::simulateLeft();
    DynamicBound::Left::setHandler(leftHandler);
    DynamicBound::simulateLeft();
    DynamicBound::Right::setHandler(rightHandler);
    DynamicBound::simulateRight();
}
int main(){
    cout << "PolicyBasedJoystick" << endl;
    demoStaticBound();
    cout << endl;
    demoDynamicBound();

}
