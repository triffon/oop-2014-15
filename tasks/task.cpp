/*
 * task.cpp
 *
 *  Created on: 28.05.2015 г.
 *      Author: trifon
 */

#include <cstring>

#include "task.h"

void Task::setName(const char* _name) {
	delete[] name;
	name = new char[strlen(_name)+1];
	strcpy(name, _name);
}

Task::Task(const char* _name) : name(NULL) {
	setName(_name);
}

Task::Task(const Task& task) : name(NULL) {
	setName(task.name);
}

Task& Task::operator =(const Task& task) {
	if (this != &task)
		setName(task.name);
	return *this;
}

Task::~Task() {
	delete[] name;
}
