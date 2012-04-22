#include "missile.h"

Missile::Missile(){
  bxdir = 188;
  bydir = 100;
	counter = 0;
  image.load("fire.png");
  rect = image.rect();
	rect.moveTo(-50,450);
	offscreen = true;
}

Missile::~Missile(){

}

void Missile::move(){ //move class that sends the missile directly at location of character
	if(counter%2==0){//Reduces move speed by half
	bxdir+=directx;
	bydir+=directy;
	}
	counter++;
	rect.moveTo(QPoint(bxdir,bydir));
	if(bxdir<0 || bxdir> 400 || bydir>400 || bydir<0 ){ //Sets missile offscreen
		offscreen = true;
	}
}

void Missile::fire(double x, double y){ //Called to fire missile at the location
	bxdir = 188; bydir = 100;	
	rect.moveTo(bxdir, bydir);
	double z = sqrt(pow(x-188,2)+pow(y-175,2));//Math logic to determine distance to move each turn
	directx = (x-188)/(z);
	directy = (y-175)/(z);
	offscreen = false;
}

void Missile::hide(){ //Hides missile offscreen
	rect.moveTo(-50,450);
	offscreen = true;
}

bool Missile::isOffScreen(){ //Returns bool to see if missile is offscreen
	return offscreen;
}

