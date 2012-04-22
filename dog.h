#ifndef DOG_H
#define DOG_H

#include <QImage>
#include <QRect>
#include <QPoint>
#include <math.h>
#include "projectile.h"

class Dog : public Projectile{
  public:
    Dog();
	~Dog();
	void reset();
	virtual void move(int);
  private:
	int counter;
};

#endif

