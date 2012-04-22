#include "target.h"

Target::Target(){ 
  xdir = 180;
  ydir = 50;
  image.load("target.png"); //Loads image of target
  rect = image.rect();
	rect.moveTo(450,450);
}

Target::~Target() {
}

