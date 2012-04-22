#ifndef MISSILE_H
#define MISSILE_H

#include <QImage>
#include <QRect>
#include <QPoint>
#include <math.h>
#include "projectile.h"

class Missile : public Projectile{
  public:
    Missile();
	~Missile();
	virtual void move();
	virtual void fire(double, double);
	void hide();
	bool isOffScreen();
	
	double bxdir;
	double bydir;
  private:
	double directx;
	double directy;
	bool offscreen;
	int counter;
};

#endif

