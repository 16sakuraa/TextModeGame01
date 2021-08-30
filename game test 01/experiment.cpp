#include<iostream>
#include<windows.h>
#include<conio.h>

int main2()
{
	int sizex = 114;
	int sizey = 29;
	char world[sizex][sizey];
	char player = '<-0->';
	char ch = ' ';
	int x = 38, y = 20;
	setcursor(0);
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a' && x > 0) { draw_ship(--x, y); }
			if (ch == 'd' && x < 114) { draw_ship(++x, y); }
			fflush(stdin);
			if (ch == 'w' && y > 0) { erase_ship(x, y); draw_ship(x, --y); }
			if (ch == 's' && y < 29) { erase_ship(x, y); draw_ship(x, ++y); }

		}

		Sleep(100);
	} while (ch != 'x');
	return 0;
}