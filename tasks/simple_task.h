/*
 * simple_task.h
 *
 *  Created on: 29.05.2015 г.
 *      Author: trifon
 */

#ifndef SIMPLE_TASK_H_
#define SIMPLE_TASK_H_

#include "task.h"

class SimpleTask : public Task {
private:
	int progress;
	int time;

public:

	SimpleTask(char const*, int);

	Cloneable* clone() const {
		return new SimpleTask(*this);
	}

	// извеждане на информация за задачата
	void print() const;

	// брой единици време за изпълнение на задачата
	int getTime() const { return time; }

	// прогрес по задачата в единици време
	int getProgress() const { return progress; }

	// работа по задачата
	// връща неусвоените единици време
	int work(int = 1);

};



#endif /* SIMPLE_TASK_H_ */
