/*
 * repeat_task.h
 *
 *  Created on: 29.05.2015 г.
 *      Author: trifon
 */

#ifndef REPEAT_TASK_H_
#define REPEAT_TASK_H_

#include "simple_task.h"

#include <iostream>
using namespace std;

class RepeatTask : public SimpleTask {
private:
	Task const* toRepeat;
	Task* current;
	// SimpleTask::time го интерпретираме като
	// общ брой повторение
	// SimpleTask::progress го интерпретираме
	// като повторения, извършени до момента

	void resetCurrent();
	void copy(RepeatTask const&);

public:
	RepeatTask(char const*, Task const*, int);

	RepeatTask(RepeatTask const&);
	RepeatTask& operator=(RepeatTask const&);
	~RepeatTask();

	Cloneable* clone() const {
		return new RepeatTask(*this);
	}

	// извеждане на информация за задачата
	void print() const;

	int getRepetitions() const {
		return SimpleTask::getTime();
	}

	int getRepetitionProgress() const {
		return SimpleTask::getProgress();
	}

	// брой единици време за изпълнение на задачата
	int getTime() const {
		return toRepeat->getTime() *
			   getRepetitions();
	}

	// прогрес по задачата в единици време
	int getProgress() const {
		return toRepeat->getTime() *
				getRepetitionProgress() +
				toRepeat->getProgress();
	}

	// работа по задачата
	// връща неусвоените единици време
	int work(int = 1);
};



#endif /* REPEAT_TASK_H_ */
