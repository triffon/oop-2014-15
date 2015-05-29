/*
 * quick_task.h
 *
 *  Created on: 28.05.2015 г.
 *      Author: trifon
 */

#ifndef QUICK_TASK_H_
#define QUICK_TASK_H_

#include "task.h"

class QuickTask : public Task {
private:
	bool finished;

public:
	QuickTask(char const*);

	// извеждане на информация за задачата
	void print() const;

	// брой единици време за изпълнение на задачата
	int getTime() const { return 1; }

	// прогрес по задачата в единици време
	int getProgress() const { return finished ? 1 : 0; }

	// работа по задачата
	// връща неусвоените единици време
	int work(int = 1);
};



#endif /* QUICK_TASK_H_ */
