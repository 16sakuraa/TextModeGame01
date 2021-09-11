#include<stdio.h>
#include<windows.h>
#include<conio.h>

void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}


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

void draw_ship(int x, int y)
{

	gotoxy(x, y);
	setcolor(2, 4);
	printf(" <-0-> ");
}

void erase_ship(int x, int y)
{
	gotoxy(x, y);
	setcolor(0, 0);
	printf("       ");

}

void draw_bullet(int x, int y, int bulletStatus)
{
	int bx[6], by[6];
	bx[bulletStatus] = x;
	by[bulletStatus] = y;
	gotoxy(bx[bulletStatus], by[bulletStatus]);
	printf("^");
}

void clear_bullet(int x, int y, int bulletStatus)
{
	int bx[6], by[6];
	bx[bulletStatus] = x;
	by[bulletStatus] = y;
	gotoxy(bx[bulletStatus], by[bulletStatus]);
	setcolor(1, 0);
	printf(" ");
}


int main()
{
	char ch = ' ';
	int x = 38, y = 20, i = 0;
	int left = 0, right = 0, up = 0, down = 0;
	int bulletx[5], bullety[5];
	int bulletStatus[5];
	for (i = 0; i <= 5; i++)
	{
		bulletStatus[i] = 0;
	}
	setcursor(0);
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();

			if (ch == 'a' && right == 0)
			{
				left = 1;
			}
			if (ch == 'd' && left == 0)
			{
				right = 1;
			}
			if (ch == 's')
			{
				left = 0;
				right = 0;
			}
			if (bulletStatus[0] == 0 && ch == ' ')
			{
				bulletStatus[0] = 1;
				bulletx[0] = x + 3;
				bullety[0] = y - 1;
			}
			else if (bulletStatus[1] == 0 && ch == ' ')
			{
				bulletStatus[1] = 1;
				bulletx[1] = x + 3;
				bullety[1] = y - 1;
			}
			else if (bulletStatus[2] == 0 && ch == ' ')
			{
				bulletStatus[2] = 1;
				bulletx[2] = x + 3;
				bullety[2] = y - 1;
			}
			else if (bulletStatus[3] == 0 && ch == ' ')
			{
				bulletStatus[3] = 1;
				bulletx[3] = x + 3;
				bullety[3] = y - 1;
			}
			else if (bulletStatus[4] == 0 && ch == ' ')
			{
				bulletStatus[4] = 1;
				bulletx[4] = x + 3;
				bullety[4] = y - 1;
			}

			/*	if (ch == 'w' && y > 0)
				{
					erase_ship(x, y);
					draw_ship(x, --y);
				}
				if (ch == 's' && y < 29 )
				{
					erase_ship(x, y);
					draw_ship(x, ++y);
				} */
			fflush(stdin);
		}
		if (left == 1 && x > 0)
		{
			erase_ship(x, y);
			draw_ship(--x, y);
		}

		if (right == 1 && x < 113)
		{
			erase_ship(x, y);
			draw_ship(++x, y);

		}
		if (bulletStatus[0] == 1)
		{
			clear_bullet(bulletx[0], bullety[0], 0);
			if (bullety[0] == 0)
			{
				bulletStatus[0] = 0;
			}
			else
			{
				draw_bullet(bulletx[0], --bullety[0], 0);
			}
		}
		if (bulletStatus[1] == 1)
		{
			clear_bullet(bulletx[1], bullety[1], 1);
			if (bullety[1] == 0)
			{
				bulletStatus[1] = 0;
			}
			else
			{
				draw_bullet(bulletx[1], --bullety[1], 1);
			}
		}
		if (bulletStatus[2] == 1)
		{
			clear_bullet(bulletx[2], bullety[2], 2);
			if (bullety[2] == 0)
			{
				bulletStatus[2] = 0;
			}
			else
			{
				draw_bullet(bulletx[2], --bullety[2], 2);
			}
		}

		if (bulletStatus[3] == 1)
		{
			clear_bullet(bulletx[3], bullety[3], 3);
			if (bullety[3] == 0)
			{
				bulletStatus[3] = 0;
			}
			else
			{
				draw_bullet(bulletx[3], --bullety[3], 3);
			}
		}
		if (bulletStatus[4] == 1)
		{
			clear_bullet(bulletx[4], bullety[4], 4);
			if (bullety[4] == 0)
			{
				bulletStatus[4] = 0;
			}
			else
			{
				draw_bullet(bulletx[4], --bullety[4], 4);
			}
		}

		Sleep(100);
	} while (ch != 'x');
	return 0;
}