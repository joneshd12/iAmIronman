#ifndef SNAKE_H
#define SNAKE_H
#include <Windows.h>
#endif // !snake.h

class Snake
{
private:
	COORD pos;
	int len;
	int vel;
	char direction;
public:
	Snake(COORD pos, int vel);
	void changeDir(char dir);
	void move_snake();
	COORD get_pos(); 
};

