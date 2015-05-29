
/*
 * repeat_task.cpp
 *
 *  Created on: 29.05.2015 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;

#include "repeat_task.h"

RepeatTask::RepeatTask(const char* _name,
					   Task const* _toRepeat,
					   int _repetitions)
	: SimpleTask(_name, _repetitions),
	  toRepeat(_toRepeat),
	  current(NULL) {
	resetCurrent();
}

void RepeatTask::print() const {
	cout << "потваряща се ";
	Task::print();
	cout << ", която е повторила " <<
			getRepetitionProgress() << " пъти от ";
	cout << getRepetitions() << ' ';
	toRepeat->print();
	cout << ", като текущата задача е с прогрес " << current->getProgress();
	cout << " от " << current->getTime();
}

void RepeatTask::copy(RepeatTask const& rt) {
	toRepeat = rt.toRepeat;
	current = (Task*)rt.current->clone();
}

RepeatTask::RepeatTask(const RepeatTask& rt)
	: SimpleTask(rt) {
	copy(rt);
}

RepeatTask& RepeatTask::operator=(const RepeatTask& rt) {
	if (this != &rt) {
		delete current;
		copy(rt);
	}
	return *this;
}

RepeatTask::~RepeatTask() {
	delete current;
}

int RepeatTask::work(int t) {
	if (t <= 0)
		return t;

	// 1) довършваме current
	t = current->work(t);

	// 1а) дали сме завършили current?
	if (current->isFinished()) {
		resetCurrent();
		SimpleTask::work();
	}

	// 2) правим толкова повторения, колкото можем
	int repetitionsToMake = t / toRepeat->getTime();
	int repetitionsLeft = SimpleTask::work(repetitionsToMake);
	t -= (repetitionsToMake - repetitionsLeft) * toRepeat->getTime();

	// 3) започваме новия current, ако можем
	if (!isFinished()) {
		t = current->work(t);
	}

	return t;
}

void RepeatTask::resetCurrent() {
	// !!! current = new Task(toRepeat);
	delete current;
	current = (Task*)toRepeat->clone();
}
