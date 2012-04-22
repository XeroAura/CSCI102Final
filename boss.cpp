#include "boss.h"

Boss::Boss(){ 
	direction = 0;
  xdir = 180;
  ydir = 50;
	lives = 8;
  image.load("boss.png");
  rect = image.rect();
	rect.moveTo(450,450);
}

Boss::~Boss() {
}

void Boss::reset(){
	xdir = 180;
	ydir = 50;
	rect.moveTo(QPoint(180,50));
}

void Boss::move(){ //Moves to coordinates
	if(xdir <= 0)
		direction = 1;
	else if(xdir >= 350)
		direction = 0;

	if(direction == 0)
		xdir-=1;
	else
		xdir+=1;  

	rect.moveTo(QPoint(xdir,ydir));
}

void Boss::hide(){ //Moves offscreen to hide Boss
	rect.moveTo(QPoint(460,460));
}

int Boss::getXDir(){ //Returns x/y coordinates
  return xdir;
}

int Boss::getYDir(){
  return ydir;
}

void Boss::setXDir(int x){ //Sets x,y coordinates with boundary checkss
	xdir =x;
}


void Boss::setYDir(int y){ 
		ydir = y;
}

int Boss::returnLives(){//Returns number of lives
	return lives;
}

int Boss::reduceLives(){//Reduces life count
	lives--;
	return 0;
}

int Boss::getDirection(){ //Returns direction Boss is going in
	return direction;
}

QRect Boss::getRect(){ //Returns rect object assigned to Boss
  return rect;
}

QImage& Boss::getImage(){ //Returns sprite image assigned to Boss
	return image;
}

