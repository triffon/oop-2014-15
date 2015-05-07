/*
 * ai.cpp
 *
 *  Created on: 7.05.2015 г.
 *      Author: trifon
 */

#include <cstring>
#include <iostream>
using namespace std;
#include "ai.h"

void AI::setAlgorithm(const char* _algo) {
	algorithm = new char[strlen(_algo)+1];
	strcpy(algorithm, _algo);
}

AI::AI(const char* _algo, double _threshold)
	: threshold(_threshold) {
	setAlgorithm(_algo);
}

AI::AI(const AI& ai)
	: threshold(ai.threshold) {
	setAlgorithm(ai.algorithm);
}

AI& AI::operator =(const AI& ai) {
	if (this != &ai) {
		threshold = ai.threshold;
		delete[] algorithm;
		setAlgorithm(ai.algorithm);
	}
	return *this;
}

AI::~AI() {
	delete[] algorithm;
}

void AI::print() const {
	cout << "Алгоритъм " << algorithm << " с праг " << threshold;
}
