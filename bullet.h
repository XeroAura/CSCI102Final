#ifndef BULLET_H
#define BULLET_H

#include <QImage>
#include <QRect>
#include <QPoint>
#include "projectile.h"

class Bullet : public Projectile{
  public:
    Bullet();
    ~Bullet();
	virtual void move();
	void hit();
  private:

};

#endif
