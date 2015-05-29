/*
 * quick_task.cpp
 *
 *  Created on: 28.05.2015 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;

#include "quick_task.h"

QuickTask::QuickTask(const char* _name)
	: Task(_name), finished(false) {
}

void QuickTask::print() const {
	cout << "бърза ";
	Task::print();
	cout << ", която ";
	if (!finished)
		cout << "НЕ ";
	cout << "е завършена";
}

int QuickTask::work(int t) {
	if (t > 0 && !finished) {
		finished = true;
		t--;
	}
	return t;
}
