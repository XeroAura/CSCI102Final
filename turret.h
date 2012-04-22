#ifndef TURRET_H
#define TURRET_H

#include <QImage>
#include <QRect>
#include <QPoint>
#include "item.h"

class Turret : public Item{
  public:
    Turret();
	~Turret();
	void hide();  
	private:
    
};

#endif

