/*
 * main.cpp
 *
 *  Created on: 20.05.2018
 *      Author: Gerd
 */

#include "IsPowerOf2.h"

#include<iostream>
using namespace std;

void demo(){
	static constexpr size_t mask{1u<<((sizeof(size_t)*8)-1)};
	size_t value = -1;
	cout << hex << "mask: " << mask << endl;
	cout << dec << "value " << value << endl;
	cout << hex << "value & mask " << (value & mask) << endl;
}
int main(){
	cout << "RatioCounter" << endl;
	cout << "sizeof(long long)" << sizeof(long long) << endl;
	demo();

	cout << "1: " << countOnes<1> << endl;
	cout << "2: " << countOnes<2> << endl;
	cout << "3: " << countOnes<3> << endl;
	cout << "8: " << countOnes<8> << endl;

	cout << endl;
	cout << "1: " << countNumberOfOnes(1) << endl;
	cout << "2: " << countNumberOfOnes(2) << endl;
	cout << "3: " << countNumberOfOnes(3) << endl;
	cout << "8: " << countNumberOfOnes(8) << endl;

	cout << endl;
	cout << boolalpha;
	cout << "isPowerOfTwo(1):" << isPowerOfTwo(1) << endl;
	cout << "isPowerOfTwo(2):" << isPowerOfTwo(2) << endl;
	cout << "isPowerOfTwo(3):" << isPowerOfTwo(3) << endl;
	cout << "isPowerOfTwo(8):" << isPowerOfTwo(8) << endl;

}

