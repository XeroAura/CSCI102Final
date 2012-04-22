#ifndef ITEM_H
#define ITEM_H

#include <QImage>
#include <QRect>
#include <QPoint>

class Item{

  public:
    Item();
    ~Item();
    void move();
    int getXDir();
    int getYDir();
	void setXDir(int);
	void setYDir(int);
    QRect getRect();
	QImage& getImage();
	void hide();
  protected:
    int xdir;
    int ydir;
    QImage image;
    QRect rect;
};

#endif
