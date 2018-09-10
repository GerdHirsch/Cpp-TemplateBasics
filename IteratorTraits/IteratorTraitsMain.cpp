#include <iostream>
#include <vector>
#include <list>

#include <forward_list>

using namespace std;

#include "Templates.h"

int main()
{

	int array[] = {1,2,3};
	demoIteratorTags(array, &array[3]);

    cout   << "myDistance(array, &array[3]): " 
            << myDistance(array, &array[3])<< endl;

	vector<int> myVector;
	demoIteratorTags(myVector.begin(), myVector.end());

	list<int> myList;
    myList.push_back(42);
    myList.push_back(43);
    demoIteratorTags(myList.begin(), myList.end());

	forward_list<int> myForward_list(myList.begin(), myList.end());
	demoIteratorTags(myForward_list.begin(), myForward_list.end());


//    cout   << "myDistance(myList.begin(), myList.end()): "
//            << myDistance(myList.begin(), myList.end())<< endl;
}
