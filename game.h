#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <QVector>
#include <QWidget>
#include <QKeyEvent>
#include <QPainter>
#include <QApplication> 
#include <QPushButton>
#include <QGraphicsObject>
#include <QLabel>
#include <QFont>
#include <QKeyEvent>
#include <QTimerEvent>
#include <QPaintEvent>
#include <QPalette>
#include "enemy.h"
#include "char.h"
#include "target.h"
#include "boss.h"
#include "bullet.h"
#include "acid.h"
#include "health.h"
#include "missile.h"
#include "turret.h"
#include "dog.h"

class Game : public QWidget {
	Q_OBJECT
	public:
		Game(QWidget *parent = 0);
 	   ~Game();
	private slots:
		void startClicked();
		void timerEvent(QTimerEvent*);
		void keyPressEvent(QKeyEvent*);
		void paintEvent(QPaintEvent*);
		void checkEvent();
		void restartMenu();
		void createEnemy();
		void secondMenu();
		void thirdMenu();
		void victoryMenu();
	private:
		QLabel *instructions;
		QLabel *instructions2;
		QLabel *instructions3;
		QLabel *label;
		QLabel *victory;
		QPushButton *start;
		QPushButton *start2;
		QPushButton *start3;
		QPushButton *restart;
		QPushButton *end;
		QLabel *score;
		QLabel *lives;
		QLabel *bosslives;
		QLabel *timerd;
		QPalette pal;
		int scorecnt;
		int livescnt;
		int timerId;
		int timerId2;
		int timerId3;
		Char *character;
		Target *target;
		Boss *boss;
		Acid *acid;
		QVector<Enemy*> enemies;
		Enemy *minion;
		Bullet *bullet;
		Health *health;
		Turret *turret;
		Dog *dog;
		QVector<Missile*> missiles;
		int side;
		int invincible;
		int level;
		bool fired;
		int lvltimer;
};

#endif

