
/*
 * lstack.cpp
 *
 *  Created on: 26.03.2015 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;
#include "lstack.h"

LinkedStack::LinkedStack() {
	top = NULL;
}

bool LinkedStack::empty() const {
	return top == NULL;
}

int LinkedStack::peek() const {
	if (empty()) {
		cout << "Грешка: опит за поглеждане в празен стек!\n";
		return 0;
	}

	return top->data;
}

void LinkedStack::push(int x) {
	StackElement* p = new StackElement;
	p->data = x;
	p->next = top;
	top = p;
}

int LinkedStack::pop() {
	if (empty()) {
		cout << "Грешка: опит за изключване от празен стек!\n";
		return 0;
	}
	// top != NULL

	StackElement* p = top;
	top = top->next;
	int x = p->data;
	delete p;
	return x;
}
