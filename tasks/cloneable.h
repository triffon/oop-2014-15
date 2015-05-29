/*
 * cloneable.h
 *
 *  Created on: 29.05.2015 г.
 *      Author: trifon
 */

#ifndef CLONEABLE_H_
#define CLONEABLE_H_

class Cloneable {
public:
	virtual Cloneable* clone() const = 0;
	virtual ~Cloneable() {}
};



#endif /* CLONEABLE_H_ */
