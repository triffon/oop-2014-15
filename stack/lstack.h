/*
 * lstack.h
 *
 *  Created on: 26.03.2015 г.
 *      Author: trifon
 */

#ifndef LSTACK_H_
#define LSTACK_H_

struct StackElement {
	int data;
	StackElement* next;
};

class LinkedStack {
private:
	StackElement* top;

public:
	// създаване на празен стек
	LinkedStack();

	// конструктор за копиране
	LinkedStack(LinkedStack const&);

	// операция за присвояване
	LinkedStack& operator=(LinkedStack const&);

	// селектори

	// проверка дали стек е празен
	bool empty() const;

	// намиране на елемента на върха на стека
	int peek() const;

	// мутатори

	// включване на елемент
	void push(int);

	// изключване на елемент
	int pop();

	// деструктор
	~LinkedStack();

	friend LinkedStack operator+(int, LinkedStack);
};



#endif /* LSTACK_H_ */
