#include "Tank.h"
#define WINDOW_WIDTH	932						//为窗口宽度定义的宏，以方便在此处修改窗口宽度
#define WINDOW_HEIGHT	932							//为窗口高度定义的宏，以方便在此处修改窗口高度

bool Tank::Tank_move(int Direction) {
	switch (Direction)
	{
	case 0:
		Tank_Y -= Tank_Speed;
		if (Tank_Y < 0)
			Tank_Y = 0;
		break;
	case 1:
		Tank_X -= Tank_Speed;
		if (Tank_X < 0)
			Tank_X = 0;
	case 2:
		Tank_Y += Tank_Speed;
		if (Tank_Y >= WINDOW_HEIGHT)
			Tank_Y = WINDOW_HEIGHT;
	case 3:
		Tank_X += Tank_Speed;
		if (Tank_X > WINDOW_WIDTH)
			Tank_X = WINDOW_WIDTH;
	default:
		break;
	}
	return 0;
}

bool Tank::Tank_Getcoord(int &X_coord, int &Y_coord) {
	X_coord = Tank_X;
	Y_coord = Tank_Y;
	return 0;
}