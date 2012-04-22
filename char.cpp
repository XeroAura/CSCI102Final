#include "char.h"

Char::Char(){

  xdir = 190; //Default location of character
  ydir = 350;

  image.load("char.png");//Load .png sprite for character

  rect = image.rect();//Sets image to character and moves off screen
	rect.moveTo(-50,-50);
}

Char::~Char() {
}


void Char::reset(){ //Resets location to default
	xdir = 190;
	ydir = 360;  
	rect.moveTo(190, 360);
}

void Char::move(){ //Moves character to selected point
  rect.moveTo(QPoint(xdir,ydir));
}

void Char::move(int x, int y){
	rect.moveTo(QPoint(x,y));
}

int Char::getXDir(){//Returns x and y coordinates
  return xdir;
}

int Char::getYDir(){
  return ydir;
}

void Char::setXDir(int x){ //Sets x and y coordinates with boundaries check
	if(x>0 && x < 380)
		xdir = x;
}

void Char::setYDir(int y){
	if(y >35 && y <380)	
		ydir = y;
}

QRect Char::getRect(){ //Returns rect object assigned to character
  return rect;
}

QImage& Char::getImage(){ //Returns .png assigned to character
	return image;
}

