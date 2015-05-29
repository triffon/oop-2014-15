/*
 * task.h
 *
 *  Created on: 28.05.2015 г.
 *      Author: trifon
 */

#ifndef TASK_H_
#define TASK_H_

#include "cloneable.h"

class Task : public Cloneable {
private:
	char* name;

	void setName(char const*);

public:

	// голяма 4

	Task(char const* = "<неизвестна>");
	Task(Task const&);
	Task& operator=(Task const&);
	// виртуален деструктор
	virtual ~Task();

	char const* getName() const { return name; }

	bool isFinished() const {
		return getProgress() == getTime();
	}


	/*** Интерфейс ***/

	// извеждане на информация за задачата
	virtual void print() const;

	// брой единици време за изпълнение на задачата
	virtual int getTime() const = 0;

	// прогрес по задачата в единици време
	virtual int getProgress() const = 0;

	// работа по задачата
	// връща неусвоените единици време
	virtual int work(int = 1) = 0;

	/*******/
};



#endif /* TASK_H_ */
