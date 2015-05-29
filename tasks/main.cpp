/*
 * main.cpp
 *
 *  Created on: 28.05.2015 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;

#include "quick_task.h"
#include "simple_task.h"
#include "repeat_task.h"


int main() {
	// !!! Task t("Проба");
	QuickTask qt("Малко контролно");
	qt.print();cout << endl;
	qt.work();
	qt.print();cout << endl;

	SimpleTask st("Лекции", 3);
	do {
		st.print();cout << endl;
		cout << "Остават " << st.work(2) << " единици време\n";
	} while (st.getProgress() < st.getTime());
	st.print();cout << endl;

	for(int i = 0; i <= 20; i++) {
		SimpleTask st("Лекции", 3);
		RepeatTask rt("Курс", &st, 5);
		cout << "Започваме с " << i << " единици\n";
		cout << "Остават " << rt.work(i) << " единици\n";
		rt.print();cout << endl;
	}

	return 0;
}

