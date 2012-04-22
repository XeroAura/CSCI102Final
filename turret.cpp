#include "turret.h"

Turret::Turret(){
  xdir = 188; 
  ydir = 100;
  image.load("turret.png"); //Loads turret image
  rect = image.rect();
  rect.moveTo(-50,450);
}

Turret::~Turret(){

}

void Turret::hide(){ //Hides turret offscreen when called
	rect.moveTo(-50,450);
}	

