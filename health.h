#ifndef HEALTH_H
#define HEALTH_H

#include <QImage>
#include <QRect>
#include <QPoint>
#include "item.h"

class Health : public Item {

  public:
    Health();
    ~Health();
    virtual void move();
	void changeUsed(bool);
	bool returnUsed();
  private:
	bool onscreen;
};

#endif
