#include "acid.h"

Acid::Acid(int x, int y, int targx, int targy){ //Creates Acid located at given x,y with image load

  xdir = x;
  ydir = y;
	offscreen = true;
	tarx= targx;
	tary = targy;
  image.load("acid.png");
  rect = image.rect();
}

Acid::Acid(){ 
  xdir = 200;
  ydir = 200;
	tarx = 200;
	tary = 400;
	offscreen = true;
  image.load("acid.png");
  rect = image.rect();
}

Acid::~Acid() {
}

void Acid::move(){ //Moves to coordinates
	if(xdir > 400|| ydir <0 || ydir > 400){ //Test if acid fire is offscreen
		offscreen = true;
		rect.moveTo(500,500);
	}
	else{//Moves acid towards character
		ydir+=3;
		if(xdir > tarx)
			xdir-=5;
		else if(xdir < tarx)
			xdir+=5;
	}
	rect.moveTo(QPoint(xdir,ydir));
}

void Acid::spit(int x, int y, int a, int b){ //Fires acid bullet at target location
	tarx=x; tary=y;
	xdir = a+25;
	ydir = b+50;
	rect.moveTo(QPoint(xdir,ydir));
	offscreen = false;
}

void Acid::hit(){ //Records hits
	offscreen = true;
}

