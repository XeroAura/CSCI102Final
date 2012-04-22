#ifndef ACID_H
#define ACID_H

#include <QImage>
#include <QRect>
#include <QPoint>
#include "projectile.h"

class Acid : public Projectile{
  public:
    Acid(int,int,int,int);
    Acid();
    ~Acid();
    virtual void move();
	void spit(int, int, int, int);
	void hit();
  private:
	int tarx;
	int tary;
};

#endif
