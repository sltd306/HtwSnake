#ifndef GUI_H
#define GUI_H

#include "Util.h"
#include "Snake.h"

class GUI : public Util
{
public:
	GUI(): dichuyen(1) {}
	void Wall();

	void CheckColor();
	void KeyBoard(Snake& rSnake);
	void XuLy(Snake& rSnake);
	void GameOver(Snake& rSnake);
	void MainGame(Snake& rSnake, int color, Snake& rSnake1, int color1);
	void menu(Snake& rSnake,Snake& rSnake1);
	void Intro(Snake& rSnake, Snake& rSnake1);

private:
	int dichuyen;
};



#endif