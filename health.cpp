#include "health.h"

Health::Health(){ 
  xdir = 190;
  ydir = 240;
	onscreen = true;
  image.load("health.png");
  rect = image.rect();
	rect.moveTo(190,240);
}

Health::~Health() {
}

void Health::move(){ //Moves to set coordinates
  rect.moveTo(QPoint(xdir,ydir));
}

void Health:: changeUsed(bool toggle){//Changes if health pack is used.
	onscreen = toggle;
}

bool Health::returnUsed(){ //Returns if the health pack is used or not
	return onscreen;
}

