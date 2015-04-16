/*
 * rstack.h
 *
 *  Created on: 26.03.2015 г.
 *      Author: trifon
 */

#ifndef RSTACK_H_
#define RSTACK_H_

class ResizingStack {
private:
	int* a; // елементите на стека
	int top; // индекс на последния елемент
	int capacity; // капацитет на стека

	// проверка дали стекът е пълен
	bool full() const;

	// разширяване на стека
	void resize();

public:

	// създаване на празен стек
	ResizingStack();

	// конструктор за копиране
	ResizingStack(ResizingStack const&);

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
	~ResizingStack();

};



#endif /* RSTACK_H_ */
