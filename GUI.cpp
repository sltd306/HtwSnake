#include "GUI.h"

void GUI::Wall()
{
	for (int i = 5; i<70; i++){
		this->Textcolor(10);
		this->GotoXY(i, 4); cout << char(205);
		this->GotoXY(i, 30); cout << char(205);
	}
	//in vien doc
	for (int i = 5; i<30; i++){
		this->GotoXY(4, i); cout << char(186);
		this->GotoXY(70, i); cout << char(186);
	}
}

/*
void GUI::DieuKien(Snake& rSnake){		//tang dot len khi di chuyen dot dau tien
	this->setMaps();
	this->changeCoord(n, 0, rSnake.getX());
	this->changeCoord(n, 1, rSnake.getY());
	n++;
	if (n == rSnake.getDot()) n = 1;
}
*/
/*
void GUI::XoaDauVet(Snake& rSnake){	//xoa toa do khi di chuyen
	this->GotoXY(rSnake.getMapsValue(rSnake.getN(), 0), rSnake.getMapsValue(n, 1));
	cout << " ";
}
*/

void GUI::CheckColor(){	//in phim bam
	if (dichuyen == 1){
		this->Textcolor(172);
		cout << "D";
		this->GotoXY(35, 3); this->Textcolor(10); cout << "A";
		this->GotoXY(37, 3); this->Textcolor(10); cout << "S";
		this->GotoXY(37, 2); this->Textcolor(10); cout << "W";
	}
	else if (dichuyen == 2){
		this->Textcolor(172);
		cout << "A";
		this->GotoXY(39, 3); this->Textcolor(10); cout << "D";
		this->GotoXY(37, 3); this->Textcolor(10); cout << "S";
		this->GotoXY(37, 2); this->Textcolor(10); cout << "W";
	}
	else if (dichuyen == 3){
		this->Textcolor(172);
		cout << "S";
		this->GotoXY(35, 3); this->Textcolor(10); cout << "A";
		this->GotoXY(39, 3); this->Textcolor(10); cout << "D";
		this->GotoXY(37, 2); this->Textcolor(10); cout << "W";
	}
	else if (dichuyen == 4){
		this->Textcolor(172);
		cout << "W";
		this->GotoXY(35, 3); this->Textcolor(10); cout << "A";
		this->GotoXY(37, 3); this->Textcolor(10); cout << "S";
		this->GotoXY(39, 3); this->Textcolor(10); cout << "D";
	}
}

void GUI::KeyBoard(Snake& rSnake){
	//kbhit bat key cham, khong nen su dung kbhit
	//else if --> fix bug eat me --> khong linh hoat
	if (GetAsyncKeyState(0x44))//D
	{
		if (dichuyen != 2)
			dichuyen = 1;
	}
	else if (GetAsyncKeyState(0x41))//A
	{
		if (dichuyen != 1)
			dichuyen = 2;
	}
	else if (GetAsyncKeyState(0x53))//S
	{
		if (dichuyen != 4)
			dichuyen = 3;
	}
	else if (GetAsyncKeyState(0x57)) //W
	{
		if (dichuyen != 3)
			dichuyen = 4;
	}
	//speed game
	if (GetAsyncKeyState(0x31)) //1
		rSnake.setSpeed(-35);
	if (GetAsyncKeyState(0x32)) //2
		rSnake.setSpeed(-20);
	if (GetAsyncKeyState(0x33)) //3
		rSnake.setSpeed(0);
	if (GetAsyncKeyState(0x34)) //4
		rSnake.setSpeed(50);
	//xu ly di chuyen
	if (dichuyen == 1){
		rSnake.setX(1);
		this->GotoXY(30, 1);
		cout << "                ";
		this->GotoXY(39, 3); this->CheckColor();
	}
	if (dichuyen == 2){
		rSnake.setX(-1);
		this->GotoXY(30, 1);
		cout << "                ";
		this->GotoXY(35, 3); this->CheckColor();
	}
	if (dichuyen == 3){
		rSnake.setY(1);
		this->GotoXY(30, 1);
		cout << "                ";
		this->GotoXY(37, 3); this->CheckColor();
	}
	if (dichuyen == 4){
		rSnake.setY(-1);
		this->GotoXY(30, 1);
		cout << "                ";
		this->GotoXY(37, 2); this->CheckColor();
	}
}


void GUI::XuLy(Snake& rSnake){
	ifstream files;
	if (MessageBox(NULL, (LPCWSTR)L"Press OK to Play Again...", (LPCWSTR)L"YOU DIE", MB_OKCANCEL) == IDOK){
		if (rSnake.getDot() > savedot)
		{
			rSnake.SaveScore();
		}
		this->GotoXY(25, 25);
		this->Textcolor(12);
		cout << "Press Enter...";
		system("snake_oop_v2.exe");
		exit(1);
	}
	else{
		if (rSnake.getDot() > savedot){
			if (MessageBox(NULL, (LPCWSTR)L"High Score!!\nDo you want to save ?", (LPCWSTR)L"Save Scores", MB_YESNO) == IDYES){
				rSnake.SaveScore(); //?
				exit(1);
			}
			else{
				files.close();	//loadscore()
				exit(1);
			}
		}
		else{
			if (MessageBox(NULL, (LPCWSTR)L"Diem cua ban chua phai la cao nhat", (LPCWSTR)L"YOU LOSE", MB_OK) == IDOK){
				files.close();
				exit(1);
			}
		}
	}
}

void GUI::GameOver(Snake& rSnake){		//xu ly thua game
	//xu ly cham bien --> die
	if (rSnake.getX() <= 4 || rSnake.getX() >= 70 || rSnake.getY() <= 4 || rSnake.getY()  >= 30){
		rSnake.setMang(0);
		this->GotoXY(50, 30); this->Textcolor(12);
		
		this->GotoXY(20, 14); this->Textcolor(14);
		cout << "Game Over, ...\n\n\n\n\n\n\n\n\n\n\n\n\n";
		this->XuLy(rSnake);
	}
	//cham vao than snake --> -1 live
	for (int i = 1; i<rSnake.getDot(); i++){
		if (rSnake.getX() == rSnake.getMapsValue(i,0) && rSnake.getY() == rSnake.getMapsValue(i,1)){
			rSnake.addMang(-1);
			if (rSnake.getLive() < 0){
				this->GotoXY(20, 14); this->Textcolor(14);
				cout << "Game Over, ...\n\n\n\n\n\n\n\n\n\n\n\n\n";
				this->XuLy(rSnake);
			}
		}
	}
}

void GUI::MainGame(Snake& rSnake,int color, Snake& rSnake1, int color1)
{
	this->GotoXY(5, 31);
	this->Textcolor(color); //2
	//cout << "Speed, Press:";
	this->GotoXY(28, 31);
	this->Textcolor(10);
	//cout << "[1] [2] [3] [4]";
	this->GotoXY(50, 1); this->Textcolor(2); cout << "Scores Max: ";
	this->GotoXY(62, 1); this->Textcolor(10); cout << rSnake.getHighScore();
	this->GotoXY(1, 3); this->Textcolor(12); cout << char(4);
	this->GotoXY(50, 2); this->Textcolor(12); cout << char(90);
	this->GotoXY(50, 3); this->Textcolor(10); cout << char(169);
	this->GotoXY(5, 32);
	this->Textcolor(10); cout << "10 ";
	this->Textcolor(12); cout << char(4);
	this->Textcolor(10); cout << " +1 ";
	this->Textcolor(2); cout << "Live";

	while (1){
		//Voraussetzung
		rSnake.DieuKien();
		rSnake1.DieuKien();
		// Kontrolle
		rSnake.printSnake();
		rSnake1.printSnake2();
		// Teil der Schlange löschen
		rSnake.XoaDauVet();
		rSnake1.XoaDauVet();
		rSnake.VicTim();
		rSnake1.VicTim();
		//this->KeyBoard(rSnake);
		rSnake.snakeMove();
		rSnake1.snakeMove2();
		GameOver(rSnake);
		GameOver(rSnake1);
		Sleep(50 + rSnake.getSpeed());
		Sleep(50 + rSnake1.getSpeed());
	}
}

void GUI::menu(Snake& rSnake, Snake& rSnake1){
	if (GetAsyncKeyState(VK_SPACE)){
		//this->setFood(10, 15);
		system("cls");
		this->Wall();
		this->GotoXY(s_VTx, s_VTy); this->Textcolor(12);
		cout << char(4);
		rSnake.LoadScore();
		//this->MainGame(rSnake,6); //check = 1;
		this->MainGame(rSnake,4, rSnake1, 10);
	}
}

void GUI::Intro(Snake& rSnake, Snake& rSnake1){
	ifstream files;
	char kytu;
	this->GotoXY(18, 10);
	this->Textcolor(10);
	files.open("intro.txt", ios::out);
	if (files.fail())
	{
		cout << "File not found";
	}
	if (!files.eof()){
		while (!files.eof()){
			kytu = files.get();
			Sleep(10);
			cout << kytu;
			if (kbhit()){
				if (_getch() == VK_RETURN){
					files.close();
					system("cls");
					this->Wall();
					this->GotoXY(s_VTx, s_VTy);
					this->Textcolor(12);
					cout << char(4);
					rSnake.LoadScore();
					this->MainGame(rSnake,2, rSnake1, 10); //check = 1;
				}
			}
		}
	}
	this->Wall();
	files.close();
	//start.txt
	this->GotoXY(25, 25); this->Textcolor(10);
	files.open("start.txt", ios::out);
	if (files.fail()){ cout << "File khong ton tai.."; }
	while (!files.eof()){
		kytu = files.get();
		Sleep(50);
		cout << kytu;
	}
	files.close();
}