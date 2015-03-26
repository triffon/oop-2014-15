/*
 * main.cpp
 *
 *  Created on: 19.03.2015 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;
#include "stack.h"
#include "rstack.h"

typedef ResizingStack TestStack;

bool matchParentheses(char open, char close) {
	return open == '(' && close == ')' ||
			open == '[' && close == ']' ||
			open == '{' && close == '}' ||
			open == '<' && close == '>';
}

bool checkParentheses(char const* s) {
	TestStack stack;
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
	TestStack s;
	for(int i = 1; i <= 101; i++)
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

double* resize(double* a, int& capacity) {
	int oldCapacity = capacity;
	// capacity++;
	capacity *= 2;
	double* newa = new double[capacity];
	for(int i = 0; i < oldCapacity; i++)
		newa[i] = a[i];
	delete[] a;
	return newa;
}

void findAverage() {
	// double a[10];
	int n = 0;
	int capacity = 4;
	double* a = new double[capacity];
	do {
		cout << "a[" << n << "] = ";
		// cin >> a[n];
		a[n] = n + 1;
		n++;
		if (n == capacity) {
			cout << "Разширяваме масива!" << endl;
			a = resize(a, capacity);
		}
	} while (a[n-1] != 0);
	n--;
	double sum = 0;
	for(int i = 0; i < n; i++) {
		sum += a[i];
		cout << a[i] << ' ';
	}
	cout << endl;
	cout << "Средно: " << sum / n << endl;
}

int main() {
	testStack();
	testParentheses();
	// testDynamic();
	// findAverage();
	return 0;
}


