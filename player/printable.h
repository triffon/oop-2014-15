/*
 * printable.h
 *
 *  Created on: 28.05.2015 г.
 *      Author: trifon
 */

#ifndef PRINTABLE_H_
#define PRINTABLE_H_

class Printable {
public:
	virtual void print() const = 0;
	virtual ~Printable() {}
};



#endif /* PRINTABLE_H_ */
