/*
 * rstack.cpp
 *
 *  Created on: 26.03.2015 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;
#include "rstack.h"

int const EMPTY_STACK = -1;
int const DEFAULT_CAPACITY = 10;

ResizingStack::ResizingStack() {
	capacity = DEFAULT_CAPACITY;
	top = EMPTY_STACK;
	a = new int[capacity];
}

bool ResizingStack::empty() const {
	return top == EMPTY_STACK;
}

int ResizingStack::peek() const {
	if (empty()) {
		cout << "Грешка: опит за поглеждане в празен стек!\n";
		return 0;
	}

	return a[top];
}

void ResizingStack::push(int x) {
	if (full())
		resize();
	a[++top] = x;
}

bool ResizingStack::full() const {
	return top == capacity - 1;
}

void ResizingStack::resize() {
	int oldCapacity = capacity;
	capacity *= 2;
	cout << "Увеличаваме стека до " << capacity;
	cout << " елемента!" << endl;
	int* newa = new int[capacity];
	for(int i = 0; i < oldCapacity; i++)
		newa[i] = a[i];
	delete[] a;
	a = newa;
}

int ResizingStack::pop() {
	if (empty()) {
		cout << "Грешка: опит за изключване от празен стек!\n";
		return 0;
	}
	return a[top--];
}

