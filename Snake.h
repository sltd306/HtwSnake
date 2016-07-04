#ifndef SNAKE_H
#define SNAKE_H

#include "Util.h"

class Snake : public Util 
{
public:
	Snake(int speed = 0, int x = 10, int y = 10, int dot = 10, int live = 1, int nA=1) : m_speed(speed), m_x(x), m_y(y), m_dot(dot), m_live(live), n(nA){}

	void Speed();
	int getSpeed() { return m_speed; }
	void VicTim();
	int getX(){ return m_x; }
	void setX(int a) { m_x += a; }
	int getY(){ return m_y; }
	void setY(int a) { m_y += a; }
	int getDot() { return m_dot; }
	int getLive() { return m_live; }
	int getHighScore() { return savedot; }
	void setMang(int a) { m_live = a; }
	void addMang(int a) { m_live += a; }
	void printSnake();
	void printSnake2();
	void setSpeed(int a){ m_speed = a; }
	void LoadScore();
	void SaveScore();
	void DieuKien();
	void setMaps();
	int getMapsValue(int a, int b)	{ return maps[a][b]; }
	void XoaDauVet();
	void snakeMove(); // neue Funktion des Schlange
	void snakeMove2();

private:
	int m_speed, m_x, m_y, m_dot, m_live;
	vector<vector<int> > maps;
	int n;
};


#endif