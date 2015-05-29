/*
 * main.cpp
 *
 *  Created on: 28.05.2015 г.
 *      Author: trifon
 */

#include "quick_task.h"

int main() {
	// !!! Task t("Проба");
	QuickTask t("Малко контролно");
	t.print();cout << endl;
	t.work();
	t.print();cout << endl;
	return 0;
}

