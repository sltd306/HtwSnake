#ifndef UTIL_H
#define UTIL_H

#define _WIN32_WINNT 0x500	//using resize console
#include <windows.h>	//resize console
#include <iostream>		//cout, cin
#include <conio.h>		//getch, kbhit
#include <stdlib.h>		//rand
#include <ctime>		//time rand
#include <stdio.h>		//fflush
#include <fstream>		//file
#include <string>		//string
#include <mmsystem.h>
#include <vector>


using namespace std;

class Util
{
public:
	void ResizeConsole(int width, int height);
	void HideCursor();
	void Textcolor(int x);
	void GotoXY(int x, int y);


	static int s_VTx;
	static int s_VTy;

protected:
	int savedot;


private:


};




#endif