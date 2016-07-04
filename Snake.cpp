
#include "Snake.h"

void Snake::Speed(){
	string spe;
	if (m_speed == -35){
		spe = "Max Speed ";
		this->GotoXY(1, 3); this->Textcolor(2); cout << "Speed: ";
		this->GotoXY(8, 3); this->Textcolor(10); cout << spe;
	}
	if (m_speed == -20){
		spe = "Fast     ";
		this->GotoXY(1, 3); this->Textcolor(2); cout << "Speed: ";
		this->GotoXY(8, 3); this->Textcolor(10); cout << spe;
	}
	if (m_speed == 0){
		spe = "Medium";
		this->GotoXY(1, 3); this->Textcolor(2); cout << "Speed: ";
		this->GotoXY(8, 3); this->Textcolor(10); cout << spe;
	}
	if (m_speed == 50){
		spe = "Slow      ";
		this->GotoXY(1, 3); this->Textcolor(2); cout << "Speed: ";
		this->GotoXY(8, 3); this->Textcolor(10); cout << spe;
	}

}

void Snake::VicTim(){
	if (m_x == s_VTx && m_y == s_VTy){	// snake cham vao thuc an
		//tang mang (live) khi an 20 thuc an
		if ((m_dot % 10) == 0){
			m_live += 1;
		}
		PlaySound((LPCWSTR)L"eat.wav", NULL, SND_FILENAME | SND_ASYNC);
		Sleep(0);
		m_dot++;
		s_VTx = rand() % 50 + 5;
		s_VTy = rand() % 20 + 5;
		this->GotoXY(s_VTx, s_VTy);
		this->Textcolor(12);
		cout << char(4);
	}
	//fix bug khi toa do thuc an = toa do cua than snake
	for (int i = 1; i<m_dot; i++){
		if (maps[i][0] == s_VTx && maps[i][1] == s_VTy){
			m_dot += 0;	//khong tang diem
			s_VTx = rand() % 50 + 7;
			s_VTy = rand() % 30 + 6;
			this->GotoXY(s_VTx, s_VTy); this->Textcolor(12);
			cout << char(4);
		}
	}
}

void Snake::printSnake(){	//in dot ra khi di chuyen
	for (int i = 1; i<m_dot; i++){
		//fix bug
		if (maps[i][0] == 0 && maps[i][1] == 0){
			cout << " ";
		}
		else{	//in ra man hinh
			this->GotoXY(maps[i][0], maps[i][1]);
			this->Textcolor(10);
			cout << char(169);
		}
	}
	// in diem ra man hinh
	this->GotoXY(1, 1); this->Textcolor(2); cout << "Scores:   ";
	this->GotoXY(1, 2); this->Textcolor(2); cout << "Live: "; //
	this->GotoXY(9, 1); this->Textcolor(10); cout << m_dot - 2; //
	this->GotoXY(11, 1); this->Textcolor(2); cout <<    " : ";
	this->GotoXY(9, 2); this->Textcolor(10); cout << m_live;//
	this->GotoXY(11, 2); this->Textcolor(2); cout << " : ";
	this->GotoXY(4, 3); this->Textcolor(2); cout << "(" << s_VTx << "," << s_VTy << ") ";
	this->GotoXY(53, 3); this->Textcolor(2); cout << "(" << m_x << "," << m_y << ") ";
	//this->Speed();
}
void Snake::printSnake2(){	//in dot ra khi di chuyen
	for (int i = 1; i<m_dot; i++){
		//fix bug
		if (maps[i][0] == 0 && maps[i][1] == 0){
			cout << " ";
		}
		else{	//in ra man hinh
			this->GotoXY(maps[i][0], maps[i][1]);
			this->Textcolor(15);
			cout << char(90);
		}
	}
	// in diem ra man hinh
	this->GotoXY(15, 1); this->Textcolor(15); cout << m_dot - 2; //
	this->GotoXY(53, 2); this->Textcolor(4); cout << "(" << m_x << "," << m_y << ") ";
	this->GotoXY(15, 2); this->Textcolor(5); cout << m_live;//
}

/*
void Snake::LoadScore()
{
	ifstream files;
	files.open("save.txt", ios::out);
	if (!files)
	{
		cout << "File not found";
	}
	files >> savedot;
}
*/

void Snake::LoadScore()
{
	ifstream files;
	files.open("save.txt");
	if (!files)
	{
		cout << "File not found";
	}
	files >> savedot;
	files.close();
}

void Snake::SaveScore(){	//luu diem vao file
	ofstream files;
	files.open("save.txt", ios::out);
	if (!files)
	{
		cout << "Khong doc duoc file...";
	}
	files << m_dot - 2;
	files.close();
}

void Snake::DieuKien(){		//tang dot len khi di chuyen dot dau tien
	this->setMaps();
	maps[n][0] = m_x;
	maps[n][1] = m_y;
	n++;
	if (n == m_dot) n = 1;
}

void Snake::setMaps()
{
	maps.resize(200);
	for (int i = 0; i < 200; ++i)
	{
		maps[i].resize(200);
	}
}

void Snake::XoaDauVet(){	//xoa toa do khi di chuyen
	this->GotoXY(maps[n][0], maps[n][1]);
	cout << " ";
}

void Snake::snakeMove()
{
	int mx, my;
	mx = s_VTx - m_x;
	my = s_VTy - m_y;

	if (mx > 0)
	{
		if (my >0){

			Snake::setY(1);
			Snake::setX(1);
		}

		if (my <0){


			Snake::setY(-1);
			Snake::setX(1);
		}

		if (my == 0){
			Snake::setX(1);
		}

	}
	else
	{

		if (my >0){
			Snake::setX(1);
			Snake::setY(1);
			Snake::setX(-1);
		}
		if (my <0){
			Snake::setX(1);
			Snake::setY(-1);
			Snake::setX(-1);
		}
		if (my == 0){
			Snake::setX(-1);
		}

	}


}

void Snake::snakeMove2()
{
	int mx, my;
	mx = s_VTx - m_x;
	my = s_VTy - m_y;

	if (mx > 0)
	{
		if (my >0){

			Snake::setY(1);
		}

		if (my <0){
			Snake::setY(-1);

		}

		if (my == 0){
			Snake::setX(1);
		}

	}
	else
	{

		if (my >0){

			Snake::setY(1);

		}
		if (my <0){
			Snake::setY(-1);

		}
		if (my == 0){
			Snake::setX(-1);
		}

	}

}