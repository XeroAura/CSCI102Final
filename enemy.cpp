#include "enemy.h"

Enemy::Enemy(int x, int y){ //Creates enemy located at given x,y with image load and random direction.
  xdir = x;
  ydir = y;
direction = rand()%2;
if(direction == 0){
  image.load("bird-left.png");
}
else
image.load("bird-right.gif");
  rect = image.rect();
	rect.moveTo(450,450);
	
}

Enemy::Enemy(){ 
	direction = 0;
  xdir = 190;
  ydir = 240;

  image.load("bird-left.png");
  rect = image.rect();
	rect.moveTo(450,450);
}

Enemy::~Enemy() {
}

void Enemy::move(){ //Moves to coordinates
  rect.moveTo(QPoint(xdir,ydir));
}

void Enemy::hide(){ //Moves offscreen to hide enemy
	rect.moveTo(QPoint(450,450));
}

int Enemy::getXDir(){ //Returns x/y coordinates
  return xdir;
}

int Enemy::getYDir(){
  return ydir;
}

void Enemy::setXDir(int x){ //Sets x,y coordinates with boundary checkss
	if(xdir < 0)
		xdir = 399;
	else if(xdir > 400)
		xdir = 1;
	else xdir = x;
}

void Enemy::setYDir(int y){
	if(y >35 && y <380)	
		ydir = y;
}

int Enemy::getDirection(){ //Returns direction enemy is going in
	return direction;
}

QRect Enemy::getRect(){ //Returns rect object assigned to enemy
  return rect;
}

QImage& Enemy::getImage(){ //Returns sprite image assigned to enemy
	return image;
}

