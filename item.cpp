#include "item.h"//Item class when other item classes can be derived from

Item::Item(){ 
  xdir = 180;
  ydir = 50;

  image.load("Item.png");
  rect = image.rect();
	rect.moveTo(450,450);
}

Item::~Item() {
}

void Item::move(){ //Moves to coordinates
  rect.moveTo(QPoint(xdir,ydir));
}

void Item::hide(){ //Moves offscreen to hide enemy
	rect.moveTo(QPoint(500,-50));
}

int Item::getXDir(){ //Returns x/y coordinates
  return xdir;
}

int Item::getYDir(){
  return ydir;
}

void Item::setXDir(int x){ //Sets x,y coordinates with boundary checkss
	xdir = x;
}

void Item::setYDir(int y){
	ydir = y;
}

QRect Item::getRect(){ //Returns rect object assigned to enemy
  return rect;
}

QImage& Item::getImage(){ //Returns sprite image assigned to enemy
	return image;
}

