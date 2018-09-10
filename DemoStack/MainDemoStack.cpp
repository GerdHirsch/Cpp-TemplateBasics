#include <iostream>

#include "StackWithElementParameter.h"
#include "StackWithContainerTypeParameter.h"

void demoMixingTypeTemplateParameter();

using namespace std;

//using namespace StackWithElementParameter;
using namespace StackWithContainerTypeParameter;
//using namespace StackWithContainerTemplateParameter;

int main(){
    cout << "DemoStack " << endl;
//    demoStack();
    demoMixingTypeTemplateParameter();

}
