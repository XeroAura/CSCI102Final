#include "game.h"

using namespace std;

Game :: Game(QWidget *parent) : QWidget(parent){
	resize(400,400);
	setWindowTitle("Dodger");		
	
	pal.setColor(QPalette::Background, Qt::white);
	setPalette(pal);
	livescnt = 3;
	side = 0;
	invincible = 0;
	level = 1;
	srand(time(0));

	character = new Char();	 
	target = new Target();
	//Instructions
	instructions = new QLabel("  Get to the target. WASD for movement.\n Reach a score of 8 to get to the next level.",this); 	
	label = new QLabel("Dodger", this);	
	start = new QPushButton("&Start", this); //Start button
	label->setFont(QFont("Times", 20));
	label->setGeometry(150,50,150,50);
	instructions->setFont(QFont("Times", 12));
	instructions->setGeometry(25,125,350,100);
	start -> setGeometry(135,250,125,45);
	label ->show();
	start ->show();
	instructions ->show();	

	score = new QLabel("Score:", this); //Score and life counters
	score ->setFont(QFont("Times",12));
	score ->setGeometry(5,0,100,50);
	score->hide();
	lives = new QLabel("Lives:", this);
	lives ->setFont(QFont("Times",12));
	lives ->setGeometry(120,0,100,50);
	lives->hide();
	
	restart = new QPushButton("Restart", this); //Exit menu widgets
	restart->setFont(QFont("Times", 20));
	restart->setGeometry(135,150,125,50);
	end = new QPushButton("Exit", this);
	end->setFont(QFont("Times", 20));
	end->setGeometry(135,250,125,50);
	restart->hide();
	end->hide();

	bosslives = new QLabel("Boss life:", this); //Boss life counter
	bosslives ->setFont(QFont("Times",12));
	bosslives ->setGeometry(5,0,100,50);
	bosslives->hide();
	
	instructions2 = new QLabel("       	  Shoot with F key.\n	Boss takes 8 shots to kill.\n         There is also one health pack.",this); //2nd spot instructions
	instructions2->setFont(QFont("Times", 12));
	instructions2->setGeometry(25,110,350,100);
	instructions2->hide();
	start2 = new QPushButton("Start", this);//Start button for second lvl
	start2 -> setGeometry(135,250,125,45);
	start2 ->hide();

	instructions3 = new QLabel("       Avoid the fireballs and the dog.\n	Survive the countdown.", this); //Third portion instructions
	instructions3 ->setFont(QFont("Times",12));
	instructions3 -> setGeometry(25,110,350,100);
	instructions3->hide();
	start3 = new QPushButton("Start", this);//Start button for third lvl
	start3->setGeometry(135,250,125,45);
	start3->hide();
	
	victory = new QLabel("Victory!",this); //Victory screen note
	victory->setGeometry(165,100,100,50);
	victory->setFont(QFont("Times",12));
	victory->hide();
	timerd = new QLabel("Timer: " ,this);//Timer counter
	timerd->setText("Time: " + QString::number(lvltimer));
	timerd->hide();
	timerd->setGeometry(5,0,100,50);
	timerd->setFont(QFont("Times",12));
	
	connect(start, SIGNAL(clicked()), this, SLOT(startClicked()));
	
}

Game:: ~Game(){
	delete minion;
	delete boss;
	delete acid;
	delete bullet;
	delete health;
	delete character;
	delete target;
	delete turret;
	delete dog;
}

void Game::createEnemy(){ //Function to create enemy sprites
	Enemy* temp = new Enemy(1,(150+20*(scorecnt%5)));
	enemies.push_back(temp);
}

void Game:: startClicked(){ //Click start button on main menu
	victory->hide();
	if(level == 1){//First level (frogger style)
		pal.setColor(QPalette::Background, Qt::blue);//Sets background blue
		setPalette(pal);		
		livescnt = 3;
		scorecnt = 7;
		side = 0;
		label-> hide();//Hides main menu items
		instructions -> hide();
		start -> hide();
		restart->hide();
		end->hide();
		score -> show(); //Shows score and lives
		score -> setText("Score: " + QString::number(scorecnt));
		lives ->show();
		lives -> setText("Lives: " + QString::number(livescnt));
		character->reset(); //Resets character
		target -> setXDir(185);
		target -> setYDir(50);
		target ->move();
		for(int i =0;i<enemies.size();i++){	 //Deletes enemies correctly
			Enemy* temp = enemies[i];
			delete temp;
		}
		enemies.clear();
		for(int i = 0; i<5; i++){ //Creates initial enemies
			Enemy* temp = new Enemy((50+40*i),(150+20*i));
			enemies.push_back(temp);
		}
		killTimer(timerId);
		timerId = startTimer(20);
	}
	else if(level == 2 || level == -1){ //Second level (acid spit snake battle)
		pal.setColor(QPalette::Background, Qt::green);//sets background green
		setPalette(pal);	
		livescnt = 3;
		level = 2;		
		scorecnt = 0;
		instructions2->hide();//Shows and hides appropriate screen GUIs
		start2 -> hide();
		score -> hide();
		label -> hide();
		end -> hide();
		restart -> hide();
		boss = new Boss();
		boss->reset();
		bullet = new Bullet();
		fired = false;
		acid = new Acid();
		health = new Health();
		minion = new Enemy();
		minion->move();
		lives -> setText("Lives: " + QString::number(livescnt));
		bosslives -> setText("Boss Life: " + QString::number(boss->returnLives()));
		bosslives -> show();
		character -> reset();
		lives -> show();
		killTimer(timerId2); //Starts timer for second lvl
		timerId2 = startTimer(20);
	}
	else if(level == 3 || level == -2){
		pal.setColor(QPalette::Background, Qt::gray); //Set background to gray
		setPalette(pal);
		livescnt = 3;
		level = 3;
		instructions3->hide();//Hide and shows right GUIs
		start3->hide();
		label -> hide();
		score -> hide();
		lives -> show();
		restart->hide();
		end->hide();
		character->reset();
		turret = new Turret();
		turret->move();
		dog = new Dog();
		lvltimer = 900;//Sets timer to 600 timer events
		timerd->show();
		killTimer(timerId3);//Starts 3rd lvl timer
		timerId3 = startTimer(20);

	}
}

void Game:: victoryMenu(){
	level=1;//sets level back to 1
	pal.setColor(QPalette::Background, Qt::white);
	setPalette(pal);	
	victory->show();//Shows correct GUI portions
	label-> show(); 
	restart->show();
	end->show();
	timerd->hide();
	lives -> hide();
	character->move(-50,-50); //Hides character
	target->hide();
	connect(restart, SIGNAL(clicked()), this, SLOT(startClicked())); //Option connects
	connect(end, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void Game:: thirdMenu(){ //Menu before third level
	pal.setColor(QPalette::Background, Qt::white);
	setPalette(pal);
	bosslives->hide();
	lives -> hide();
	label -> show();
	instructions3->show();
	start3->show();
	connect(start3, SIGNAL(clicked()),this,SLOT(startClicked()));
}

void Game:: secondMenu(){//Menu before second level
	pal.setColor(QPalette::Background, Qt::white);
	setPalette(pal);
	for(int i =0;i<enemies.size();i++){	 //Deletes enemies correctly
		Enemy* temp = enemies[i];
		delete temp;
	}
	enemies.clear();
	score -> hide();
	lives -> hide();
		label -> show();
	instructions2 -> show();
	start2 -> show();
	connect(start2, SIGNAL(clicked()), this, SLOT(startClicked()));
}

void Game:: restartMenu(){ //Restart menu GUI
	pal.setColor(QPalette::Background, Qt::white);
	setPalette(pal);
	label-> show(); //Shows correct GUI portions
	restart->show();
	end->show();
	score -> hide();
	lives -> hide();
	connect(restart, SIGNAL(clicked()), this, SLOT(startClicked())); //Option connects
	connect(end, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void Game::checkEvent(){
	if(level == 1){	
		bool collided = false;
		int lefta, leftb, righta, rightb, topa, topb, bota, botb;
		lefta = character->getXDir();//Coordinates for character sprite
		righta = lefta+20;
		topa = character ->getYDir();
		bota = topa+20;
		//Check for collisions
		for(int i = 0; i<enemies.size();i++){
			leftb = enemies[i]->getXDir();
			rightb = leftb+20;
			topb = enemies[i]->getYDir();
			botb = topb+20;
			if(bota>topb-1 && bota<botb+1 && lefta<rightb+1 && lefta>leftb-1){//Bottom left corner
				collided = true;
			}
			else if(bota>topb-1 && bota<botb+1 && righta<rightb+1 && righta>leftb-1){ //Bottom right corner
				collided = true;
			}
			else if(topa>topb-1 && topa<botb+1 && lefta<rightb+1 && lefta>leftb-1){//Top left corner
				collided = true;
			}
			else if(topa>topb-1 && topa<botb+1 && righta<rightb+1 && righta>leftb-1){//Top right corner
				collided = true;
			}
		}
		if(collided && invincible <1){ //Collision detected
			side = 0;
			character->reset();
			livescnt--;
			invincible = 8;
			collided = false;
			lives -> setText("Lives: " + QString::number(livescnt));
			target -> setXDir(185);
			target -> setYDir(50);
			target -> move();
		}
	//Check for score, if so difficulty++
		else if(side == 0 && character->getYDir() < 130){
			if(topa >target->getYDir() && bota< target->getYDir()+35 && lefta >target->getXDir() && righta < target->getXDir()+35){		
				side = 1;
				scorecnt++;
				score -> setText("Score: " + QString::number(scorecnt));
				createEnemy();
				target -> setXDir(185);
				target -> setYDir(325);
				target ->move();
			}
		}
		else if(side == 1 && character -> getYDir() > 250){
			if(topa >target->getYDir() && bota< target->getYDir()+35 && lefta >target->getXDir() && righta < target->getXDir()+35){		
				side = 0;
				scorecnt++;
				score -> setText("Score: " + QString::number(scorecnt));
				createEnemy();
				target -> setXDir(185);
				target -> setYDir(50);
				target -> move();
			}
		}
		if(scorecnt > 7){
			level = -1;
		}
	}
	else if(level == 2){
		//Check for collisions with boss attacks.
		if(acid -> getScreen()){
			acid -> spit(character->getXDir(), character->getYDir(), boss->getXDir(), boss->getYDir());
		}
		bool hit = false;
		if(!(acid -> getScreen())){		
			int lefta, leftb, righta, rightb, topa, topb, bota, botb;
			lefta = character->getXDir();//Coordinates for bullet sprite
			righta = lefta+20;
			topa = character ->getYDir();
			bota = topa+20;
			leftb = acid->getXDir();
			rightb = leftb+20;
			topb = acid->getYDir();
			botb = topb+20;
			if(bota>topb-1 && bota<botb+1 && lefta<rightb+1 && lefta>leftb-1){//Bottom left corner
				hit = true;
			}
			else if(bota>topb-1 && bota<botb+1 && righta<rightb+1 && righta>leftb-1){ //Bottom right corner
				hit = true;
			}
			else if(topa>topb-1 && topa<botb+1 && lefta<rightb+1 && lefta>leftb-1){//Top left corner
				hit = true;
			}
			else if(topa>topb-1 && topa<botb+1 && righta<rightb+1 && righta>leftb-1){//Top right corner
				hit = true;
			}
		}
		if(true){		//Check for collision with bird
			int lefta, leftb, righta, rightb, topa, topb, bota, botb;
			lefta = character->getXDir();//Coordinates for bullet sprite
			righta = lefta+20;
			topa = character->getYDir();
			bota = topa+20;
			leftb = minion->getXDir();
			rightb = leftb+50;
			topb = minion->getYDir();
			botb = topb+50;
			if(bota>topb-1 && bota<botb+1 && lefta<rightb+1 && lefta>leftb-1){//Bottom left corner
				hit = true;
			}
			else if(bota>topb-1 && bota<botb+1 && righta<rightb+1 && righta>leftb-1){ //Bottom right corner
				hit = true;
			}
			else if(topa>topb-1 && topa<botb+1 && lefta<rightb+1 && lefta>leftb-1){//Top left corner
				hit = true;
			}
			else if(topa>topb-1 && topa<botb+1 && righta<rightb+1 && righta>leftb-1){//Top right corner
				hit = true;
			}
		}
		if(hit && invincible < 1){			
			livescnt--;
			lives -> setText("Lives: " + QString::number(livescnt));
			hit = false;
			acid->hit();
			invincible = 40;		
		}
		
		//Check for firing own bullets.
		if(fired){
			fired = false;
			if(bullet->getScreen()){
				bullet -> fire(character->getXDir(), character->getYDir());
			}
		}
		//Check for bullets hitting boss.
		bool collided = false;
		if(!(bullet -> getScreen())){		
			int lefta, leftb, righta, rightb, topa, topb, bota, botb;
			lefta = bullet->getXDir();//Coordinates for bullet sprite
			righta = lefta+20;
			topa = bullet ->getYDir();
			bota = topa+20;
			leftb = boss->getXDir();
			rightb = leftb+50;
			topb = boss->getYDir();
			botb = topb+50;
			if(bota>topb-1 && bota<botb+1 && lefta<rightb+1 && lefta>leftb-1){//Bottom left corner
				collided = true;
			}
			else if(bota>topb-1 && bota<botb+1 && righta<rightb+1 && righta>leftb-1){ //Bottom right corner
				collided = true;
			}
			else if(topa>topb-1 && topa<botb+1 && lefta<rightb+1 && lefta>leftb-1){//Top left corner
				collided = true;
			}
			else if(topa>topb-1 && topa<botb+1 && righta<rightb+1 && righta>leftb-1){//Top right corner
				collided = true;
			}
		}
		if(collided){
			bullet->hit();			
			boss->reduceLives();
			bosslives -> setText("Boss Life: " + QString::number(boss->returnLives()));
			collided = false;		
		}
		if(boss ->returnLives() == 0){
			level = -2;
		}
		//Health pack pick up logic
		if(health->returnUsed()){
			int lefta, leftb, righta, rightb, topa, topb, bota, botb;
			lefta = character->getXDir();//Coordinates for bullet sprite
			righta = lefta+20;
			topa = character ->getYDir();
			bota = topa+20;
			leftb = health->getXDir();
			rightb = leftb+20;
			topb = health->getYDir();
			botb = topb+20;
			if(bota>topb-1 && bota<botb+1 && lefta<rightb+1 && lefta>leftb-1){//Bottom left corner
				health->changeUsed(false);
				livescnt++;
			}
			else if(bota>topb-1 && bota<botb+1 && righta<rightb+1 && righta>leftb-1){ //Bottom right corner
				health->changeUsed(false);
				livescnt++;
			}
			else if(topa>topb-1 && topa<botb+1 && lefta<rightb+1 && lefta>leftb-1){//Top left corner
				health->changeUsed(false);
				livescnt++;
			}
			else if(topa>topb-1 && topa<botb+1 && righta<rightb+1 && righta>leftb-1){//Top right corner
				health->changeUsed(false);
				livescnt++;
			}
			lives -> setText("Lives: " + QString::number(livescnt));
		}
	}
	else if(level == 3){
		//Check for dog hitting char and missile hitting char
		bool shot = false;
		for(int i = 0; i<missiles.size();i++){		
		if(!(missiles[i] -> isOffScreen())){		
			int lefta, leftb, righta, rightb, topa, topb, bota, botb;
			lefta = character->getXDir();
			righta = lefta+20;
			topa = character ->getYDir();
			bota = topa+20;
			leftb = missiles[i]->bxdir;
			rightb = leftb+20;
			topb = missiles[i]->bydir;
			botb = topb+20;
			if(bota>topb-1 && bota<botb+1 && lefta<rightb+1 && lefta>leftb-1){//Bottom left corner
				shot = true;
			}
			else if(bota>topb-1 && bota<botb+1 && righta<rightb+1 && righta>leftb-1){ //Bottom right corner
				shot = true;
			}
			else if(topa>topb-1 && topa<botb+1 && lefta<rightb+1 && lefta>leftb-1){//Top left corner
				shot = true;
			}
			else if(topa>topb-1 && topa<botb+1 && righta<rightb+1 && righta>leftb-1){//Top right corner
				shot = true;
			}
		}
		if(shot && invincible < 1){			
			livescnt--;
			lives -> setText("Lives: " + QString::number(livescnt));
			shot = false;
			invincible = 40;		
		}
	}
	shot = false;
		for(int i = 0; i<missiles.size();i++){		
		if(!(missiles[i] -> isOffScreen())){		
			int lefta, leftb, righta, rightb, topa, topb, bota, botb;
			lefta = character->getXDir();
			righta = lefta+20;
			topa = character ->getYDir();
			bota = topa+20;
			leftb = dog->getXDir();
			rightb = leftb+32;
			topb = dog->getYDir();
			botb = topb+23;
			if(bota>topb-1 && bota<botb+1 && lefta<rightb+1 && lefta>leftb-1){//Bottom left corner
				shot = true;
			}
			else if(bota>topb-1 && bota<botb+1 && righta<rightb+1 && righta>leftb-1){ //Bottom right corner
				shot = true;
			}
			else if(topa>topb-1 && topa<botb+1 && lefta<rightb+1 && lefta>leftb-1){//Top left corner
				shot = true;
			}
			else if(topa>topb-1 && topa<botb+1 && righta<rightb+1 && righta>leftb-1){//Top right corner
				shot = true;
			}
		}
		if(shot && invincible < 1){			
			livescnt--;
			lives -> setText("Lives: " + QString::number(livescnt));
			shot = false;
			invincible = 40;		
		}
	}
}
}

void Game::timerEvent(QTimerEvent *event){ //Timer event
	if(level == 1){
		for(int i = 0; i<enemies.size(); i++){ //Auto move enemies
			if(enemies[i]->getDirection() == 1)
				enemies[i]->setXDir(enemies[i]->getXDir()+1);
			else
				enemies[i]->setXDir(enemies[i]->getXDir()-1);
			enemies[i]->move();
		}
		checkEvent(); //Check for collisions or score
		repaint(); //Repaint screen
		if(invincible > 0) //Invincibility countdown
			invincible--;
	}
	else if(level == -1){
		cout<<"Finishing lvl 1"<<endl;
		killTimer(timerId);
		secondMenu();
	}
	else if(level == 2){
		boss->move();
		checkEvent();
		repaint();
		if(invincible > 0) //Invincibility countdown
			invincible--;				
	}
	else if(level == -2){
		cout<<"Finishing lvl 2"<<endl;
		killTimer(timerId2);
		thirdMenu();
	}
	else if(level == 3){//Level three
		checkEvent();
		repaint();
		if(invincible > 0)
			invincible--;
		if(lvltimer > 0){
			lvltimer--;
			timerd->setText("Time: " + QString::number(lvltimer));
		}
		else
			level = -3;
		if(level == -3){
			cout<<"Victory."<<endl;
			killTimer(timerId3);
			victoryMenu();		
		}
	}
	if(livescnt == 0){ //Game over 
		cout<<"Game over."<<endl;
		killTimer(timerId);
		killTimer(timerId2);
		killTimer(timerId3);
		restartMenu();
	}
}

void Game::paintEvent(QPaintEvent *event){ //Painter event
	QPainter painter(this);
	painter.setBackground(QBrush(Qt::blue));
	if(level == 1){
		//Draws character and enemies
			painter.drawImage(target -> getRect(), target ->getImage());
			painter.drawImage(character -> getRect(), character -> getImage());
			for(int i = 0; i<enemies.size(); i++){
				Enemy* temp = enemies[i];
				painter.drawImage(temp->getRect(),temp->getImage());
		}
	}
	else if(level == 2){
		if(livescnt == 0){//Death test
			killTimer(timerId2);
			restartMenu();
		}
		else{
			if(health->returnUsed()){			
				painter.drawImage(health->getRect(), health->getImage());
			}
			painter.drawImage(character -> getRect(), character -> getImage());
			if(!(bullet -> getScreen())){			
				bullet -> move();
				painter.drawImage(bullet -> getRect(), bullet -> getImage());
			}
			minion->setXDir(minion->getXDir()-1);
			minion->move();
			painter.drawImage(minion->getRect(), minion->getImage());
			painter.drawImage(boss -> getRect(), boss -> getImage());
			if(!(acid -> getScreen())){	
				acid -> move();		
				painter.drawImage(acid -> getRect(), acid -> getImage());		
			}
		}
	}
	else if(level == 3){
		if(livescnt == 0){ //Test for death
			killTimer(timerId3);
			restartMenu();
		}
		else{//Draw images
			painter.drawImage(character -> getRect(), character -> getImage());
			painter.drawImage(turret -> getRect(), turret->getImage());
			if(lvltimer%50 == 0){
				missiles.push_front(new Missile());
				missiles[0]->fire(double(character->getXDir()),double(character->getYDir()));
			}
			for(int j = 0;j<missiles.size();j++){
				if(!(missiles[j]->isOffScreen())){				
					missiles[j]->move();
					painter.drawImage(missiles[j]->getRect(), missiles[j]->getImage());
				}
			}
			dog->move(character->getXDir());
			painter.drawImage(dog->getRect(),dog->getImage());
		}
	}
}

void Game::keyPressEvent(QKeyEvent *press){ //Key press event for movement
	switch (press->key()) {
    case Qt::Key_A: //Left
		{  
        int x = character->getRect().x();        
		character->setXDir(x-5);
		character->move();
        break;
       }
    case Qt::Key_D://Right
        { 
          int x = character->getRect().x();
          character->setXDir(x+5);
			character->move();
        }
        break;
	case Qt::Key_W: //Up
		{
			int y = character -> getRect().y();       
			character->setYDir(y-5);
			character->move();
		}
		break;
	case Qt::Key_S: //Down
		{
			int y = character -> getRect().y();
            character->setYDir(y+5);
			character->move();
		}
		break;
    case Qt::Key_Escape: //Escape key for quick exit
        {
          qApp->exit();
        }
        break;
	case Qt::Key_F:{
		fired = true;
	}
	break;
	default:
		QWidget::keyPressEvent(press);
	}
}

