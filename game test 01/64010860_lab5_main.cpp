#include<iostream>
#include<windows.h>
#include<conio.h>

void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_ship(int x , int y)
{

	gotoxy(x, y);
	printf(" <-0-> ");
}

void erase_ship(int x, int y)
{
	system("cls");

}


int main()
{
	char ch = ' ';
	int x=38, y=20;
	setcursor(0);
	draw_ship(x,y);
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