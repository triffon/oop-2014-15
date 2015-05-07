/*
 * ai.h
 *
 *  Created on: 7.05.2015 г.
 *      Author: trifon
 */

#ifndef AI_H_
#define AI_H_

class AI {
private:
	char* algorithm;
	double threshold;

	void setAlgorithm(char const*);

public:
	// конструктор
	AI(char const* _algo, double _threshold);

	// голяма 3
	AI(AI const&);
	AI& operator=(AI const&);
	~AI();

	// селектори
	char const* getAlgorithm() const { return algorithm; }
	double getThreshold() const { return threshold; }

	void print() const;

	/*
	char const* decide(char const* options) {
		....
	}
	*/

protected:
	// мутатори
	void setThreshold(double _t) { threshold = _t; }
};



#endif /* AI_H_ */
