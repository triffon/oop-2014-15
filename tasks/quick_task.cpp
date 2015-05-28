/*
 * quick_task.cpp
 *
 *  Created on: 28.05.2015 г.
 *      Author: trifon
 */

#include "quick_task.h"

QuickTask::QuickTask(const char* _name)
	: Task(_name), finished(false) {
}

void QuickTask::print() const {
}

int QuickTask::work(int t) const {

}
