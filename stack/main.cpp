/*
 * main.cpp
 *
 *  Created on: 19.03.2015 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;
#include "stack.h"

void testStack() {
	Stack s;
	for(int i = 1; i <= 10; i++)
		s.push(i);
	while (!s.empty())
		cout << s.pop() << endl;
}

int main() {
	testStack();
}


