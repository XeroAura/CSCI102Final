#ifndef ENEMY_H
#define ENEMY_H

#include <QImage>
#include <QRect>
#include <QPoint>
#include <cstdlib>
#include <time.h>

class Enemy{

  public:
    Enemy(int,int);
    Enemy();
    ~Enemy();
    void move();
    int getXDir();
    int getYDir();
	void setXDir(int);
	void setYDir(int);
    QRect getRect();
	QImage& getImage();
	void hide();
	int getDirection();
  private:
    int xdir;
    int ydir;
    QImage image;
    QRect rect;
	int direction;
};

#endif
