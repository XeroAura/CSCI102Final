#ifndef CHAR_H
#define CHAR_H

#include <QImage>
#include <QRect>
#include <QPoint>

class Char{

  public:
    Char();
    ~Char();
    void reset();
	void move();
	void move(int, int);
    int getXDir();
    int getYDir();
	void setXDir(int);
	void setYDir(int);
    QRect getRect();
	QImage& getImage();
  private:
    int xdir;
    int ydir;
    QImage image;
    QRect rect;

};

#endif
