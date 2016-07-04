#include "GUI.h"

int main()
{
	Snake s1(20,20,5,6,5,1);
	Snake s2(20, 40, 5, 6, 5, 1);
	GUI g;
	SetConsoleTitle((LPCWSTR)L"Game Snaker v2.0");	//title game
	s1.ResizeConsole(700, 600);					//resize cmd
	s1.HideCursor();							//hide mouse control
	srand(time(0));
	g.Intro(s1, s2);
	while (1){
 		g.menu(s1,s2);
	}
	system("pause>null");
	return 0;
}