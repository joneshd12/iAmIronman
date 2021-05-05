#include <iostream>
#include <cstdlib> //C Standard Lidrary
#include <conio.h>
#include "Snake.h"

#define WIDTH  50
#define HEIGHT  25
using namespace std;

Snake snake({ WIDTH / 2, HEIGHT / 2 }, 1);

void board()
{
	COORD snake_pos = snake.get_pos();
	for (int i = 0; i < HEIGHT; i++)
	{
		cout << "\t\t#";
		for (int j = 0; j < WIDTH - 2; j++)
		{
			if (i == 0 || i == HEIGHT - 1)
				cout << '#';
			else if (i == snake_pos.Y && j == snake_pos.X)
				cout << '0';
			else cout << ' ';
		}
		cout << "#\n";
	}
}

int main()
{
	while (true)
	{
		board();
		if (kbhit())
		{
			switch (getch())
			{
			case 'w': snake.changeDir('u'); break;
			case 'a': snake.changeDir('l'); break;
			case 's': snake.changeDir('d'); break;
			case 'd': snake.changeDir('r'); break;
			}
		}
		snake.move_snake();
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
	}
}