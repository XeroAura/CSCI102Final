#include "bullet.h"

Bullet::Bullet(){ 
  xdir = -50;
  ydir = -50;
	offscreen = true;
  image.load("fire.png");
  rect = image.rect();
}

Bullet::~Bullet() {
}

void Bullet::move(){ //Moves to coordinates
	if(ydir < 0){//Makes sure bullet is stopped offscreen
		offscreen = true;
		rect.moveTo(-50,-50);
	}
	else{
		ydir-=5;
		rect.moveTo(QPoint(xdir,ydir));
	}
}

void Bullet::hit(){ //Resets bullet if it hits
	offscreen = true;
	rect.moveTo(-50,-50);	
}

