/*
 * simple_task.cpp
 *
 *  Created on: 29.05.2015 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;

#include "simple_task.h"

SimpleTask::SimpleTask(const char* _name, int _time)
	: Task(_name), time(_time), progress(0) {
}

void SimpleTask::print() const {
	cout << "проста ";
	Task::print();
	cout << ", която е с прогрес " << progress << " от " << time;
}

int SimpleTask::work(int t) {
	if (t > 0) {
		int rt = min(time - progress, t);
		progress += rt;
		t -= rt;
	}
	return t;
}
