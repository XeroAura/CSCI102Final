#ifndef BOSS_H
#define BOSS_H

#include <QImage>
#include <QRect>
#include <QPoint>
#include <cstdlib>
#include <time.h>

class Boss{

  public:
    Boss();
    ~Boss();
    void move();
	void reset();
    int getXDir();
    int getYDir();
	void setXDir(int);
	void setYDir(int);
    QRect getRect();
	QImage& getImage();
	void hide();
	int getDirection();
	int returnLives();
	int reduceLives();
  private:
    int xdir;
    int ydir;
	int lives;
    QImage image;
    QRect rect;
	int direction;
	bool acidon;
};

#endif
