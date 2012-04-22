#include "game.h"
#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[]){

	QApplication app(argc, argv);
	Game game;
	game.show();
	return app.exec();
}

