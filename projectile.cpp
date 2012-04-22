#include "projectile.h"//Projectile class

Projectile::Projectile(){ 
  xdir = -50; // Offscreen location
  ydir = -50;
	offscreen = true; //Sets projectile offscreen variable as start
  image.load("fire.png"); //Loads picture of fireball
  rect = image.rect();
}

Projectile::~Projectile() {
}

void Projectile::fire(int x, int y){ //Fire the projectile to x and y direction
	offscreen = false;
	xdir = x; ydir = y;
	rect.moveTo(QPoint(xdir,ydir));
}

void Projectile::move(){ //Move class that is empty. Virtual move functions in other derived classes

}

int Projectile::getXDir(){ //Returns x/y coordinates
  return xdir;
}

int Projectile::getYDir(){
  return ydir;
}

bool Projectile::getScreen(){ //Returns true if projectile is offscreen
	return offscreen;
}

QRect Projectile::getRect(){ //Returns rect object assigned to Projectile
  return rect;
}

QImage& Projectile::getImage(){ //Returns sprite image assigned to Projectile
	return image;
}

