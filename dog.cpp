#include "dog.h"

Dog::Dog(){
  //32x23 image size
  xdir = 184;
  ydir = 50;
	counter=0;
  image.load("dog.png");
  rect = image.rect();
	rect.moveTo(500,500);
}

Dog::~Dog(){

}

void Dog::move(int x){ //Movement function
	if(x>xdir && counter%2==0){//Moves right every other turn
		xdir++;
	}
	else if(x<xdir && counter%2==0){//Moves left every other turn
		xdir--;
	}
	ydir++; //Moves dog downward
	counter++;//Counter for turns
	if(ydir>400)
		ydir = 0;
	rect.moveTo(QPoint(xdir,ydir));
}

void Dog::reset(){ //Sets dog to top of screen again
	xdir = 184; ydir=50;
	rect.moveTo(184,50);
}

