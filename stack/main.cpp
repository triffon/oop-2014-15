/*
 * main.cpp
 *
 *  Created on: 19.03.2015 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;
#include "stack.h"

bool matchParentheses(char open, char close) {
	return open == '(' && close == ')' ||
			open == '[' && close == ']' ||
			open == '{' && close == '}' ||
			open == '<' && close == '>';
}

bool checkParentheses(char const* s) {
	Stack stack;
	char const* p = s;
	while (*p != '\0') {
		switch (*p) {
		case '(':
		case '[':
		case '{':
		case '<':
			stack.push(*p);
			break;
		case ')':
		case ']':
		case '}':
		case '>':
			if (stack.empty() ||
				!matchParentheses(stack.pop(), *p))
				return false;
			break;
		}
		p++;
	}
	return stack.empty();
}

void testStack() {
	Stack s;
	for(int i = 1; i <= 10; i++)
		s.push(i);
	while (!s.empty())
		cout << s.pop() << endl;
}

void testParentheses() {
	const int MAX = 1000;
	char s[MAX];
	cin.getline(s, MAX);
	cout << "Скобите са ";
	if (checkParentheses(s))
		cout << "OК\n";
	else
		cout << "сгрешени!\n";
}

void testDynamic() {
	int* p = new int(5);
	int& x = *p;
	cout << x << endl;
	x = 30;
	cout << x << endl;
	char* s = new char[x];
	cin.getline(s, x);
	cout << s << endl;
	delete p;
	// !!! *p = 10;
	// !!! cout << x << endl;
	// !!! delete p;
	// !!! delete[] (s+1);
	delete[] s;
	// !!! cout << s << endl;
	int y = 20;
	p = &y;
	// !!! delete p;
}

int main() {
	// testStack();
	// testParentheses();
	testDynamic();
	return 0;
}


