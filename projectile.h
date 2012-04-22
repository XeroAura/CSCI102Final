#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QImage>
#include <QRect>
#include <QPoint>

class Projectile{
  public:
    Projectile();
    ~Projectile();
    int getXDir();
    int getYDir();
	void move();
	bool getScreen();
    QRect getRect();
	void fire(int, int);
	QImage& getImage();
  protected:
    int xdir;
    int ydir;
	bool offscreen;
    QImage image;
    QRect rect;
};

#endif
